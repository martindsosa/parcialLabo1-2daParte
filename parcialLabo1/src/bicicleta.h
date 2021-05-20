#ifndef BICICLETA_H_
#define BICICLETA_H_

typedef struct
{
	int idBicicleta;
	char marcaBicicleta[25];
	int rodado;
	char color[25];
	int isEmpty;

}eBicicleta;

int BuscarLibreBicicleta(eBicicleta[], int);
int ObtenerIdBicicleta();
void HardcodearBicicleta(eBicicleta[], int);
void BuscarMarca(eBicicleta[],int,char*,int);
void ObtenerMarcaBicicleta(eBicicleta[], int, int,char[]);
int ObtenerRodadoBicicleta(eBicicleta[], int, int);



#endif /* BICICLETA_H_ */
