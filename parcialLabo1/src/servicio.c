#include <string.h>
#include <stdio.h>
#include "servicio.h"


void MostrarListadoServicios(eServicio listaServicio[],int tamS)
{
    int i;
    char flagHayServicio;
    printf("++++++++++++++++ Listado de Servicios ++++++++++++++++\n");
    printf(" NUM  \t\t SERVICIO\t\t  PRECIO \n");
    for (i=0;i<tamS;i++)
    {
        if (listaServicio[i].isEmpty == OCUPADO )
        {
            flagHayServicio = 's';
            printf("%3d %20s \t\t  %d \n",listaServicio[i].id
            							,listaServicio[i].descripcion
										,listaServicio[i].precio);
        }

    }
    if (flagHayServicio != 's')
    {
        printf ("\nNo hay Servicios DADOS DE ALTA !!!\n");
    }
    else
    {
        printf("++++++++++++++++   FIN  de Servicios     +++++++++++++\n");
    }

}
void HardcodearServicio(eServicio listaServicio[],int tamS)
{
	int i;
	int id[4]={1,2,3,4};
	char descripcion[4][20]={"Limpieza","Parche","Centrado","Cadena"};
	int precio[4]={250,300,400,350};
	int estado[4]={OCUPADO,OCUPADO,OCUPADO,OCUPADO};
	for(i=0; i<tamS; i++)
	{
		listaServicio[i].id =id[i];
		strcpy(listaServicio[i].descripcion, descripcion[i]);
		listaServicio[i].precio = precio[i];
		listaServicio[i].isEmpty = estado[i];
	}
}


