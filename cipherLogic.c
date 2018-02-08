#include "cipherLogic.h"


int encrypt(FILE *in, FILE *out, char** key){
	char* lowerKey = *key;
	//Used stackoverflow to confirm that argv arguments are null terminated
	char* upperKey;
	int i;
	upperKey = malloc(strlen(*key) * sizeof(char));
	for(i = 0; i < strlen(*key); i++){
		if(*key[i] > 64 && *key[i] < 91){
			upperKey[i] = (*key[i] + 32);
		}else{
			upperKey[i] = (*key[i] - 32);
		}
	}
	char* upperAlphabet = malloc(26 * sizeof(char));
	char* lowerAlphabet = malloc(26 * sizeof(char));
	
	//this for loop handles mapping the lowercase cipher onto the alphabet
	int j;
	int n;
	int m;
	//starting the lowercase cipher
	for(n = 0; n < strlen(*key); n++){
		lowerAlphabet[n] = *key[n];
		
	}
	//Completing the lowercase cipher
	for(j = 0; j < 26; j++){
		bool exists = false;	
		for(m = 0; m <=j; m++){
			if(lowerAlphabet[m] == (90 - j) || lowerAlphabet[m] == (122 - j)){
				exists = true;
			}
		}
		
		if(!exists){
			lowerAlphabet[j] = 122 - j;
		}	
	}

	//starting the lowercase cipher
	for(n = 0; n < strlen(*key); n++){
		upperAlphabet[n] = upperKey[n];
		
		
	}

	//completing the lowercase cipher
	for(j = 0; j < 26; j++){
		bool exists = false;
		for(m = 0; m <=j; m++){
			if(upperAlphabet[m] == (90 - j) || upperAlphabet[m] == (122 - j)){
				exists = true;
			}
			
			
			
		}
		if(!exists){
			upperAlphabet[j] = 90 - j;
		}
		
		
	}
	


	while(! feof(in)){
		char ch;
		fscanf(in, "%c", &ch);
		if(ch > 64 && ch < 91){
			ch = upperAlphabet[ch % 65];
		}else{
			ch = lowerAlphabet[ch % 97];
		}
		
		fprintf(out, "%c", ch);
		
		
	}
	fclose(in);
	fclose(out);
	return 0;



	
	
}


int decrypt(FILE *in, FILE *out, char** key){


}











