#ifndef TRABAJO_H_
#define TRABAJO_H_

#define OCUPADO 1
#define LIBRE 0

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
    int id;	//pk
    //char marcaBicicleta[25];
    //int rodado;
    int idServicio;
    int idBicicleta;
    eFecha fecha;
    int isEmpty;

}eTrabajo;
void InicializarTrabajos(eTrabajo[],int);
int BuscarLibre(eTrabajo[], int tamT);
int ObtenerIdTrabajo();



#endif /* TRABAJO_H_ */
