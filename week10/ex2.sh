#!/bin/bash
touch ../week01/file.txt
link ../week01/file.txt _ex2.txt
find .. -inum `ls -i _ex2.txt | cut -d ' ' -f 1`
find .. -inum `ls -i _ex2.txt | cut -d ' ' -f 1` -exec rm {} \;
