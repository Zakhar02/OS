#!/usr/bin/env bash

echo 1 > ex2.txt

for (( i = 0; i < 4; ++i )); do
    ./inc.sh
    ./inc.sh&
done
