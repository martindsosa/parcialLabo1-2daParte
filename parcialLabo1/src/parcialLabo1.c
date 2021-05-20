/*
 ============================================================================
 Name        : parcialLabo1.c
 Author      : Martin D. Sosa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#define SALIDA 10


int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	opcion = menu();
	if(opcion == SALIDA){
	    printf("\nGracias por usar el sistema !!");
	}
	return EXIT_SUCCESS;
}
