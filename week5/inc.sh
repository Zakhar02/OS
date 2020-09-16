#!/usr/bin/env bash

while ! ln "ex2.txt" "ex2.txt.lock" 2>deb>null
do
    sleep 0.1
done
#Critical Region
i=$(tail -n 1 <ex2.txt)
i=$((i + 1))
echo ${i} >>ex2.txt
rm "ex2.txt.lock"
