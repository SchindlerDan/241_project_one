#ifndef _cipherLogic_
#define _cipherLogic_

#include <stdio.h>
#include <stdlib.h>


int encrypt(FILE *in, FILE *out, char** key);
int decrypt(FILE *in, FILE *out, char** key);


#endif


