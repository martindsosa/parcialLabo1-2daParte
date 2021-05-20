#include <stdio.h>
#include <stdlib.h>
#include "trabajo-servicio-bicicleta.h"
#include "trabajo-servicio.h"
#include "trabajo-bicicleta.h"
#define TOPETRABAJO 10
#define TOPESERVICIO 4
#define TOPEBICICLETA 10
#define REINTENTOS 2

int menu() {
	eTrabajo listaTrabajos[TOPETRABAJO];
    eServicio listaServicios[TOPESERVICIO];
    eBicicleta listaBicicletas[TOPEBICICLETA];

    int retorno;
    int opcion;
    InicializarTrabajos(listaTrabajos,TOPETRABAJO);
    HardcodearServicio(listaServicios,TOPESERVICIO);
    HarcodearBicicleta(listaBicicletas,TOPEBICICLETA);
    do{
    	printf("\n* Menu de Opciones   *\n");
    	printf("**********************\n");
    	printf("     1. Alta de Trabajo\n");
    	printf("     2. Modificar Trabajo\n");
    	printf("     3. Baja de Trabajo\n");
    	printf("     4. Listado de Trabajos\n");
    	printf("     5. Listado de Servicios\n");
    	printf("     6. Total en pesos x los servicios\n");
    	printf("    10. SALIR\n");
    	printf("Ingrese opcion: ");
    	scanf("%d",&opcion);
    	switch(opcion){
    		case 1:
    			retorno =  CargarTrabajos(listaTrabajos, TOPETRABAJO,listaServicios,TOPESERVICIO,listaBicicletas,TOPEBICICLETA);
    			if(retorno != -1)
				{
    				printf("\nTrabajo dado de alta con exito!!!");
				}
				else
				{
					printf("\nNo hay lugar para un alta de trabajo!!");
				}
    		break;
    		case 2:
    			if(MostrarListadoTrabajos(listaTrabajos,TOPETRABAJO,listaServicios,TOPESERVICIO,listaBicicletas,TOPEBICICLETA) != -1)
				{
					ModificarTrabajo(listaTrabajos,TOPETRABAJO,listaServicios,TOPESERVICIO,listaBicicletas,TOPEBICICLETA);
				}
    		break;
    		case 3:

    			if(MostrarListadoTrabajos(listaTrabajos,TOPETRABAJO,listaServicios,TOPESERVICIO) != -1)
    			{
    				BajaDeTrabajo(listaTrabajos,TOPETRABAJO,listaServicios,TOPESERVICIO,listaBicicletas,TOPEBICICLETA,REINTENTOS);
    			}
    		break;
    		case 4:
    				OrdenarListadoTrabajosAnioMarca(listaTrabajos,TOPETRABAJO,listaBicicletas,TOPEBICICLETA);
    				MostrarListadoTrabajos(listaTrabajos,TOPETRABAJO,listaServicios,TOPESERVICIO);
    		break;
    		case 5:
    			MostrarListadoServicios(listaServicios,TOPESERVICIO);
    		break;
    		case 6:
    			TotalizarServiciosPrestados(listaTrabajos,TOPETRABAJO,listaServicios,TOPESERVICIO);
    		break;
    		case 7:
    			OrdenarListadoTrabajosMarca(listaTrabajos,TOPETRABAJO,listaBicicletas,TOPEBICICLETA);
    			MostrarListadoTrabajos(listaTrabajos,TOPETRABAJO,listaServicios,TOPESERVICIO);
    		break;
    	}
    }while(opcion!=10);
	return opcion;
}


