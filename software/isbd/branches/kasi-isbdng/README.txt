To build the isbd you need to install some boost libraries, openssl and sqlite3.

Sample Install for Ubuntu:

1) Install the Boost Build System and BJam
apt-get install bjam boost-build
2) Install required libraries and headers
apt-get install libboost-dev libboost-program-options-dev libboost-signals-dev libboost-system-dev libboost-thread-dev libssl-dev  libsqlite3-dev liblog4cxx10-dev
3) Check Jamroot:
Starting with ssl version 1.0 the required cryptoparts are no longer in libssl but in libcrypto - select your variant ( default is libcrypto)
If you need libssl: change the line "lib crypto ;" to "lib ssl ;" Note the space before the ";" it is required!

3) Build the source: 
bjam 
or 
bjam release 

The "release" variant will create more efficient code without debugging symbols.

Your binary will be located in bin/<gccvariant>/debug/threading-multi or bin/<gccvariant>/release/threading-multi.

4) Create a folder "/opt/isysbus" and Copy the binary to that folder.
5) Copy the logger.cfg and isbd-ng.conf.sample to the target folder and rename isbd-ng.conf.sample to "isbd-ng.conf".

Adapt the config files to your needs.



 
