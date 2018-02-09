//this is the main method, made by Josh Stewart and Dan Schindler
//Who loves Github? WE DO!
#include <stdio.h>
#include <stdlib.h>
#include "cipherLogic.h"
#include <ctype.h>
#include <string.h>
//add an include for our cipher logic library

int main(int argc, const char** argv){
	FILE *in, *out;
	char* key;
	printf("The number of arguments is %d\n", argc);
	key = argv[1];
	in = fopen(argv[2], "r");
	out = fopen(argv[3], "w");

	char option = 'q';
	
	if(in == NULL || out == NULL){
		printf("File could not be found! Oh No!\n");
		exit(1);
	}
	
	while(option != 'D' || option != 'E' || option != 'e' || option != 'd'){
	printf("Please enter whether you want to encrypt or decrypt a file. E for encrypt, D for decrypt\n");
	scanf("%c", &option);
	printf("You chose option %c\n", option);
	//here's where we would use the encrypt/decrypt methods
	if(option == 'd' || option == 'D'){
		//*in, *out, **key
		printf("decrypting now\n");
		decrypt(in, out, key);		
	}else if(option == 'e' || option == 'E'){
		printf("encrypting now\n");
		encrypt(in, out, key);
	}else{
		printf("Goodbye\n");
		exit(1);
	}
	}
	
	printf("Program has finished running\n");

	



	return 0;
}



