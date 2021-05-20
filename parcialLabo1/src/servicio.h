#ifndef SERVICIO_H_
#define SERVICIO_H_
#define OCUPADO 1
#define LIBRE 0

typedef struct
{
    int id; //PK
    char descripcion[25];
    int precio;
    int isEmpty;

}eServicio;

void MostrarListadoServicios(eServicio[],int);
void HardcodearServicio(eServicio[],int);


#endif /* SERVICIO_H_ */
