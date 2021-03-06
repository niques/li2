/**
@file estado.c

Definição das funções que convertem strings em estados e vice-versa
*/

#include <stdio.h>
#include "estado.h"

#define MAX_BUFFER		10240


/**
\brief Função que converte um estado numa string
@param e O estado
@returns A string correspondente ao estado e
*/
char *estado2str(ESTADO e) {
	static char buffer[MAX_BUFFER];
	unsigned char *p = (unsigned char *) &e;
	int i;

	buffer[0] = 0;

	for(i = 0; i < sizeof(ESTADO); i++)
		sprintf(buffer, "%s%02x", buffer, p[i]);
	
	return buffer;
}

/**
\brief Função que converte uma string num estado
@param argumentos Uma string contendo os argumentos passados à CGI
@returns O estado correspondente à string dos argumentos
*/
ESTADO str2estado(char *argumentos) {
	ESTADO e;
	unsigned char *p = (unsigned char *) &e;
	int i;

	for(i = 0; i < sizeof(ESTADO); i++, argumentos += 2) {
		int d;
		sscanf(argumentos, "%2x", &d);
		p[i] = (unsigned char) d;
	}
	
	return e;
}

