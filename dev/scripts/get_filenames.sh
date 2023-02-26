
FILE_PATH="../../../config/"
FILE="filename.mk"

rm -f config/$FILE;

# mandatory
cd mandatory/srcs;
# camera files
cd camera;
printf "FILENAME\t\t=\t\t" >> $FILE_PATH$FILE;
find *.c | cut -f 1 -d "." | xargs printf "camera/%s\\\\\n\t\t\t\t\t\t" >> $FILE_PATH$FILE;

# material files
cd ../material;
find *.c | cut -f 1 -d "." | xargs printf "material/%s\\\\\n\t\t\t\t\t\t" >> $FILE_PATH$FILE;

# object files
cd ../object
find *.c | cut -f 1 -d "." | xargs printf "object/%s\\\\\n\t\t\t\t\t\t" >> $FILE_PATH$FILE;

# pdf files
cd ../pdf
find *.c | cut -f 1 -d "." | xargs printf "pdf/%s\\\\\n\t\t\t\t\t\t" >> $FILE_PATH$FILE;

# material files
cd ../ray
find *.c | cut -f 1 -d "." | xargs printf "ray/%s\\\\\n\t\t\t\t\t\t" >> $FILE_PATH$FILE;

# shading files
cd ../shading
find *.c | cut -f 1 -d "." | xargs printf "shading/%s\\\\\n\t\t\t\t\t\t">> $FILE_PATH$FILE;

# utils files
cd ../utils
find *.c | cut -f 1 -d "." | xargs printf "utils/%s\\\\\n\t\t\t\t\t\t">> $FILE_PATH$FILE;

# world files
cd ../world
find *.c | cut -f 1 -d "." | xargs printf "world/%s\\\\\n\t\t\t\t\t\t">> $FILE_PATH$FILE;

# texture files
cd ../texture
find *.c | cut -f 1 -d "." | xargs printf "texture/%s\\\\\n\t\t\t\t\t\t">> $FILE_PATH$FILE;

# scene files
cd ../scene
find *.c | cut -f 1 -d "." | xargs printf "scene/%s\\\\\n\t\t\t\t\t\t">> $FILE_PATH$FILE;

# main file
cd ..
FILE_PATH="../../config/"
find *.c | cut -f 1 -d "." | xargs printf "%s\\\\\n\t\t\t\t\t\t">> $FILE_PATH$FILE;
