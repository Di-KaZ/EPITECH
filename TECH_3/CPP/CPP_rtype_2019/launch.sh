#! /usr/bin/bash

# ask to remove previous build
# read -p "Remove previous build ? [Y/N] " yesorno
# if [ `echo $yesorno | tr a-z A-Z` == "Y" ]
#     then
        echo -e "Removed."
        rm -rf build > /dev/null
        rm -rf r-type_client
        rm -rf r-type_server
        mkdir build > /dev/null
#     else
#         echo -e "Keeped."
# fi

# launch build
cd build && conan install --build=missing .. && cmake .. -G "Unix Makefiles"  && cmake --build .  && make 

if [ -f bin/r-type_server ] && [ -f bin/r-type_client ]
    then
        cp bin/r-type_server ../.
        cp bin/r-type_client ../.

        echo -e "Compilation success !"
    else
        echo -e "Compilation failed..."
fi