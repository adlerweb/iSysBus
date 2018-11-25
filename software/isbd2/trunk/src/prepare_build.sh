#!/bin/sh

aclocal && autoheader && automake --foreign -a && autoconf

./configure
# LDFLAGS=-static ./configure

