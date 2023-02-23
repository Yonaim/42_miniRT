
FILE_PATH="../../../config/"
FILE="filename.mk"

rm -f config/$FILE;

# mandatory
cd mandatory/srcs;
# camera files
cd camera;
printf "FILENAME\t\t=\t\t" >> $FILE_PATH$FILE;
ls | grep ".c" | cut -f 1 -d "." | xargs printf "camera/%s\\\\\n\t\t\t\t\t\t" >> $FILE_PATH$FILE;

# material files
cd ../material;
ls | grep ".c" | cut -f 1 -d "." | xargs printf "material/%s\\\\\n\t\t\t\t\t\t">> $FILE_PATH$FILE;

# object files
cd ../object
ls | grep ".c" | cut -f 1 -d "." | xargs printf "object/%s\\\\\n\t\t\t\t\t\t">> $FILE_PATH$FILE;

# parsing files
cd ../parsing
ls | grep ".c" | cut -f 1 -d "." | xargs printf "parsing/%s\\\\\n\t\t\t\t\t\t">> $FILE_PATH$FILE;

# pdf files
cd ../pdf
ls | grep ".c" | cut -f 1 -d "." | xargs printf "pdf/%s\\\\\n\t\t\t\t\t\t">> $FILE_PATH$FILE;

# material files
cd ../ray
ls | grep ".c" | cut -f 1 -d "." | xargs printf "ray/%s\\\\\n\t\t\t\t\t\t">> $FILE_PATH$FILE;

# shading files
cd ../shading
ls | grep ".c" | cut -f 1 -d "." | xargs printf "shading/%s\\\\\n\t\t\t\t\t\t">> $FILE_PATH$FILE;

# utils files
cd ../utils
ls | grep ".c" | cut -f 1 -d "." | xargs printf "utils/%s\\\\\n\t\t\t\t\t\t">> $FILE_PATH$FILE;

# main file
printf "main\n" >> $FILE_PATH$FILE;