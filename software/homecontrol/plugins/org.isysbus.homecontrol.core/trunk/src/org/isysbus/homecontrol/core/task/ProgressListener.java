package org.isysbus.homecontrol.core.task;

public interface ProgressListener {
	
	public void setInfo(String text);
	public void setLogInfo(String text);
	public void setProgress(int progress);
	public void setFinished(boolean success);
	
}
