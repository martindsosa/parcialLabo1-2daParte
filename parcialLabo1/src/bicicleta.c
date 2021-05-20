#include <string.h>
#include <stdio.h>
#include "bicicleta.h"
#define OCUPADO 1
#define LIBRE 0

int BicicletaIdIncremental = 25;

int BuscarLibreBicicleta(eBicicleta list[], int tamB)
{
	int retorno = -1;
	int i;

	if (list != NULL && tamB > 0)
	{
		for (i = 0; i < tamB; i++) {
			if (list[i].isEmpty == LIBRE) {
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int ObtenerIdBicicleta() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return BicicletaIdIncremental += 1;
}

void HardcodearBicicleta(eBicicleta listaBicicletas[],int tamB)
{
	int i;
	int id[5]={20,21,22,23,24};
	char marca[5][20]={"aurorita","spl","nueva","infantil","mediana"};
	int rodado[5]={20,21,25,26,30};
	char color[5][15]={"rojo","azul","amarillo","rosa","rojo"};
	int estado[5]={OCUPADO,OCUPADO,OCUPADO,OCUPADO};
	for(i=0; i<tamB; i++)
	{
		listaBicicletas[i].idBicicleta =id[i];
		strcpy(listaBicicletas[i].marcaBicicleta, marca[i]);
		strcpy(listaBicicletas[i].color, color[i]);
		listaBicicletas[i].rodado = rodado[i];
		listaBicicletas[i].isEmpty = estado[i];
	}
}
void MostrarListadoBicicletas(eBicicleta listaBicicletas[],int tamB)
{
    int i;
    char flagHayBicicleta;
    printf("++++++++++++++++ Listado de Bicicletas ++++++++++++++++\n");
    printf(" NUM  \t\t BICICLETA\t COLOR\t RODADO \n");
    for (i=0;i<tamB;i++)
    {
        if (listaBicicletas[i].isEmpty == OCUPADO )
        {
            flagHayBicicleta = 's';
            printf("%3d %20s\t%20s\t  %d \n",listaBicicletas[i].idBicicleta
            								,listaBicicletas[i].marcaBicicleta
											,listaBicicletas[i].color
											,listaBicicletas[i].rodado);
        }

    }
    if (flagHayBicicleta != 's')
    {
        printf ("\nNo hay Bicicletas DADOS DE ALTA !!!\n");
    }
    else
    {
        printf("++++++++++++++++   FIN  de Bicicletas     +++++++++++++\n");
    }
}

void BuscarMarca(eBicicleta listaBicicletas[],int tamB,char* marca,int idBicicleta){
	int i;
	for(i=0;i<tamB;i++){
		if(listaBicicletas[i].idBicicleta == idBicicleta){
			marca = listaBicicletas[i].marcaBicicleta;
		}
	}
}
void ObtenerMarcaBicicleta(eBicicleta listaBicicletas[],int tamB,int idBicicleta,char marca[])
{
	int i;
	for(i=0;i<tamB;i++)
	{
		if(listaBicicletas[i].idBicicleta == idBicicleta && listaBicicletas[i].isEmpty == OCUPADO )
		{
			strcpy(marca,listaBicicletas[i].marcaBicicleta);
			break;
		}
	}
}
int ObtenerRodadoBicicleta(eBicicleta listaBicicletas[],int tamB,int idBicicleta){
	int i;
	int rodado;
	for(i=0;i<tamB;i++)
	{
		if(listaBicicletas[i].idBicicleta == idBicicleta && listaBicicletas[i].isEmpty == OCUPADO )
		{
			rodado = listaBicicletas[i].rodado;

		}
	}
	return rodado;
}

