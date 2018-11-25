/**
 * 
 */
package org.isysbus.tools;

import java.util.EventListener;

/**
 * @author Antimon
 *
 */
public interface CMDListener extends EventListener {
	
	void cmdReceived(Object source, String cmd);
	
}
