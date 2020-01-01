#!/bin/bash
commit_message="$1"
git add -A
git commit -am "$1$"
git push
