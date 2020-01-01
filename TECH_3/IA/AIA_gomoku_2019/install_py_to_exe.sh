#!/usr/bin/bash

if [ -z "$(whereis wine)" ]
    then
        echo "Intall wine before please"
        exit 84
fi

wget "https://www.python.org/ftp/python/3.7.5/python-3.7.5-amd64.exe"
mkdir -p "$HOME/.wine/drive_c/python3"
echo "Installing python3 on wine..."
echo "/!\\ SELECT CUSTOM INSTALL"
echo "AND USE PATH '$HOME/.wine/drive_c/python3'"
echo "WHEN IT'S DONE PRESS ANY KEY



"
wine "./python-3.7.5-amd64.exe"
read tmp

echo "installing pyinstaller"
wine "$HOME/.wine/drive_c/python3/python.exe" "$HOME/.wine/drive_c/python3/Scripts/pip3.exe"  "install" "pyinstaller"


echo "done ! you should be able to use create_exe.sh"

