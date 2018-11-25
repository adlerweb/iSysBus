package org.isysbus.homecontrol.core.expressions;

import org.dom4j.Element;

public interface IExpression {
	
	public boolean parse(Element el, Object source);
	
	public EvaluationResult evaluate();
	
}
