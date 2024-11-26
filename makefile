all:
	gcc main.c -o XorCrypt
	./XorCrypt.exe -h -if inputfile -k mykey -of output_file
compile:
	gcc main.c -o XorCrypt
