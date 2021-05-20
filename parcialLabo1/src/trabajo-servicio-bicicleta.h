#include "trabajo.h"
#include "servicio.h"
#include "bicicleta.h"

#ifndef TRABAJO_SERVICIO_BICICLETA_H_
#define TRABAJO_SERVICIO_BICICLETA_H_

int CargarTrabajos(eTrabajo[], int,eServicio[],int,eBicicleta[],int);
void ModificarTrabajo(eTrabajo[],int,eServicio[],int,eBicicleta[],int);
eTrabajo PedirDatosTrabajo(eServicio[],int, int,eBicicleta[],int);
eFecha PedirFecha(char[],int);
void BajaDeTrabajo(eTrabajo[],int,eServicio[],int,eBicicleta[],int,int);
void MostrarUnTrabajo(eTrabajo,eServicio[],int,eBicicleta[],int);

#endif /* TRABAJO_SERVICIO_BICICLETA_H_ */
