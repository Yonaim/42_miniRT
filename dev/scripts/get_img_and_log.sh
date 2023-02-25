#!/bin/bash

num=0;
FILE_PATH="dev/img/"
FILE=$FILE_PATH"image$num.ppm"
LOG_FILE_PATH="dev/log/"
LOG_FILE=$LOG_FILE_PATH"process$num.log"

while true
do
	if ! [ -f "$FILE" ];
	then
		break;
	else
		num=$(($num + 1));
		echo $FILE;
		FILE=$FILE_PATH"image$num.ppm";
	fi
done

num=0;
while true
do
	if ! [ -f "$LOG_FILE" ];
	then
		break;
	else
		num=$(($num + 1));
		echo $LOG_FILE;
		LOG_FILE=$LOG_FILE_PATH"process$num.log";
	fi
done

make;
./miniRT > $FILE 2> $LOG_FILE;