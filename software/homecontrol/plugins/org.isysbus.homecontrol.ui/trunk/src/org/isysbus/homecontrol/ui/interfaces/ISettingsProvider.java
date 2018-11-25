package org.isysbus.homecontrol.ui.interfaces;

import org.eclipse.swt.widgets.Composite;

public interface ISettingsProvider {
	
	public Class getProvider();
	public void createComposite(Composite parent);
	public void load(Object selected_element);
}
