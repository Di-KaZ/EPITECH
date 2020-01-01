#!/bin/bash
dir_name="$1"
blih -u moussa.fofana@epitech.eu repository create "$1"
blih -u moussa.fofana@epitech.eu repository setacl "$1" ramassage-tek r
blih -u moussa.fofana@epitech.eu repository getacl "$1"
git clone git@git.epitech.eu:/moussa.fofana@epitech.eu/"$1"

