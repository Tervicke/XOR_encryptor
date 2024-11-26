# Xor encryptor/decryptor written in c 
# work in progress...

XorCrypt - XOR Encryption Tool
==============================

Usage
-----

    XorCrypt -e -i <input_file> -k <key> -o <output_file>
    XorCrypt -d -i <input_file> -kf <keyfile> -o <output_file>

Description
-----------

XorCrypt is a simple tool for encrypting and decrypting files using XOR encryption.
It requires a key (provided as a string or a file) and supports both encryption (`-e`)
and decryption (`-d`) modes. Use the same key or keyfile for both encryption and decryption.

Options
-------

    -e               Encrypt the input file.
    -d               Decrypt the input file.
    -i <input_file>  Specify the input file to encrypt or decrypt.
    -k <key>         Provide the encryption/decryption key as a string.
    -kf <keyfile>    Provide the encryption/decryption key as a file.
    -o <output_file> Specify the output file for the encrypted or decrypted data.

Example Usage
-------------

Encrypt using a key string:

    XorCrypt -e -i input_file.txt -k "mysecretkey" -o encrypted_output.txt

Decrypt using a keyfile:

    XorCrypt -d -i encrypted_output.txt -kf keyfile.txt -o decrypted_output.txt

