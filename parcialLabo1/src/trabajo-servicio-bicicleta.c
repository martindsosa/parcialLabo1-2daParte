#include "trabajo-servicio-bicicleta.h"
#include "utn.h"
#include<stdio.h>
#define OCUPADO 1
#define LIBRE 0

int CargarTrabajos(eTrabajo listaTrabajos[], int tamT,eServicio listaServicios[],int tamS,eBicicleta listaBicicletas[],int tamB)
{

    int indice;
    int retorno = -1;
    char resp= 'n';
    int id;
    indice = BuscarLibre(listaTrabajos, tamT);
    if(indice!=-1)
    {
    	id = ObtenerIdTrabajo();
    	listaTrabajos[indice] = PedirDatosTrabajo(listaServicios,tamS,id,listaBicicletas,tamB);
    	MostrarUnTrabajo(listaTrabajos[indice],listaServicios,tamS,listaBicicletas,tamB);
    	resp = GetSoN("\nDesea realizar el alta? ","Error Reingrese ",'s','n');
    	if (resp == 's')
    	{
    		listaTrabajos[indice].isEmpty = OCUPADO;
    		retorno = 1;
    	}
    	else
    	{
    		retorno = 0;
    	}
    }
    return retorno;
}

void ModificarTrabajo(eTrabajo listaTrabajos[],int tamT,eServicio listaServicios[],int tamS,eBicicleta listaBicicletas[],int tamB)
{
    eTrabajo auxTrabajo;
	int auxId;
    int i;
    int flagEncontro;
    int auxOpcion;
    char respuesta;

    printf("Ingrese el ID Trabajos: ");
    scanf("%d", &auxId);
    do
    {
        for(i=0;i<tamT; i++)
        {
            if(listaTrabajos[i].isEmpty == OCUPADO && auxId == listaTrabajos[i].id)
            {
                flagEncontro = 1;
                auxTrabajo = listaTrabajos[i];
                GetInt(&auxOpcion,"Modifica: 1.Marca 2.Servicio ","Error!!! Reingrese ",1,2,2);
                if(auxOpcion==1)
			   {
                	MostrarListadoBicicletas(listaBicicletas,tamB);
                	GetInt(&auxTrabajo.idBicicleta,"Ingrese idBicicleta: ", "Error! No Valido",20, 25,2);
                	//GetString(auxTrabajo.marcaBicicleta,"Ingrese Marca: ", "Error! Demasiado largo Reingrese: ",25,2);
                	MostrarUnTrabajo(auxTrabajo,listaServicios,tamS,listaBicicletas,tamB);
					respuesta = GetSoN("\nDesea realizar la modificacion? ","Error Reingrese ",'s','n');
					if (respuesta== 's')
					{
						listaTrabajos[i].idBicicleta = auxTrabajo.idBicicleta;
						printf("\nTrabajo MODIFICADO !!!\n");
					}
					else
					{
						printf("\nNo se realizo MODIFICACION...\n");
					}
			   }
			   else
			   {
				   if(auxOpcion == 2)
				   {
					   MostrarListadoServicios(listaServicios,tamS);
					   GetInt(&auxTrabajo.idServicio,"Ingrese idServicio: ","Error!!! Reingrese ",1,4,2);
					   MostrarUnTrabajo(auxTrabajo,listaServicios,tamS,listaBicicletas,tamB);
					   respuesta = GetSoN("\nDesea realizar la modificacion? ","Error Reingrese ",'s','n');
					   if (respuesta== 's')
					   {
						   listaTrabajos[i].idServicio = auxTrabajo.idServicio;
						   printf("\nTrabajo MODIFICADO !!!\n");
					   }
					   else
					   {
						   printf("\nNo se realizo MODIFICACION...\n");
					   }
				   }
			   }
			   break;
            }
        }
        if (flagEncontro!=1)
        {
            MostrarListadoTrabajos(listaTrabajos,tamT,listaServicios,tamS,listaBicicletas,tamB);
            printf("Error ! No se encontro id trabajos.Reingrese: ");
            scanf("%d",&auxId);
        }

    }while(flagEncontro != 1);
}


eTrabajo PedirDatosTrabajo(eServicio listaServicios[],int tamS,int id,eBicicleta listaBicicletas[],int tamB)
{
    eTrabajo miTrabajo;

    miTrabajo.id = id;
    //GetString(miTrabajo.marcaBicicleta,"Ingrese Marca: ", "Error! ",30,2);

	//GetInt(&miTrabajo.rodado,"Ingrese Rodado: ", "Error! Rodado Valido entre 14-30.",14,30,2);
    MostrarListadoBicicletas(listaBicicletas,tamB);
    GetInt(&miTrabajo.idBicicleta,"Ingrese idBicicleta: ", "Error! No Valido",20, 25,2);

	MostrarListadoServicios(listaServicios,tamS);
	GetInt(&miTrabajo.idServicio,"Ingrese numero de servicio: ", "Error! No Valido",1, 4,2);
	miTrabajo.fecha = PedirFecha("\nIngrese Fecha de arreglo ",2);
	if(miTrabajo.fecha.dia == 0){
		printf("\nFECHA INGRESADA INCORRECTA");
	}

	return miTrabajo;
}

/**brief controla fecha correcta
 *@param char mensaje
 *@param int reintentos
* devulve fecha en 0 si es incorrecta sino la fecha correcta
*/
eFecha PedirFecha(char mensaje[],int reintentos)
{
	eFecha miFecha;

	do{
		printf("%s\n",mensaje);
		printf("Ingrese dia: ");
		scanf("%d",&miFecha.dia);
		printf("Ingrese mes: ");
		scanf("%d",&miFecha.mes);
		printf("Ingrese anio: ");
		scanf("%d",&miFecha.anio);
		if ( miFecha.mes >= 1 && miFecha.mes <= 12 ){
			switch ( miFecha.mes ){
				case  1 :
				case  3 :
				case  5 :
				case  7 :
				case  8 :
				case 10 :
				case 12 :
					if ( miFecha.dia >= 1 && miFecha.dia <= 31 ){
						return miFecha;
					}
					else{
						printf("Fecha Erronea ");
						reintentos--;
					}
		 	    break;
				case  4 :
				case  6 :
				case  9 :
				case 11 :
					if ( miFecha.dia >= 1 && miFecha.dia <= 30 ){
						return miFecha;
					}
					else{
						printf("Fecha Erronea ");
						reintentos--;
					}
				break;
				case  2 :
					if((miFecha.anio % 4 == 0 && miFecha.anio % 100 != 0 )|| (miFecha.anio % 400 == 0 )){
						if ( miFecha.dia >= 1 && miFecha.dia <= 29 ){
							return miFecha;
						}
						else{
							printf("Fecha Erronea ");
							reintentos--;
						}
					}
					else{
						if ( miFecha.dia >= 1 && miFecha.dia <= 28 ){
							return miFecha;
						}
						else{
							printf("Fecha Erronea ");
							reintentos--;
						}
					}
				break;
			}
		}
		else{
			printf("Fecha Erronea ");
			reintentos--;
		}
	}while(reintentos>=0);

	miFecha.dia = 00;
	miFecha.mes = 00;
	miFecha.anio = 0000;
	return miFecha;
}


int MostrarListadoTrabajos(eTrabajo listaTrabajos[],int tamT,eServicio listaServicios[],int tamS,eBicicleta listaBicicletas[],int tamB)
{
    int i;
    int flagHayTrabajos = -1;
    int flagTitulos = 0;
    char descripcion[25];

    for (i=0;i<tamT;i++)
    {
        if (listaTrabajos[i].isEmpty == OCUPADO )
        {
            flagHayTrabajos = 0;
            if(flagTitulos == 0)
            {
            	printf("\n++++++++++++++++++++++ Listado de Trabajos ++++++++++++++++++++++++\n");
            	printf(" ID \t\t MARCA DE BICICLETA     RODADO\t\t\tSERVICIO  \t  FECHA\n");
            	flagTitulos = 1;
            }
            ObtenerDescripcionServicio(listaServicios,tamS,listaTrabajos[i].idServicio,descripcion);
            MostrarUnTrabajo(listaTrabajos[i],listaServicios,tamS,listaBicicletas,tamB);

        }
    }
    if (flagHayTrabajos == -1)
    {
        printf ("\nNo hay Trabajos DADOS DE ALTA !!!\n");
    }
    else
    {
        printf("+++++++++++++++++ FIN  DE Listado de Trabajos ++++++++++++++++++++\n");
    }
    return flagHayTrabajos;
}


void MostrarUnTrabajo(eTrabajo unTrabajo,eServicio listaServicios[],int tamS,eBicicleta listaBicicletas[],int tamB)
{
	char descripcion[25];
	char marca[25];
	int rodado;
	ObtenerDescripcionServicio(listaServicios,tamS,unTrabajo.idServicio,descripcion);
	ObtenerMarcaBicicleta(listaBicicletas, tamB,unTrabajo.idBicicleta,marca);
	rodado = ObtenerRodadoBicicleta(listaBicicletas, tamB,unTrabajo.idBicicleta);

	printf("\nID %4d  MARCA: %25s \tRODADO: %d\tSERVICIO: %25s \tFECHA (%2d-%2d-%4d)\n",unTrabajo.id
																						,marca
																						,rodado
																						,descripcion
																						,unTrabajo.fecha.dia
																						,unTrabajo.fecha.mes
																						,unTrabajo.fecha.anio);
}


void BajaDeTrabajo(eTrabajo listaTrabajos[],int tamT,eServicio listaServicios[],int tamS,eBicicleta listaBicicletas[],int tamB,int reintentos)
{
    int auxId;
    int i;
    int encontro;
    char respuesta;

    printf("Ingrese el ID Trabajos: ");
    scanf("%d", &auxId);
    do
    {
        for(i=0;i<tamT; i++)
        {
            if(listaTrabajos[i].isEmpty == OCUPADO && auxId == listaTrabajos[i].id)
            {
                encontro = 1;
                MostrarUnTrabajo(listaTrabajos[i],listaServicios,tamS,listaBicicletas,tamB);
                respuesta = GetSoN("\nDesea realizar la baja? ","Error Reingrese ",'s','n');
                if (respuesta== 's')
                {
                    listaTrabajos[i].isEmpty = LIBRE;
                    printf("\nTrabajo ELIMINADO !!!\n");
                }
                else
                {
                    printf("\nNo se realizo baja...\n");
                }
            }
        }
        if (encontro!=1)
        {
            MostrarListadoTrabajos(listaTrabajos,tamT,listaServicios,tamS,listaBicicletas,tamB);
            reintentos --;
            printf("Error ! No se encontro id trabajos.Reingrese: ");
            scanf("%d",&auxId);
        }

    }while(encontro != 1 && reintentos >=0);
}


