#!/usr/bin/env bash

cd ../build
cmake .. -DPYTHON_LIBRARY_DIR="/usr/local/anaconda3/lib/python3.9/site-packages" -DPYTHON_EXECUTABLE="/usr/local/anaconda3/bin/python3.9"
make
make install