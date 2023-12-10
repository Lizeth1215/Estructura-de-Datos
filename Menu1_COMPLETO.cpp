/*Menu de archivos
1.- Guardar en nuevo archivo
2.- Leer de archivo
3.- Agregar a archivo existente
4.- Salir*/
#include<stdio.h>	
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<math.h>
#include<time.h>
/*En este programa funcionan todos los casos, pero en el caso agregar despues de se agrega el nuevo nombre y la edad en la posicion que se pidio,
pero se guarda en el archivo temporal*/
struct nombres{
	char N[80];
	int e;
};
FILE *AbrirArchivo (char N[80], char M[5]);
void CopyF (FILE *fp, FILE *fq);
struct nombres Teclado (void);
//-----Funciones-----
int main (void)
{
	int i,n,t,c,c2,c3;
	float p,r;
	char N[80],D[80],T[80],R[80];
	struct nombres H;
	int e;
	FILE *fp,*fq;
	do
	{
		system("cls");
		printf("1.- Guardar en Nuevo Archivo");
		printf("\n2.- Leer _ archivo");
		printf("\n3.- Agregar al final del archivo");
		printf("\n4.- Agregar despues de___");	
		printf("\n5.- Copiar archivo");
		printf("\n6.- Invertir archivo");
		printf("\n7.- Salir");
		printf("\nSelecciona una opcion: ");
		scanf("%i",&i);
		fflush(stdin);
		/*Estos casos vienen en el programa del semestre anterior
		printf("\n1.- Guardar datos de alumno.");
		printf("\n2.- Leer datos de alumno.");
		printf("\n3.- Adicionar al final.");
		printf("\n4.- Adicionar al inicio.");
		printf("\n5.- Adicionar al inicio en forma de pila.");
		printf("\n6.- Invertir el orden del archivo.");
		printf("\n7.- Salir.");
		printf("\nElija opcion ->");*/
		switch(i)
		{
			case 1:{//Guardar datos en un archivo
				system("cls");
				printf("Introduce ruta y nombre de archivo: ");
				gets(N);
				fp=AbrirArchivo(N,"w");//en modo escritura
				n=0;
				do
				{
					system("cls");
					printf("Introduce un nombre: ");
					gets(N);//guardo el nombre en una cadena de tamaño 80
					printf("\nIntroduce edad: ");
					scanf("%i",&e);//guardo la edad en un entero e
					fflush(stdin);//limpio el flujo de la informacion
					fprintf(fp,"%s %i\n",N,e);//guardar el nombre y la edad en el archivo
					printf("\nPulsa 1 para agregar mas datos, pulsa 2 para salir: ");
					scanf("%i",&n);
					fflush(stdin);
				}while(n!=2);
				fclose(fp);
				break;
			}
			case 2:{//leer los datos del archivo
				system("cls");
				printf("Introduce ruta y nombre de archivo: ");
				gets(N);
				fp=AbrirArchivo(N,"r");//abro el archivo en modo lectura
				n=1;
				printf("\tNombre\tEdad\n");
				p=0.0;
				do
				{
					fscanf(fp,"%s%i",N,&e);//lee el contenido del archivo, cuando lo lee va amperson
					if(!feof(fp))//sirve para que no se repita informacion
					{
						printf("%i\t%s\t%i\n",n,N,e);//imprime en pantalla el contenido del archivo
						p=p+e;//suma acumulativa de las edades
						n++;	//cuenta el numeor de edades para calcular el promedio
					}
				}while(!feof(fp));
				printf("\nPromedio de edades: %f",p/(n-1));
				getch();
				fclose(fp);
				break;
			}
			case 3:{//Agregar al final del archivo
				system("cls");
				printf("Introduce ruta y nombre de archivo: ");
				gets(N);
				fp=AbrirArchivo(N,"a");//se abre el archivo en modo adicion
				n=0;
				do
				{
					system("cls");//borra la pantalla
					printf("Introduce un nombre: ");
					gets(N);//guarda en una cadena de tamaño 80
					printf("\nIntroduce edad: ");//guarda en un entero e
					scanf("%i",&e);
					fflush(stdin);//limpia el flujo de la informacion
					fprintf(fp,"%s %i\n",N,e);//guarda los datos en el archivo
					printf("\nPulsa 1 para agregar mas datos, pulsa 2 para salir: ");
					scanf("%i",&n);
					fflush(stdin);//limpia el flujo de la informacion
				}while(n!=2);
				fclose(fp);
				break;
			}
			case 4:{//Agrega despues de 
				system("cls");//limpia la pantalla
				printf("Introduce ruta y nombre de archivo: ");
				gets(N);//guarda el dato en una cadena de tamaño 80
				fp=AbrirArchivo(N,"r");//se abre el archivo en modo lectura. Archivo original
				fq=AbrirArchivo("C:\\Estructuras\\temporal.txt","w");//se crea y despues se abre un archivo temporal en modo escritura
				printf("\nDespues de quien quieres ingresar el nuevo dato?: ");//se muestra el letrero en pantalla
				gets(D);//guarda el dato nuevo en una cadena de tamaño 80
				t=0;//inicializa un entero t
				do
				{
					fscanf(fp,"%s%i",T,&t);//lee el contenido del archivo original de una nueva cadena T y de un nuevo entero t
					if(!feof(fp))
					{
						if(strcmp(D,T)==0)//si la cadena D y la cadena T son iguales, entonces
						{
							fprintf(fq,"%s %i\n",T,t);//guarda el contenido en la cadena T
							H=Teclado();//con esta funcion se piden que se introduza el nombre y la edad
							fprintf(fq,"%s %i\n",H.N,H.e);//Guarda el contenido del archivo en la cadena H
						}
						else//si no...
						{
							fprintf(fq,"%s %i\n",T,t);//Guarda el contenido del archivo en la cadena T
							//printf("%s %i\n",T,t);		//Esto es chequeo
						}
					}
				}while(!feof(fp));
				fclose(fp);
				fclose(fq);
			/*	con estas instrucciones marca "error de apertura de archivo"
				fp=AbrirArchivo(N,"w");//abro el srchivo original en modo escritura
				fq=AbrirArchivo("e:\\temporal.txt","r");//abro el archivo temporal en modo lectura
				CopyF(fq,fp);//esta funcion copea el contenido del archivo temporal al original
				fclose(fp);
				fclose(fq);
				//system("C:\\Estructuras\\temporal.txt");
				system("del e:\\temporal.txt");*/
				
				//este caso funciona, solo que el archivo final es el temporal
				//con estas lineas estoy borrando el archivo original
				strcpy(R,"del ");//R es una cadena vacia
				strcat(R,N);
				system(R);
				//con estas voy a poner el temporal en el original
				strcpy(R,"copy ");
				strcat(R,"C:\\Estructuras\\destino.txt");	
				//Funcion copy trabaja ==   copy "rutaArchivoOrigen" "RutaArchivoDestino"
				strcat(R,N);
				system(R);
				system("C:\\Estructuras\\temporal.txt");			
				break;
			}
			case 5:{//Copiar archivo
				printf("Introduce ruta y nombre de archivo origen: ");
				gets(N);
				printf("\nIntroduce ruta y nombre de archivo destino: ");
				gets(D);
				fp=AbrirArchivo(N,"r");
				fq=AbrirArchivo(D,"w");
				CopyF(fp,fq);
				fclose(fp);
				fclose(fq);
				break;
			}
			case 6:{//Invertir archivo
				printf("Introduce ruta y nombre de archivo origen: ");
				gets(N);
				fp=AbrirArchivo(N,"r");//se abre el archivo en modo lectura
				fq=AbrirArchivo("C:\\Estructuras\\temporal.txt","w");//se abre un archivo temporal en modo escritura
				c=0;
				do
				{
					fscanf(fp,"%s%i",T,&t);//lee el contenido de la cadena T
					c++;//para ejemplo 4 vale 5
				}while(!feof(fp));
				c=c-1;
			//	printf("%i",c);
			//	getch();
			//	fprintf(fq,"%s %i\n",T,t);
				rewind(fp);//esto hace que el apuntador de archivo se reposicione al inicio
				for(c3=0;c3<c;c3++)
				{
					for(c2=0;c2<c-c3;c2++)
					{
						fscanf(fp,"%s%i",T,&t);//lee el contenido de la cadena T
					}
					fprintf(fq,"%s %i\n",T,t);//guarda el contenido de la cadena T en el archivo fq
					rewind(fp);//El apuntador del archivo se reposiciona al inicio
				}
				fclose(fp);
				fclose(fq);
				fp=AbrirArchivo(N,"w");//se abre el archivo original en modo escritura
				fq=AbrirArchivo("C:\\Estructuras\\temporal.txt","r");//se abre el archivo temporal en modo lectura
				CopyF(fq,fp);//se copea el contenido del archivo temporal al orignal
				fclose(fp);
				fclose(fq);
				system("del C:\\Estructuras\\temporal.txt");
			//	system("cls");
			//	printf("Invirtiendo ....");
			//	delay(50);
				break;
			}
				
		}
	}while(i!=7);
	return 0;
}
/*Alexis 18
				Alex 18
				Juan 26
				Dan 458
				
			así va a quedar el caso 6:
				Dan 458
				Juan 26
				Alex 18
				Alexis 18*/
struct nombres Teclado (void)
{
	struct nombres H;
	printf("Introduce un nombre: ");
	gets(H.N);
	printf("\nIntroduce edad: ");
	scanf("%i",&H.e);
	fflush(stdin);
	return H;
}
void CopyF (FILE *fp, FILE *fq)		//fp es el original
{
	char C[80];
	int e;
	do
	{
		fscanf(fp,"%s%i",C,&e);
		if(!feof(fp))
			fprintf(fq,"%s %i\n",C,e);
	}while(!feof(fp));
}
FILE *AbrirArchivo (char N[80], char M[5])
{
	FILE *w;
	w=fopen(N,M);
	if(w==NULL)
	{
		printf("\nError de apertura de archivo, pulsa enter para continuar");
		getch();
		exit(1);
	}
	return w;
}
