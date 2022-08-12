#!/bin/sh
gcc testgtk.c -o testgtk `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0`
