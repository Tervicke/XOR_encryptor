#include<stdio.h>
#include<stdlib.h>

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
