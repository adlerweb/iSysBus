package org.isysbus.homecontrol.nc.config_page;

import org.isysbus.homecontrol.core.nodes.BusNode;

public class ConfigPagesModelFactory {
	
	public static ConfigPageModel getModelFor(BusNode n) {
		return new ConfigPageModel(n);
	}
	
}
