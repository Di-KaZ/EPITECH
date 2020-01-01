#!/bin/bash

cat Day02/passwd |grep "\ $1" | wc -l
