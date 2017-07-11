#!/bin/bash

EXEC=port_test
SRC_DIR=.

if [ -e  $SRC_DIR/$EXEC ]
then
   echo "Clean execuatble file"
   rm -rf $SRC_DIR/$EXEC
fi

echo "Generated executable file"
gcc -g -o $EXEC port.c

if [ -e $SRC_DIR/$EXEC ]
then
   echo "Success generated $EXEC"
   echo "Please run $EXEC"
else
   echo "Generated $EXEC failed."
fi
