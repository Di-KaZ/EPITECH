#!/usr/bin/bash
path="$HOME/.wine/drive_c/python3"
python_path="$path/python.exe"
pyinstaller_path="$path/Scripts/pyinstaller.exe"
cache_path="$path/$1"
echo "Generating..."
cp $1 $cache_path
wine "$python_path" "$pyinstaller_path" "-F" "$cache_path"
echo "Done !"