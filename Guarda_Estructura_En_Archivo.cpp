#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
/*Guarda una estructura de datos en un archivo
	-Crea una estructura
	-Llena una estrictura
	-Escribe una estructura en un archivo*/
struct registro
{
	int id;
	char nombre[30];
};
//void imprime (struct registro S);
int main (void)
{
	FILE *archivo;
	struct registro registros[10];
	int i=0;
//	memset(registros,0,sizeof(struct registros)*10);
	while(i<10)
	{
		printf("Ingrese el nombre del registro %i: ",i+1);
		fgets(registros[i].nombre,30,stdin);
		registros[i].id=i+1;
		i++;
	}
	archivo=fopen("C:\\Estructuras\\registros.txt","w");
	if(archivo!=NULL)
	{
		//aquí registros no lleva & porque es registros en un tipo estructura
		fwrite(registros,sizeof(struct registro),10,archivo);
		fclose(archivo);
	}
/*	archivo=fopen("C:\\Estructuras\\registros.txt","rb");
	fread(registros,sizeof(struct registro),10,archivo);
	fclose(archivo);
	printf("%s",registros);*/
	
	
/*	archivo=fopen("C:\\Estructuras\\registros.txt","rb");
	fread(registros,sizeof(struct registro),10,archivo);
	for(i=0;i<10;i++)
	{
		imprime(registro[i]);
//		printf("registro :\t%s\n",registro.nombre[i]);
	}
	fclose(archivo);*/
	
	getch();
	
	return 0;
}
void imprime (struct registro S)
{
//	printf("registro %i:\t%s\n",i+1,S.registros);
}
