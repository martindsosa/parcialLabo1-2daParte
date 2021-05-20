#include <string.h>
#include <stdio.h>
#include "trabajo.h"

int TrabajoIdIncremental = 2000;

int BuscarLibre(eTrabajo list[], int tamT)
{
	int retorno = -1;
	int i;

	if (list != NULL && tamT > 0)
	{
		for (i = 0; i < tamT; i++) {
			if (list[i].isEmpty == LIBRE) {
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int ObtenerIdTrabajo() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return TrabajoIdIncremental += 1;
}

void InicializarTrabajos(eTrabajo list[],int tamT){
	int i;
	if (list != NULL && tamT > 0)
	{
		for (i = 0; i < tamT; i++) {
			list[i].isEmpty = LIBRE;
		}
	}
}

