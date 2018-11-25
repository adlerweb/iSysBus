package org.isysbus.homecontrol.webclient.exceptions;

public class UserCanceledException extends Exception {

	public UserCanceledException() {
		super();
	}
	
	public UserCanceledException(String message) {
		super(message);
	}
}
