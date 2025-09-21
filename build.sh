#!/usr/bin/env bash

CSRCFOLDER=src
gcc $CSRCFOLDER/*.c -o bin/main $(pkg-config --cflags --libs sdl3)