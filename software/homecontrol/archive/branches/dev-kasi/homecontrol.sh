#!/bin/bash

ls homecontrol*.jar lib/* |sed -e 's/$/:/;s/: /:/g' > lib.cp

CLASSPATH=.:`cat lib.cp`
echo $CLASSPATH |sed -e 's/: /:/g' > lib.cp
CLASSPATH=`cat lib.cp` 

java -classpath "$CLASSPATH" org.isysbus.gui.HomeControl
 
