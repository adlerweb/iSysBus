/**
 *
 */
package org.isysbus.homecontrol.tools;

import java.util.EventListener;

/**
 * @author Antimon
 *
 */
public interface BusDataListener extends EventListener {

	void dataReceived(Object source, BusDataEvent e);

}
