#ifndef _LIBRERIA
#define _LIBRERIA

void presentacion();
void menu();
void cierre();
int ingresarEntero(char* mensaje);
char ingresarChar(char* mensaje);
void ingresarString(char mensaje[],char aux[]);
long int ingresarDocumento(char* mensaje);


#include "libreriaTP2.c"
#endif