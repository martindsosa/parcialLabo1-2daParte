#include <string.h>
#include <stdio.h>
#include "utn.h"
#include "trabajo-servicio.h"
#define OCUPADO 1
#define LIBRE 0




void ObtenerDescripcionServicio(eServicio listaServicios[],int tamS,int idServicio,char descripcion[])
{
	int i;
	for(i=0;i<tamS;i++)
	{
		if(listaServicios[i].id == idServicio && listaServicios[i].isEmpty == OCUPADO )
		{
			strcpy(descripcion,listaServicios[i].descripcion);
			break;
		}
	}
}

void TotalizarServiciosPrestados(eTrabajo listaTrabajos[],int tamT,eServicio listaServicios[],int tamS)
{
	eTotal listaTotales[tamS];

	InicializarListaTotales(listaTotales,tamS,listaServicios);

	CargarCantidadesTotales(listaTotales,listaServicios,tamS,listaTrabajos,tamT);

	MostrarTotalesPorServicio(listaTotales,listaServicios,tamS);
}

void InicializarListaTotales(eTotal listaTotales[],int tamS, eServicio listaServicios[])
{
    int i;
    for(i=0; i<tamS; i++)
    {
        listaTotales[i].idServicio = listaServicios[i].id;
        listaTotales[i].totalServicio = 0;
    }
}
void CargarCantidadesTotales(eTotal listaTotales[],eServicio listaServicios[],int tamS,eTrabajo listaTrabajos[],int tamT)
{
    int i;
    int j;
    for(i=0; i<tamT; i++)
    {
        for(j=0; j<tamS; j++)
        {

            if(listaTrabajos[i].isEmpty== OCUPADO
            	&& listaServicios[j].isEmpty == OCUPADO
            	&& listaServicios[j].id == listaTrabajos[i].idServicio)
            {
            	listaTotales[j].totalServicio++;
            }
        }
    }
}

void MostrarTotalesPorServicio(eTotal listaTotales[],eServicio listaServicios[],int tamS)
{
	int i;
	int sumTotal=0;
	char descripcion[25];
	int flagTitulos = 0;
	int flagHayServicio = 0;

	for (i=0;i<tamS;i++)
	{
		if(listaTotales[i].totalServicio >0)
		{
			flagHayServicio = 1;
			if(flagTitulos == 0)
			{
				printf("\n++++++++++++++++ TOTALES POR SERVICIO ++++++++++++++++\n");
				printf("NUMERO  \t\t    SERVICIO\t\t\t TOTAL\n");
				flagTitulos = 1;
			}
			ObtenerDescripcionServicio(listaServicios,tamS,listaTotales[i].idServicio,descripcion);
			listaTotales[i].totalServicio = listaTotales[i].totalServicio * listaServicios[i].precio;
			printf("  %d\t   %25s\t\t\t  %d \n",listaTotales[i].idServicio
									,descripcion
						  			,listaTotales[i].totalServicio);
			sumTotal = sumTotal + listaTotales[i].totalServicio;
		}
	}
	if(flagHayServicio == 1)
	{
		printf("+++++++++++++++ SUMA TOTAL DE SERVICIOS PRESTADOS : %d  \n",sumTotal);
	}
	else
	{
		printf("\n+++++++++++++++ NO SE PRESTARON SERVICIOS ++++++++++\n\n");
	}
}
