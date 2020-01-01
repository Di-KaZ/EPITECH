#!/bin/bash

cat students.csv |grep "$1" | wc -l
