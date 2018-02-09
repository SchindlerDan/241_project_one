#include "cipherLogic.h"


int encrypt(FILE *in, FILE *out, char* key){
	printf("Just entered encryption\n");
	char* lowerKey = key;
	//Used stackoverflow to confirm that argv arguments are null terminated
	char* upperKey;
	int i;
	int exists;
	upperKey = malloc(strlen(key) * sizeof(char));
	printf("Just completed upperKey malloc\n");
	for(i = 0; i < strlen(key); i++){
		printf("Creating uppercase key\n");
		if(key[i] > 64 && key[i] < 91){
			upperKey[i] = (key[i] + 32);
		}else{
			upperKey[i] = (key[i] - 32);
		}
	}
	char* upperAlphabet = malloc(26 * sizeof(char));
	char* lowerAlphabet = malloc(26 * sizeof(char));
	printf("We have just finished making the space for the alphabets\n");	
	//this for loop handles mapping the lowercase cipher onto the alphabet
	int j;
	int n;
	int m;
	//starting the lowercase cipher
	for(n = 0; n < strlen(key); n++){
		lowerAlphabet[n] = key[n];
	//	printf("%c ", lowerAlphabet[n]);
	}
	printf("\n");
	//Completing the lowercase cipheri
	int offset = 0;
	for(j = 0; j < 26; j++){
	//	int exists;
		exists = 0;	
		if(26 <= offset){
			break;
		}
		for(m = 0; m < 27; m++){
			
			if(lowerAlphabet[m] == (90 - (j + offset)) || lowerAlphabet[m] == (122 - (j + offset))){
				exists = 1;
			}
		}
		
		if( 0 == exists){
			lowerAlphabet[j + strlen(key)] = 122 - (j + offset);
		}else{
			printf("%c was found \n", (122 - j));
			offset++;
			j = j - 1;
		}	
		//printf("%c ", lowerAlphabet[j]);
	}
	for(j = 0; j < 26; j++){
		printf("%c", lowerAlphabet[j]);
	}
	printf("\n");
	offset = 0;
	for(n = 0; n < strlen(key); n++){
		upperAlphabet[n] = upperKey[n];

	}
	
	for(j = 0; j < 26; j++){
	//	int exists;
		exists = 0;	
		if(26 <= offset){
			break;
		}
		for(m = 0; m < 27; m++){
			
			if(upperAlphabet[m] == (90 - (j + offset)) || upperAlphabet[m] == (122 - (j + offset))){
				exists = 1;
			}
		}
		
		if( 0 == exists){
			upperAlphabet[j + strlen(key)] = 90 - (j + offset);
		}else{
			printf("%c was found \n", (122 - j));
			offset++;
			j = j - 1;
		}	
	//	printf("%c ", lowerAlphabet[j]);
	}
	printf("\n");
	for(j = 0; j < 26; j++){
		printf("%c ", upperAlphabet[j]);
	}

	while(! feof(in)){
		char ch;
		fscanf(in, "%c", &ch);
		printf("we started with character %c ", ch);
		if(ch > 64 && ch < 91){
			
			ch = upperAlphabet[ch % 65];
		}else if(ch > 96 && ch < 123){
			ch = lowerAlphabet[ch % 97];
		}
		printf(" and turned it into %c\n", ch);
		fprintf(out, "%c", ch);
		
		
	}
	fclose(in);
	fclose(out);
	return 0;



	
	
}


int decrypt(FILE *in, FILE *out, char* key){
char* lowerKey = key;
	//Used stackoverflow to confirm that argv arguments are null terminated
	char* upperKey;
	int i;
	upperKey = malloc(strlen(key) * sizeof(char));
	for(i = 0; i < strlen(key); i++){
		if(key[i] > 64 && key[i] < 91){
			upperKey[i] = (key[i] + 32);
		}else{
			upperKey[i] = (key[i] - 32);
		}
	}
	char* upperAlphabet = malloc(26 * sizeof(char));
	char* lowerAlphabet = malloc(26 * sizeof(char));
	
	//this for loop handles mapping the lowercase cipher onto the alphabet
	int j;
	int n;
	int m;
	int exists;
	//starting the lowercase cipher
	for(n = 0; n < strlen(key); n++){
		lowerAlphabet[n] = key[n];
		printf("%c ", key[n]);
	}
	//Completing the lowercase cipher
	int offset = 0;
	for(j = 0; j < 26; j++){
	//	int exists;
		exists = 0;	
		if(26 <= offset){
			break;
		}
		for(m = 0; m < 27; m++){
			
			if(lowerAlphabet[m] == (90 - (j + offset)) || lowerAlphabet[m] == (122 - (j + offset))){
				exists = 1;
			}
		}
		
		if( 0 == exists){
			lowerAlphabet[j + strlen(key)] = 122 - (j + offset);
		}else{
			printf("%c was found \n", (122 - j));
			offset++;
			j = j - 1;
		}	
	//	printf("%c ", lowerAlphabet[j]);
	}
	for(n = 0; n < strlen(key); n++){
		upperAlphabet[n] = upperKey[n];
		
	}
	//completing the uppercase cipher
	offset = 0;
	for(j = 0; j < 26; j++){
	//	int exists;
		exists = 0;	
		if(26 <= offset){
			break;
		}
		for(m = 0; m < 27; m++){
			
			if(upperAlphabet[m] == (90 - (j + offset)) || upperAlphabet[m] == (122 - (j + offset))){
				exists = 1;
			}
		}
		
		if( 0 == exists){
			upperAlphabet[j + strlen(key)] = 90 - (j + offset);
		}else{
			printf("%c was found \n", (122 - j));
			offset++;
			j = j - 1;
		}	
	//	printf("%c ", lowerAlphabet[j]);
	}
	


	while(! feof(in)){
		char ch;
		fscanf(in, "%c", &ch);
		printf(" We took %c ", ch);
		//if(ch > 64 && ch < 91){
		//	ch = upperAlphabet[ch + 65];
		//}else if(ch > 96 && ch < 123){
		//	ch = lowerAlphabet[ch + 97];
		//}
		//
		for(i = 0; i < 26; i++){
			if(ch == lowerAlphabet[i]){
				ch = i + 97;
			}else if(ch == upperAlphabet[i]){
				ch = i + 65;
			}
		}
		printf(" and deciphered it into %c\n", ch);
		fprintf(out, "%c", ch);
		
		
	}
	fclose(in);
	fclose(out);
	return 0;



	
	
}











