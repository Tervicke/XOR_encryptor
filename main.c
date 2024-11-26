//xor encryptor - XorCrypt -i input_file.txt -kf keyfile.txt -o output file  
//xor encryptor - XorCrypt -i input_file.txt -k "key" -o output file  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char *input_file; // mandatory
	char *key_file; // 
	int use_key;
	char *key;
	int use_output_file;
	char *output_file;
} Tooloptions;

void error_occured(){
		printf("Error occured please read the help manual again\n");
		exit(1);
}
void print_options(Tooloptions *options){ // testing
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
	if(argc != 5 && argc != 7){
		return 0;
	}
	if(strcmp(argv[1],"-if") != 0 && strcmp(argv[1],"-h") != 0){
		return 0;
	}
	options->input_file = argv[2]; 

	if(strcmp(argv[3],"-k") != 0 && strcmp(argv[3],"-kf") != 0){
		return 0;
	}
	if( strcmp(argv[3],"-kf") == 0){
		options->key_file = argv[4];
		options->use_key = 0;
	}else{
		options->use_key = 1; // make true
		options->key = argv[4];
	}
	if(argc != 7){
		options->use_output_file = 0;
		return 1;
	}
	if(strcmp(argv[5],"-of") != 0){
		return 0;
	}
	options->use_output_file = 1;
	options->output_file = argv[6];
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
