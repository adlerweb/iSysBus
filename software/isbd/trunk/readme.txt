Installation instructions
-------------------------
* Please download the latest version of the isbd for your system from our website under http://www.isysbus.org


Installation under windows
--------------------------
* You can download precompiled packages, so you don't have to compile them for yourself
* Extract the contents from the zip file to a new directory
* Edit the isbd.conf to match your environment
* Run isbd.exe from the commandline and watch the logs


Installation under linux
------------------------
* Extract the contents of the archive with "tar -xvzf isbdx.y.zz.tar.gz"
* Change into the src directory of the extracted archive ("cd isbd-x.y.zz.tar.gz/src")
* Type "make" to compile the program
* Copy the program binary to /usr/bin ("cp ../bin/linux/isbd /usr/bin")
* Edit the configuration file isbd.conf to match your environment and copy it to /etc ("cp isbd.conf /etc/")
* Start the daemon ("/usr/bin/isbd") and watch the console output and / or the logfile under /var/log/isbd.log


Problems
--------
* Visit the FAQ and the forum on our website (http://www.isysbus.org)


Bugs
----
* If you find bugs in this program, please report them under http://bugs.isysbus.org
