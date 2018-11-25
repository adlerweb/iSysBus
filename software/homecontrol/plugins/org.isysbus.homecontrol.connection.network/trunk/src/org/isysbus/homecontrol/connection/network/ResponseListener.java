package org.isysbus.homecontrol.connection.network;

public interface ResponseListener {
	void notifyResponse(byte[] resp);
}
