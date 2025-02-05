#!/bin/sh

echo "Hello!"

LD_PRELOAD=./libgmpxx.so:./libgmp.so:./libgivaro.so ./main