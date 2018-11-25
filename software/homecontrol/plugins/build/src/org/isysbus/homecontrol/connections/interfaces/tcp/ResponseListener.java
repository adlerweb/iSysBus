package org.isysbus.homecontrol.connections.interfaces.tcp;

public interface ResponseListener {
	void notifyResponse(byte[] resp);
}
