#
# Makefile for isbd (Linux)
#
BIN		= ../bin/linux/isbd
CC		= /usr/bin/g++
DEBUG		= -ggdb 
CFLAGS	= -Wall #-O4
# required for Mac OS X 
INCLUDES = -I/opt/macports/include -I../../../../../../boost/include/
#INCLUDES = 
LIBS = -L/opt/macports/lib -L../../../../../../boost/lib/
#LDFLAGS	= -llog4cxx -lboost_program_options-mt -lboost_system-mt -lboost_thread-mt
LDFLAGS	= -llog4cxx -lboost_program_options -lboost_system -lboost_thread

# Required object files
OBJ = ../obj/linux/main.o \
		../obj/linux/Settings.o \
		../obj/linux/Connection.o ../obj/linux/server.o \
		../obj/linux/BusDevice.o ../obj/linux/md5.o \
		../obj/linux/tools.o ../obj/linux/frame_tools.o 

# Main target
all: $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) -o $(BIN) $(OBJ) $(LDFLAGS)

../obj/linux/%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $(DEBUG) -c -o $@ $<

clean-server:
	rm -rf ../obj/linux/server.o
# clean target
.PHONY: clean
clean:
	rm -rf $(BIN) $(OBJ)
	
.PHONY: run
run:
	$(BIN)
