#!/bin/bash
#Parameter expansion
file="$HOME/.bashrc"
echo "File path: $file"
echo "Fila name: ${file##*/}"
echo "Directory name: ${file%/*}"



