/**
 *
 */
package org.isysbus.homecontrol.nc.bootloader;

import java.util.logging.Logger;

import org.isysbus.homecontrol.exceptions.ParseErrorException;

/**
 * @author antimon
 *
 */
public class HexRecord {

	private Logger logger = Logger.getLogger("org.isysbus.homecontrol.bootloader");

	public static final int DATA_RECORD = 0x00;
	public static final int EOF_RECORD = 0x01;
	public static final int EXTENDED_SEGMENT_RECORD = 0x02;
	public static final int START_SEGMENT_ADDRESS_RECORD = 0x03;

	private int length = 0;
	private int type = 0;
	private long address = 0;
	private long base_address = 0;
	private String data = new String();


	public HexRecord(String data, long base_addr) throws ParseErrorException {
		parseData(data);
		this.base_address = base_addr;
	}

	public HexRecord parseData(String data) throws ParseErrorException {

		// Test for startbyte ':'
		if (data.charAt(0) != ':') throw new ParseErrorException("No valid start byte detected");

		// Read data length
		this.length = Integer.valueOf(data.substring(1, 3), 16);

		// Address of record
		this.address = Integer.valueOf(data.substring(3, 7), 16);

		// Type of data
		this.type = Integer.valueOf(data.substring(7, 9), 16);

		// Test if data length matches line length
		// 1 byte == 2 chars!
		// overhead = 11 chars (start code, byte count, address, ...)
		if (this.length * 2 + 11 != data.length()) throw new ParseErrorException("Data length doesn't match line length");

		// Test checksum (add all bytes except startbyte), sum has to be 0
		int crc = 0;
		for (int i = 1; i < data.length(); i += 2) {
			crc += Integer.valueOf(data.substring(i, i + 2), 16);
		//	System.out.print(String.format(" %02X", Integer.valueOf(data.substring(i, i + 2), 16)));
		}

		if ((crc & 0xFF) != 0) throw new ParseErrorException("CRC invalid: " + (crc & 0xFF) + " != 0");


		if (this.type == DATA_RECORD) {
			this.data = data.substring(9, this.length * 2 + 11);

		} else if (this.type == EOF_RECORD) {
			return this;

		} else if (this.type == EXTENDED_SEGMENT_RECORD) {
			this.base_address = Long.parseLong(data.substring(9, 13), 16);
		} else if (this.type == START_SEGMENT_ADDRESS_RECORD) {
			// Ignore...
		} else {
			logger.info("Parsing error in hexfile: Unknown record type");
			throw new ParseErrorException("Unknown record type");
		}

		return this;
	}

	public int getLength() {
		return length;
	}

	public int getType() {
		return type;
	}

	public long getAddress() {
		// TODO ERROR: if (this.type != DATA_RECORD)
		return address;
	}

	public long getBaseAddress() {
		return base_address;
	}

	public String getData() {
		return data;
	}



}
