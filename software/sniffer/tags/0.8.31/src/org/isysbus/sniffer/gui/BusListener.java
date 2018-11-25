package org.isysbus.sniffer.gui;

public interface BusListener {
	void packetReceived(Object source, Packet packet);
}
