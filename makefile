all:
	gcc main.c utils.c -o XorCrypt
	./XorCrypt.exe -e -if output_file.txt -kf mykey.txt
compile:
	gcc main.c -o XorCrypt
