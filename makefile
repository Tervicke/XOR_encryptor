all:
	gcc main.c utils.c -o XorCrypt
	./XorCrypt.exe -e -if inputfile -kf mykeyfile -of output_file
compile:
	gcc main.c -o XorCrypt
