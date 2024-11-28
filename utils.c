#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void help_menu() {
    printf("XorCrypt - XOR Encryption Tool\n\n");
    printf("Usage:\n");
    printf("  XorCrypt -e -i <input_file> -k <key> -o <output_file>\n");
    printf("  XorCrypt -d -i <input_file> -kf <keyfile> -o <output_file>\n\n");
    
    printf("Description:\n");
    printf("  XorCrypt is a simple tool for encrypting and decrypting files using XOR encryption.\n");
    printf("  It requires a key (provided as a string or a file) and supports both encryption (-e)\n");
    printf("  and decryption (-d) modes. Use the same key or keyfile for both encryption and decryption.\n\n");

    printf("Options:\n");
    printf("  -e               Encrypt the input file.\n");
    printf("  -d               Decrypt the input file.\n");
    printf("  -i <input_file>  Specify the input file to encrypt or decrypt.\n");
    printf("  -k <key>         Provide the encryption/decryption key as a string.\n");
    printf("  -kf <keyfile>    Provide the encryption/decryption key as a file.\n");
    printf("  -o <output_file> Specify the output file for the encrypted or decrypted data.\n\n");

    printf("Example Usage:\n");
    printf("  Encrypt using a key string:\n");
    printf("    XorCrypt -e -i input_file.txt -k \"mysecretkey\" -o encrypted_output.txt\n\n");
    printf("  Decrypt using a keyfile:\n");
    printf("    XorCrypt -d -i encrypted_output.txt -kf keyfile.txt -o decrypted_output.txt\n\n");
		exit(0);
}
char* get_key_by_file(char* key_file){
	FILE *fptr = fopen(key_file,"r");
	printf("keyfile %s\n",key_file);
	if(fptr == NULL){
		printf("ERROR... Keyfile not found \n");
		exit(1);
	}
	char *key = NULL;
	char ch;
	int index = 0;
	size_t size = 0;
	while((ch = fgetc(fptr)) != EOF){
		if(ch < 32 || ch > 126){
			continue;
		}
		key = (char *)realloc(key, size + 1);
		if(key == NULL){
			printf("Memory allocation failed... while resizing buffer for key\n");
			fclose(fptr);
			exit(1);
		}
		key[index++] = ch;
		size++;
	}
	key = (char *)realloc(key, size + 1);
	key[index] = '\0';
	fclose(fptr);
	return key; 
}
