//this is the main method, made by Josh Stewart and Dan Schindler
//Who loves Github? WE DO!
#include <stdio.h>
#include <stdlib.h>
//add an include for our cipher logic library

int main(int argc, const char** argv){
	FILE *in, *out;
	char* key;

	key = argv[1];
	*in = fopen(argv[2], "r");
	*out = fopen(argv[3], "w");

	char option = 'q';
	
	if(in == NULL || out == NULL){
		printf("File could not be found");
		exit(1);
	}
	
	while(option != 'D' || option != 'E' || option != 'e' || option != 'd'){
	printf("Please enter whether you want to encrypt or decrypt a file. E for encrypt, D for decrypt");
	scanf("%c", option);

	//here's where we would use the encrypt/decrypt methods
	if(option == 'd' || option == 'D'){
		
	}else if(option == 'e' || option == 'E'){
		
	}else{
		printf("You don goofed, try again");

	}
	}
	
	printf("Program has finished running");

	



	return 0;
}



