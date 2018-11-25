GCC_VER=`gcc --version|head -1|sed -e 's/^.* //'`

all:
	./gen_version_info.sh
	bjam 
clean: 
	bjam clean
dist:
	bjam	release
	echo $(GCC_VER)
	tar -cvf isbd.tar.gz src/isbd.conf.sample bin/gcc-$(GCC_VER)/release/threading-multi/isbd-ng

test:
	echo $(GCC_VER)
	./bin/gcc-$(GCC_VER)/debug/threading-multi/parsertest

install:
	sudo cp ./bin/gcc-$(GCC_VER)/debug/threading-multi/isbd-ng /opt/isysbus
