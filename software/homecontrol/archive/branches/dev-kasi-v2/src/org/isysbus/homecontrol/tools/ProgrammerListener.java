/**
 *
 */
package org.isysbus.homecontrol.tools;

import java.util.EventListener;

/**
 * @author Antimon
 *
 */
public interface ProgrammerListener extends EventListener {

	void statusUpdated(Object source, ProgressEvent e);

}
