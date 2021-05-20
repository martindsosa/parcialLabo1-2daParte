#ifndef TRABAJO_SERVICIO_H_
#define TRABAJO_SERVICIO_H_

#include "utn.h"
#include "servicio.h"
#include "trabajo.h"
//#include "bicicleta.h"

typedef struct{
	int idServicio;
	int totalServicio;
}eTotal;


void ObtenerDescripcionServicio(eServicio[],int,int,char[]);


void TotalizarServiciosPrestados(eTrabajo[],int,eServicio[],int);
void InicializarListaTotales(eTotal[],int,eServicio[]);
void CargarCantidadesTotales(eTotal[],eServicio[],int,eTrabajo[],int);
void MostrarTotalesPorServicio(eTotal[],eServicio[],int);

#endif /* TRABAJO_SERVICIO_H_ */
