#!/bin/bash

mcs -out:check check-functionality.c $(find src -name "*.c" -type f)
