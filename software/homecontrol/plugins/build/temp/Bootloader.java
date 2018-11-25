package org.isysbus.homecontrol.nc.bootloader;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;
import java.util.logging.Logger;

import javax.naming.SizeLimitExceededException;
import javax.swing.JOptionPane;

import org.isysbus.homecontrol.connections.Connection;
import org.isysbus.homecontrol.core.settings.Settings;
import org.isysbus.homecontrol.messages.ConfigServiceMessageFactory;
import org.isysbus.homecontrol.messages.Message;
import org.isysbus.homecontrol.messages.MessageAnswer;
import org.isysbus.homecontrol.messages.UnicastMessage;
import org.isysbus.homecontrol.messages.UnicastMessageFactory;
import org.isysbus.homecontrol.nc.exceptions.CommandErrorException;
import org.isysbus.homecontrol.nc.exceptions.InvalidNodeIDException;
import org.isysbus.homecontrol.nc.exceptions.NodeException;
import org.isysbus.homecontrol.nodes.BusNode;
import org.isysbus.homecontrol.tools.ExecutorFactory;
import org.isysbus.homecontrol.tools.Microcontroller;
import org.isysbus.homecontrol.tools.ProgressListener;

/**
 * Class for interacting with node bootloader
 *
 * @author ollee
 */
public class Bootloader {

	// Answers
	public static final char ANSWER_MASK = 0xC0;
	public static final char ANSWER_ACK = 0xC0;
	public static final char ANSWER_NACK = 0x40;
	public static final char ANSWER_NOT_ALLOWED = 0x80;
	public static final char ANSWER_UNDEF = 0x00;


	// Flash Errors
	public static final int ISB_BOOTLOADER_ERROR_TIMEOUT = 1;
	public static final int ISB_BOOTLOADER_ERROR_INTERRUPTED = 2;
	public static final int ISB_BOOTLOADER_ERROR_FLASH_OVERSIZE = 3;
	public static final int ISB_BOOTLOADER_ERROR_GET_PAGESIZE = 4;
	public static final int ISB_BOOTLOADER_ERROR_SET_PAGEADDRESS = 5;
	public static final int ISB_BOOTLOADER_ERROR_WRITE_PAGE = 6;
	public static final int ISB_BOOTLOADER_ERROR_CONVERT_HEX = 7;
	public static final int ISB_BOOTLOADER_ERROR_GET_SERIALID = 8;
	public static final int ISB_BOOTLOADER_ERROR_GET_BOOTLOADERID = 9;
	public static final int ISB_BOOTLOADER_ERROR_GET_HARDWAREID = 10;
	public static final int ISB_BOOTLOADER_ERROR_INIT_NODE = 11;

	public static final int MAX_WRITE_ATTEMPTS = 3;

	//
	private Logger logger = Logger.getLogger("org.isysbus.homecontrol.bootloader");
	private LinkedList<ProgressListener> listeners = new LinkedList<ProgressListener>();
	private BusNode node = null;
	private int timeout = 2000; // in miliseconds
	
	public boolean interrupted = false;
	
	public int debug_crc = 0;
	public int written_bytes = 0;


	// global variables
    Thread bootloaderFlashingThread;
    /*
	private int nodeId;
	private String flashFile;
	private int flashSize;
	private int blockAddress = 0;
	private int blockTail = 0;
	private int flashError = 0;
	private int error = 0;
*/

	public Bootloader(BusNode node) {
		// set nodeId
		this.node = node;
	}

	/**
	 * Send the number of the page to write
	 */
	public void setPage(int page_id) throws TimeoutException, CommandErrorException {

		// TEST
		if (page_id == 0) {
			debug_crc = 0;
			written_bytes = 0;
		}
		
		int attempt = 1;
		while (attempt <= MAX_WRITE_ATTEMPTS) {

			if (this.interrupted) {
				logger.config("Bootloader was interrrupted");
				return;
			}
			
			try {
				Future<Message> msg_addr = ExecutorFactory.getExecutor().submit(new MessageAnswer(ConfigServiceMessageFactory.setPageAddr(node.getNodeID(), page_id)));

				// wait maximal 2 seconds until set page address is ack-ed
				try {
					Message msg = (Message)msg_addr.get(this.timeout, TimeUnit.MILLISECONDS);
					// check for ANSWER_ACK bit set
					if((msg.getRawData().charAt(0) & ANSWER_MASK) == ANSWER_ACK) {
						return;
					} else if((msg.getRawData().charAt(0) & ANSWER_MASK) == ANSWER_NACK) {
						logger.warning("Received ANSWER_NACK while trying to set page");
						throw new CommandErrorException("SetPageAddr not succeeded, got ANSWER_NACK");
					}

				} catch (TimeoutException e) {
					logger.warning("Timeout while setting page");
				} catch (InterruptedException e) {
					logger.warning("The command SetPageAddress has been interrupted");
				} catch (ExecutionException e) {

				}
			} catch (InvalidNodeIDException ex) {
				logger.warning(ex.getMessage());
			}
			attempt++;
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
			}
		}
		// This exception is reached if all attempts didn't succeed
		throw new TimeoutException();
	}


	private void writePageData(FlashPage fp) throws TimeoutException, CommandErrorException {
		//	System.out.println("Schreibe Daten...");

			int node_id;
			try {
				node_id = node.getNodeID();
			} catch (InvalidNodeIDException e1) {
				logger.warning(e1.getMessage());
				return;
			}
			int msg_id = 0; // Number of message
			int msg_size = 7; // Bytes per message
			int bytes_remaining = fp.getSize();
			String data = fp.getData();
			String msg_data = "";
			String debug_data = "";

			while (bytes_remaining > 0 && !interrupted) {

				logger.finest("WritePage: Sende Nachricht " + msg_id + " (ab Byte " + msg_id * msg_size + ")");

				if (bytes_remaining < msg_size) {
					msg_data = data.substring(msg_id * msg_size, msg_id * msg_size + bytes_remaining);
				} else {
					msg_data = data.substring(msg_id * msg_size, (msg_id + 1) * msg_size);
				}

				debug_data = "";
				for (int i = 0; i < msg_data.length(); i++) {
					debug_data += String.format("%02X ", (int)msg_data.charAt(i));
					debug_crc += (int)msg_data.charAt(i);
					written_bytes++;
				}
				logger.finest("WritePage Daten: " + debug_data);

				Future<Message> msg_write_flash = ExecutorFactory.getExecutor().submit(new MessageAnswer(ConfigServiceMessageFactory.writeFlash(node_id, msg_data)));

				Message msg;
				try {
					msg = (Message)msg_write_flash.get(this.timeout, TimeUnit.MILLISECONDS);
					// check for ANSWER_ACK bit set

					// TODO if no ANSWER_ACK is set, try again
					if((msg.getRawData().charAt(0) & ANSWER_MASK) != ANSWER_ACK) {
						logger.warning("ANSWER_NACK received while flashing page");
						throw new CommandErrorException("ANSWER_NACK received while flashing page");
					}
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (ExecutionException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}

				msg_id++;
				bytes_remaining -= msg_size;
			}
		}


	public void programFlash(File hexfile) throws TimeoutException, NodeException {

		int page = 0;
		int pagesize = 0;
		
		interrupted = false;

		/*
		 * Read hex file
		 */
		fireActionChanged("Reading Hex File");
		HexFile hex = null;
		try {
			hex = new HexFile(hexfile, node.getMicrocontroller());
		} catch (FileNotFoundException e2) {
			logger.severe("Hexfile not found: " + e2.getMessage());
			JOptionPane.showMessageDialog(null, "Die angegebene Hex-Datei existiert nicht!", "Datei nicht vorhanden", JOptionPane.ERROR_MESSAGE);
			return;
		}

		/*
		 * Check if the node is in the bootloader mode
		 * Try to set this mode
		 */
		fireProgressChanged(0);
		fireActionChanged("Getting mode");
		
		if (node.readMode(true) != BusNode.MODE_FLASH) {
			logger.info("The node is not in flash mode, trying to set this mode...");
			node.writeMode(BusNode.MODE_FLASH);
			// Wait for the node to reboot
			node.waitForBoot(BusNode.TIMEOUT_REBOOT);
			if (node.readMode(true) != BusNode.MODE_FLASH) {
				logger.warning("The flash mode couldn't be set for node " + node.getNodeID());
				JOptionPane.showMessageDialog(null, "Der Knoten konnte nicht in den Flash-Modus gesetzt werden", "Vorgang abgebrochen", JOptionPane.WARNING_MESSAGE);
				throw new CommandErrorException("Couldn't set flash mode");
			}
		}
		
		/*
		 * Load the actual pagesize for the node
		 */
		fireActionChanged("Reading Page Size");
	//	pagesize = getPageSize();
		Microcontroller microcontroller = node.getMicrocontroller();
		pagesize = microcontroller.getPageSize();
		logger.finer("Pagesize for microcontroller " + microcontroller + ": " + pagesize);
	
		logger.finer("Flashsize: " + hex.getFlashfileSize());

		int attempt = 0;

		for (page = 0; page < hex.getPageCount(pagesize); page++) {
			logger.finer("Writing page " + page + "/" + (hex.getPageCount(pagesize) - 1));
			fireActionChanged("Schreibe Page " + page + "/" + (hex.getPageCount(pagesize) - 1));
			
			setPage(page);

			attempt = 1;
			while (attempt <= MAX_WRITE_ATTEMPTS && !interrupted) {
				try {
					writePageData(hex.getFlashPage(page, pagesize));
					fireProgressChanged((page * 100) / hex.getPageCount(pagesize));
					break;
				} catch (TimeoutException e) {
					setPage(page);
					fireActionChanged("Writing page " + page + "/" + (hex.getPageCount(pagesize) - 1)
							+ "(Attempt " + attempt + "/" + MAX_WRITE_ATTEMPTS + ")");
					logger.warning("Writing page failed, trying again (Attempt " + attempt + "/" + MAX_WRITE_ATTEMPTS + ")");
					attempt++;
					try {
						Thread.sleep(1000);
					} catch (InterruptedException e1) {}
				} catch (SizeLimitExceededException e) {
					logger.warning("Tried to write more data than available in hexfile");
					return;
				}
			}
			if (attempt >= MAX_WRITE_ATTEMPTS) {
				JOptionPane.showMessageDialog(null, "Die maximale Anzahl an Wiederholungen beim Flashen des Knotens wurden erreicht. Breche ab", "Fehler", JOptionPane.WARNING_MESSAGE);
				// TODO throw exception?
				return;
			}
			// Wait until node has written his flash page
			try {
				Thread.sleep(100);
			} catch (InterruptedException e1) {}
		}
	
		logger.config("Live calculated crc (without FF's): " + String.format("%04X", (int)(debug_crc & 0xFFFF)));
		
		int remaining = 16384 - 2048 - written_bytes;
		for (int i = remaining; i > 0; i--) {
			debug_crc += 0xFF;
		}
		
		logger.config("Live total crc: " + String.format("%04X", (int)(debug_crc & 0xFFFF)));
		int crc = hex.getCRC();
		logger.fine("Calculated total CRC: " + String.format("%04X", crc));	

		
		logger.fine("Sending Flash CRC");
		try {
			Future<Message> msg_write_crc = ExecutorFactory.getExecutor().submit(new MessageAnswer(ConfigServiceMessageFactory.setFlashCRC(node.getNodeID(), crc)));
			Message msg = (Message)msg_write_crc.get(BusNode.TIMEOUT_ANSWER, TimeUnit.MILLISECONDS);
			// Check if ACK is received
			if ((msg.getRawData().charAt(0) & ANSWER_MASK) != ANSWER_ACK) {
				throw new CommandErrorException("No ACK was received");
			}
		} catch (ExecutionException ex) {
			logger.warning("Execution Error for Command SetFlashCRC: " + ex.getMessage());
		} catch (InterruptedException ex) {
			logger.warning("Command SetFlashCRC has been interrupted: " + ex.getMessage());
		}
		
		/*
		 * Set normal operating mode
		 */
		fireActionChanged("Setting node into normal operating mode");
		node.writeMode(BusNode.MODE_FIRMWARE_NORMAL);

		/*
		 * Wait until node has booted
		 */
	//	fireActionChanged("Wait until node has rebooted");
		// Wait until eeprom is formatted, etc.
		node.waitForFirmwareStart(BusNode.TIMEOUT_REBOOT * 5);

		
	}

	/*
	public void run() {
		// whole flashing process is handled in this thread
		Message msg;
		Future<Message> msgPageSize;
		Future<Message> msgSetPageAddress;
		Future<Message> msgWriteFlash;
		int pageSize;
		int pageAddress;
		byte[] flash;
		int flashTail = 0;
		StringBuffer flashData = new StringBuffer();
		int blockLength = 0;
		// reset global variables
		flashSize = 0;
		blockAddress = 0;
		blockTail = 0;
		flashError = 0;
		// send read page size command
		msgPageSize = ExecutorFactory.getExecutor().submit(new MessageAnswer(ConfigServiceMessageFactory.getPageSize(nodeId)));
		// wait maximal 2 seconds until answer with page size is available
		try {
			msg = (Message)msgPageSize.get(2, TimeUnit.SECONDS);
			// check for ANSWER_ACK bit set
			if((msg.getRawData().charAt(0) & ANSWER_MASK) == ANSWER_ACK) {
				pageSize = msg.getRawData().charAt(1) + (msg.getRawData().charAt(2) << 16);
			}
			else {
				// get page size failed
				flashError = ISB_BOOTLOADER_ERROR_GET_PAGESIZE;
				// notify observers about error happened
				setChanged();
				notifyObservers();
				// leave thread
				return;
			}
		} catch (InterruptedException e) {
			// interrupted externally
			flashError = ISB_BOOTLOADER_ERROR_INTERRUPTED;
			// notify observers about error happened
			setChanged();
			notifyObservers();
			// leave thread
			return;
		} catch (ExecutionException e) {
			//?
			//TODO
			// leave thread
			return;
		}
		catch (TimeoutException e) {
			// Timeout while reading page size
			flashError = ISB_BOOTLOADER_ERROR_TIMEOUT;
			// notify observers about error happened
			setChanged();
			notifyObservers();
			// leave thread
			return;
		}
		// convert hex file to byte array
		try {
			File f = new File(flashFile);
			if (!f.exists()) System.out.println("Fehler: Datei " + f.getAbsolutePath() + " existiert nicht!");
			flash = IntelHexFormat.intelHexFormatToByteArray(f , pageSize);
		} catch (Exception e) {
			// Timeout while converting hex file
			flashError = ISB_BOOTLOADER_ERROR_CONVERT_HEX;
			// notify observers about error happened
			setChanged();
			notifyObservers();
			// leave thread
			return;
		}

		// count size of flash
		flashSize = 0;
		for ( int i = 0; i < flash.length; ) {
			blockLength = (flash[i++]&0xFF) * 256 * 256 + (flash[i++]&0xFF) * 256 + (flash[i++]&0xFF);
			blockAddress = (flash[i++]&0xFF) * 256 * 256 + (flash[i++]&0xFF) * 256 + (flash[i++]&0xFF);
			i += blockLength;
			flashSize += blockLength;
		}
		blockLength = 0;
		blockAddress = 0;
		flashTail = 0;

		// send flash, page per page
		while(flashSize > blockAddress + blockLength) {
			// read block header
			blockLength = (flash[flashTail++]&0xFF) * 256 * 256 + (flash[flashTail++]&0xFF) * 256 + (flash[flashTail++]&0xFF);
			blockAddress = (flash[flashTail++]&0xFF) * 256 * 256 + (flash[flashTail++]&0xFF) * 256 + (flash[flashTail++]&0xFF);
			pageAddress = blockAddress / pageSize;
			// send set page address command
			msgSetPageAddress = ExecutorFactory.getExecutor().submit(new MessageAnswer(ConfigServiceMessageFactory.setPageAddr(nodeId, pageAddress)));
			// wait maximal 2 seconds until set page address is ack-ed
			try {
				msg = (Message)msgSetPageAddress.get(2, TimeUnit.SECONDS);
				// check for ANSWER_ACK bit set
				if((msg.getRawData().charAt(0) & ANSWER_MASK) == ANSWER_ACK) {
					// set page address succeeded
				}
				// check for ANSWER_NACK bit set
				else if((msg.getRawData().charAt(0) & ANSWER_MASK) == ANSWER_NACK) {
					// address out of range
					flashError = ISB_BOOTLOADER_ERROR_FLASH_OVERSIZE;
					// notify observers about error happened
					setChanged();
					notifyObservers();
					// leave thread
					return;
				}
				else {
					flashError = ISB_BOOTLOADER_ERROR_SET_PAGEADDRESS;
					// notify observers about error happened
					setChanged();
					notifyObservers();
					// leave thread
					return;
				}
			} catch (InterruptedException e) {
				// interrupted externally
				flashError = ISB_BOOTLOADER_ERROR_INTERRUPTED;
				// notify observers about error happened
				setChanged();
				notifyObservers();
				// leave thread
				return;
			} catch (ExecutionException e) {
				//?
				//TODO
				// leave thread
				return;
			}
			catch (TimeoutException e) {
				// Timeout while reading set page address ack
				flashError = ISB_BOOTLOADER_ERROR_TIMEOUT;
				// notify observers about error happened
				setChanged();
				notifyObservers();
				// leave thread
				return;
			}
			// send page
			while(blockTail < blockLength) {
				// void flashData string
				flashData.delete(0, flashData.length());
				// build flash data string
				for ( int j = 1; ( j < 8) && ( blockTail < blockLength); j++) {
					flashData.append( ( char)(flash[flashTail++]&0xFF));
					blockTail++;
				}
				// send write flash command
				msgWriteFlash = ExecutorFactory.getExecutor().submit(new MessageAnswer(ConfigServiceMessageFactory.writeFlash(nodeId, flashData.toString())));
//				if(blockTail < blockLength) {
//					// from this messages no answer expected
//					Connection.getInstance().sendMessage(ConfigServiceMessageFactory.writeFlash(nodeId, flashData.toString()));
//				}
//				else {
//					// expect answer only from last write flash message
//					break;
//				}
//				try {
//					Thread.sleep(50);
//				} catch(InterruptedException ex) {
//					// set interrupt flag again, to cause next catch to recognize it
//					// don't leave thread here, let it finish the page
//					bootloaderFlashingThread.interrupt();
//				}
//				// only last write flash message is ack-ed when node finished writing page
//				msgWriteFlash = ExecutorFactory.getExecutor().submit(new MessageAnswer(ConfigServiceMessageFactory.writeFlash(nodeId, flashData.toString())));
				// wait maximal 2 seconds until page is ack-ed
				try {
					msg = (Message)msgWriteFlash.get(5, TimeUnit.SECONDS);
					// check for ANSWER_ACK bit set
					if((msg.getRawData().charAt(0) & ANSWER_MASK) == ANSWER_ACK) {
						// page write succeeded
						// notify observers about changed progress
						setChanged();
						notifyObservers();
//						// zero blockTail
//						blockTail = 0;
					}
					else {
						// page write failed
						flashError = ISB_BOOTLOADER_ERROR_WRITE_PAGE;
						// notify observers about error happened
						setChanged();
						notifyObservers();
						// leave thread
						return;
					}
				} catch (InterruptedException e) {
					// interrupted externally
					flashError = ISB_BOOTLOADER_ERROR_INTERRUPTED;
					// notify observers about error happened
					setChanged();
					notifyObservers();
					// leave thread
					return;
				} catch (ExecutionException e) {
					//?
					//TODO
					// leave thread
					return;
				}
				catch (TimeoutException e) {
					// timeout while writing page
					flashError = ISB_BOOTLOADER_ERROR_TIMEOUT;
					// notify observers about error happened
					setChanged();
					notifyObservers();
					// leave thread
					return;
				}
//				// notify observers about changed progress
//				setChanged();
//				notifyObservers();
				if(blockTail == blockLength) {
					// zero blockTail
					blockTail = 0;
					break;
				}
			}
		}
		return;
	}
	*/

	private void fireActionChanged(String action) {
		for (ProgressListener l : listeners) {
			l.setInfo(action);
		}
	}

	private void fireProgressChanged(int progress) {
		for (ProgressListener l : listeners) {
			l.setProgress(progress);
		}
	}

	public void addProgessListener(ProgressListener l) {
		listeners.add(l);
	}

	public void removeProgessListener(ProgressListener l) {
		listeners.remove(l);
	}
	
	public void interrupt() {
		this.interrupted = true;
	}
}
