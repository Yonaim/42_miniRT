#!/bin/sh

FILE_PATH="config/"
FILE="filename.mk"
DIR_PATH="mandatory/srcs/"
DIRECTORIES="camera,\
			material, \
			object, \
			dynamic_array, \
			object_array, \
			parsing, \
			pdf, \
			ray, \
			scene, \
			texture, \
			utils"

rm -f "${FILE_PATH}${FILE}"

printf "FILENAME\t\t=\t\t" >> $FILE_PATH$FILE;

for dir in $(echo "${DIRECTORIES}" | tr ',' ' '); do
    find "${DIR_PATH}${dir}" -name '*.c' | xargs -I{} basename {} .c | \
	xargs printf "${dir}/%s\\\\\n\t\t\t\t\t\t"  >> "${FILE_PATH}${FILE}"
done

printf "main\n\n" >> "${FILE_PATH}${FILE}"
