all:
	gcc main.c utils.c -o XorCrypt
	./XorCrypt.exe -e -if inputfile -kf mykey.txt -of output_file
compile:
	gcc main.c -o XorCrypt
