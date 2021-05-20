#include "trabajo-bicicleta.h"
#include<stdio.h>

int OrdenarListadoTrabajosAnioMarca(eTrabajo listaTrabajos[],int tamT,eBicicleta listaBicicletas[],int tamB)
{
	int retorno = -1;
	int i;
	int j;
	char auxMarcaI[25];
	char auxMarcaJ[25];
	eTrabajo auxTrabajo;

	for(i=0; i< tamT-1; i++)
	{
		for(j=i+1; j<tamT; j++)
		{
			BuscarMarca(listaBicicletas,tamB,auxMarcaI,listaTrabajos[i].idBicicleta);
			BuscarMarca(listaBicicletas,tamB,auxMarcaJ,listaTrabajos[j].idBicicleta);
			if(listaTrabajos[i].fecha.anio > listaTrabajos[j].fecha.anio ||
				((listaTrabajos[i].fecha.anio == listaTrabajos[j].fecha.anio)&&
				(strcmp(auxMarcaI,auxMarcaJ)>0)))
			{
				auxTrabajo = listaTrabajos[i];
				listaTrabajos[i] = listaTrabajos[j];
				listaTrabajos[j] = auxTrabajo;
			}
		}
	}
	return retorno;
}

int OrdenarListadoTrabajosMarca(eTrabajo listaTrabajos[],int tamT,eBicicleta listaBicicletas[],int tamB)
{
	int retorno = -1;
	int i;
	int j;
	char auxMarcaI[25];
	char auxMarcaJ[25];
	eTrabajo auxTrabajo;

	for(i=0; i< tamT-1; i++)
	{
		for(j=i+1; j<tamT; j++)
		{
			BuscarMarca(listaBicicletas,tamB,&auxMarcaI,listaTrabajos[i].idBicicleta);
			BuscarMarca(listaBicicletas,tamB,&auxMarcaJ,listaTrabajos[j].idBicicleta);
			if(strcmp(auxMarcaI,auxMarcaJ)>0)
			{
				auxTrabajo = listaTrabajos[i];
				listaTrabajos[i] = listaTrabajos[j];
				listaTrabajos[j] = auxTrabajo;
			}
		}
	}
	return retorno;
}

