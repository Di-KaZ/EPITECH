#! /usr/bin/bash
RED='\033[0;31m'
NC='\033[0m'
GREEN='\033[0;32m'

# ask to remove previous build
read -p "Remove previous build ? [Y/N] " yesorno
if [ `echo $yesorno | tr a-z A-Z` == "Y" ]
    then
        echo -e "Removed."
        rm -rf build > /dev/null
        rm -rf babel_client
        rm -rf babel_server
        mkdir build > /dev/null
    else
        echo -e "Keeped."
fi

# launch build
cd build && conan install --build missing .. && cmake .. -G "Unix Makefiles"  && cmake -–build .  && make 

if [ -f bin/babel_server ] && [ -f bin/babel_client ]
    then
        cp bin/babel_server ../.
        cp bin/babel_client ../.
        echo -e "${GREEN}Compilation sucess !${NC}"
    else
        echo -e "${RED}Compilation failed...${NC}"
fi