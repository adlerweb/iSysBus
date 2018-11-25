#!/bin/bash

TMPFILE=/tmp/svn.txt

svn info > $TMPFILE

REVISION=`svnversion`
LAST_CHANGE=`grep 'Last Changed Date' $TMPFILE |sed -e 's/^.*Date: //'`

echo "#define VERSION \"1.0\"" > src/revision.h
echo "#define REVISION \"$REVISION\"" >> src/revision.h
echo "#define LAST_CHANGE \"$LAST_CHANGE\"" >> src/revision.h
