#!/usr/bin/env bash

./maker.sh
sleep 3
cd ./tests/

./maker.sh
sleep 3
./exec.sh 