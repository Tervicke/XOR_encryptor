//xor encryptor - XorCrypt -d -i input_file.txt -kf keyfile.txt -o output file  
//xor encryptor - XorCrypt -e -i input_file.txt -k "key" -o output file  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char *input_file; // mandatory
	char *key_file; // 
	int use_key;
	char *key;
	int use_output_file;
	int operation; // 1 for encrypt 2 for decrypt
	char *output_file;
} Tooloptions;

void error_occured(){
		printf("Error occured please read the help manual again\n");
		exit(1);
}

void print_options(Tooloptions *options){ 
	printf("operation = %d\n",options->operation);
	printf("input file = %s\n",options->input_file);
	if(options->use_key == 1){
		printf("key = %s\n",options->key);
	}else{
		printf("key file = %s\n",options->key_file);
	}
	if(options->use_output_file){
		printf("output file = %s\n",options->output_file);
	}
}

int parse_arguments(int argc , char *argv[] , Tooloptions* options){
	if(argc != 6 && argc != 8){
		return 0;
	}
	if(strcmp(argv[1],"-decrypt") == 0 || strcmp(argv[1],"-d") == 0){
		options->operation = 2;
	}else if(strcmp(argv[1] , "-encrypt") == 0 || strcmp(argv[1],"-e") == 0){
		options->operation = 1;
	}else{
		return 0;
	}

	if(strcmp(argv[2],"-if") != 0 && strcmp(argv[2],"-h") != 0){
		return 0;
	}
	options->input_file = argv[3]; 

	if(strcmp(argv[4],"-k") != 0 && strcmp(argv[4],"-kf") != 0){
		return 0;
	}
	if( strcmp(argv[4],"-kf") == 0){
		options->key_file = argv[4];
		options->use_key = 0;
	}else{
		options->use_key = 1; // make true
		options->key = argv[5];
	}
	if(argc != 8){
		options->use_output_file = 0;
		return 1;
	}
	if(strcmp(argv[6],"-of") != 0){
		return 0;
	}
	options->use_output_file = 1;
	options->output_file = argv[7];
	return 1;
}
int main(int argc , char *argv[]){
	Tooloptions options;
	if ( parse_arguments(argc , argv , &options) != 1) {
		error_occured();
	}
	print_options(&options);
	return 0;
}
