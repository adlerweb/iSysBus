/**
 *
 */
package org.isysbus.homecontrol.nc.bootloader;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;
import java.util.logging.Logger;

import javax.naming.SizeLimitExceededException;

import org.isysbus.homecontrol.core.misc.Code;
import org.isysbus.homecontrol.core.sync.Sync;
import org.isysbus.homecontrol.exceptions.ParseErrorException;
import org.isysbus.homecontrol.tools.Microcontroller;

/**
 * @author antimon
 *
 */
public class HexFile {

	private Logger logger = Logger.getLogger("org.isysbus.homecontrol.bootloader");
	private LinkedList<HexRecord> records = new LinkedList<HexRecord>();
	private Microcontroller microcontroller;
	
	public HexFile(File hexfile) throws FileNotFoundException {
		parseFile(hexfile);
	}
	
	public HexFile(File hexfile, Microcontroller controller) throws FileNotFoundException {
		this.microcontroller = controller;
		parseFile(hexfile);
	}

	/**
	 * The controller can be set optionally
	 * If it is set, the address of the flash memory is compared to the controller's flash size
	 * and if the size is exceeded, a warning is sent to log and the data isn't appended
	 * This means that eeprom data can be inside the hex file, but it is ignored
	 * @param controller
	 */
	public void setMicrocontroller(Microcontroller controller) {
		this.microcontroller = controller;
	}

	public void parseFile(File hexfile) throws FileNotFoundException {

		BufferedReader in = new BufferedReader(new FileReader(hexfile));
		try {
			String line;
			long base_addr = 0;
			while ((line = in.readLine()) != null) {
				//String line = in.readLine();
				HexRecord hr = new HexRecord(line, base_addr);
				
				if (hr.getType() == HexRecord.DATA_RECORD) {

					if (microcontroller == null) {
						records.add(hr);
					} else {
						if (microcontroller.getSizeOfFlash() > (hr.getAddress() + hr.getLength())) records.add(hr);
						else { 
							logger.warning("The size of the flash data exceeds the capacity of the controller flash - additional data is ignored");
							break;
						}
					}

				} else if (hr.getType() == HexRecord.EXTENDED_SEGMENT_RECORD) {
					// If an Extended Segment Address Record is received, set new base address
					base_addr = hr.getBaseAddress();
				} else if (hr.getType() == HexRecord.EOF_RECORD) {
					//System.out.println("Parsing ready");
				}
			}
			in.close();

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ParseErrorException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	public FlashPage getFlashPage(int page_id, int pagesize) throws SizeLimitExceededException {
		long start_address = page_id * pagesize; // Start address of page
		long end_address = start_address + pagesize - 1; // End address of page
		long record_start_address = 0; // Start address of hexfile record (=line in hexfile)
		long record_end_address = 0; // End address of hexfile record
		int offset_start = 0; // Offset, if the page address begins in the middle of a record
		int offset_end = 0; // Offset (counting backwards from the record length) if the end address of the record != end address of the page
		int record_length = 0; // Count of data bytes in the record
		int fill_bytes = 0; // If there is not enough data in the hexfile to fill the page, fill up with <fill_bytes> bytes of 0xFF
		String data = new String(); // data to write into the page
		String record_data = new String(); // data of the record
		String debug_data = new String(); // Data for debugging purposes (->log)

		FlashPage fp = new FlashPage(pagesize);

		// If someone tries to read a page beyond the end of the flashsize, throw exception
		if (start_address > (getFlashfileSize() - 1)) throw new SizeLimitExceededException("Start address of page is greater than flash size");

		// If the end of the page is behind the last address of the flash, fill up with <fill_bytes> bytes
		if (end_address > (getFlashfileSize() - 1)) {
			fill_bytes = (int)(end_address - getFlashfileSize() + 1);
			end_address = getFlashfileSize() - 1;
		}

		// Look through the records and find those with matching addresses
		for (int i = 0; i < records.size(); i++) {
			data = "";
			debug_data = "";
			record_length = records.get(i).getLength();
			record_data = records.get(i).getData();
			offset_start = 0;
			offset_end = 0;
			record_start_address = records.get(i).getAddress();
			record_end_address = records.get(i).getAddress() + record_length - 1;

			// Multiply with 2, because 1 byte = 2 chars in hex file!
			if (start_address > record_start_address) offset_start = 2 * (int)(start_address - record_start_address);
			if (record_end_address > end_address) offset_end = 2 * (int)(record_end_address - end_address);

			int val = 0;
			for (int k = offset_start; k < record_length * 2 - offset_end; k += 2) {
				val = (int)Integer.valueOf(record_data.substring(k, k + 2), 16);
				data += (char)val;
				debug_data += String.format(" %02X", (int)val);
			}
			if (((record_length * 2 - offset_end) - offset_start) > 0) logger.finest("Read hexfile data (" + ((record_length * 2 - offset_end) - offset_start) + " Bytes): " + debug_data);

			// All needed data have been read, so quit here
			if (end_address < record_start_address) {
				logger.finer("Finished reading hexfile, record start address: " + record_start_address + ", end address: " + end_address);
				break;
			}

			try {
				fp.appendData(data);
			} catch (SizeLimitExceededException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		if (fill_bytes > 0) {
			data = "";
			debug_data = "Fill up with " + fill_bytes + " Bytes:";
			for (int i = 0; i < fill_bytes; i++) {
				data += (char)0xFF;
				debug_data += " 0xFF";
			}
			try {
				fp.appendData(data);
				logger.finest(debug_data);
			} catch (SizeLimitExceededException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return fp;
	}

	/**
	 * The number of bytes of the flash in the file
	 * @return
	 */
	public int getFlashfileSize() {
		int size = 0;
		for (HexRecord hr : records) {
			if (hr.getType() == HexRecord.DATA_RECORD) {
				size += hr.getLength();
			}
		}
		return size;
	}

	/**
	 * Calculate the number of pages depending on the current pagesize
	 * @param pagesize
	 * @return
	 */
	public int getPageCount(int pagesize) {
		if (pagesize <= 0) return 0;
		return (int)Math.ceil((double)getFlashfileSize() / (double)pagesize);
	}
	
	/**
	 * Calculate CRC for flash
	 */
	public int getCRC() {
		int crc = 0;
		int remaining = microcontroller.getSizeOfFlash() - microcontroller.getSizeOfBootloader();

		logger.info("Calculating flashfile CRC");
		for (int i = 0; i < getPageCount(128); i++) {
			try {
				FlashPage fp = getFlashPage(i, 128);
				String data = fp.getData();
				for (int k = 0; k < data.length(); k++) {
					crc += data.charAt(k);
					remaining--;
				}
			} catch (SizeLimitExceededException e) {
				break;
			}
		}

		for (int i = remaining; i > 0; i--) {
			crc += 0xFF;
		}
		return (crc & 0xFFFF);
	}
}
 