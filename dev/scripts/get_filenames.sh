#!/bin/sh

FILE_PATH="config/"
FILE="filename.mk"
DIR_PATH="mandatory/srcs/"


rm -f "${FILE_PATH}${FILE}"
printf "FILENAME\t\t=\t\t" >> $FILE_PATH$FILE;
find mandatory/srcs -name "*.c" | cut -f 1 -d "." | sed 's/mandatory\/srcs\///g' | \
xargs printf "%s\\\\\n\t\t\t\t\t\t" >> $FILE_PATH$FILE;

