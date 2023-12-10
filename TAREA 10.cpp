//TAREA 10. AGREGAR ANTES DE 
#include<stdio.h>	
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<math.h>
#include<time.h>
struct nombres{
	char N[80];
	int e;
};
FILE *AbrirArchivo (char N[80], char M[5]);
void CopyF (FILE *fp, FILE *fq);
struct nombres Teclado (void);
int main (void)
{
	int i,n,t,c,c2,c3;
	float p,r;
	char N[80],D[80],T[80],R[80];
	struct nombres H;
	int e,a,z;
	FILE *fp,*fq;
	do
	{
		system("cls");
		printf("1.- Guardar en Nuevo Archivo");
		printf("\n2.- Leer _ archivo");
		printf("\n3.- Agregar al final del archivo");
		printf("\n4.- Agregar (despues de ___ y antes de ___");	
		printf("\n5.- Copiar archivo");
		printf("\n6.- Invertir archivo");
		printf("\n7.- Salir");
		printf("\nSelecciona una opcion: ");
		scanf("%i",&i);
		fflush(stdin);
		switch(i)
		{
			case 1:
				system("cls");
				printf("Introduce ruta y nombre de archivo: ");
				gets(N);
				fp=AbrirArchivo(N,"w");
				n=0;
				do
				{
					system("cls");
					printf("Introduce un nombre: ");
					gets(N);
					printf("\nIntroduce edad: ");
					scanf("%i",&e);
					fflush(stdin);
					fprintf(fp,"%s %i\n",N,e);
					printf("\nPulsa 1 para agregar mas datos, pulsa 2 para salir: ");
					scanf("%i",&n);
					fflush(stdin);
				}while(n!=2);
				fclose(fp);
				break;
			
			case 2:
				system("cls");
				printf("Introduce ruta y nombre de archivo: ");
				gets(N);
				fp=AbrirArchivo(N,"r");
				n=1;
				printf("\tNombre\tEdad\n");
				p=0.0;
				do
				{
					fscanf(fp,"%s%i",N,&e);
					if(!feof(fp))
					{
						printf("%i\t%s\t%i\n",n,N,e);
						p=p+e;
						n++;	
					}
				}while(!feof(fp));
				printf("\nPromedio de edades: %f",p/(n-1));
				getch();
				fclose(fp);
				break;
			
			case 3:
				system("cls");
				printf("Introduce ruta y nombre de archivo: ");
				gets(N);
				fp=AbrirArchivo(N,"a");
				n=0;
				do
				{
					system("cls");
					printf("Introduce un nombre: ");
					gets(N);
					printf("\nIntroduce edad: ");
					scanf("%i",&e);
					fflush(stdin);
					fprintf(fp,"%s %i\n",N,e);
					printf("\nPulsa 1 para agregar mas datos, pulsa 2 para salir: ");
					scanf("%i",&n);
					fflush(stdin);
				}while(n!=2);
				fclose(fp);
				break;
			
			case 4:
				do
				{
					printf("1.-Agregar antes de ___\n2.-Agregar despues de ___\n3.-Salir");
					printf("\nSelecciona una opcion: ");
					scanf("%i",&a);
					fflush(stdin);
					switch(a)
					{
						case 1:
							system("cls");
							printf("Introduce ruta y nombre de archivo: ");
							gets(N);
							fp=AbrirArchivo(N,"r");
							fq=AbrirArchivo("C:\\Estructuras\\temporal.txt","w");
							printf("\nAntes de quien quieres ingresar el nuevo dato?: ");
							gets(D);
							t=0;
							do
							{
								fscanf(fp,"%s%i",T,&t);//voy a leer el tipo de archivo (archivo nuevo.txt)
								if(!feof(fp))//si aun no llego al fin de archivo
								{
									if(strcmp(D,T)==0)//si el nombre que agregue es igual a uno de la lista, entonces
									{
										H=Teclado();//Agrego el nombre nuevo
										fprintf(fq,"%s %i\n",H.N,H.e);//Guarda en el archivo temporal con el nombre que recien agregue
										fprintf(fq,"%s %i\n",T,t);//Guardo en el arhivo tempral el resto de nombres del archivo original
									}
									else
										fprintf(fq,"%s %i\n",T,t);//Guarda en el archivo temporal el nombre 1, luego el 2 y asi hasta que los nombres coincidan
								}
								/*else
								{
									printf("Alumno no encontrado.\nDesea agregar al final? 1.-Si/n 2.-No: ");
									scanf("%i",&z);
									fflush(stdin);	
									if(z==1)
									{
										H=Teclado();
										fprintf(fq,"%s %i\n",H.N,H.e);
									}
								}*/
							}while(!feof(fp));
							fclose(fp);
							fclose(fq);
							fp=AbrirArchivo(N,"w");
							fq=AbrirArchivo("C:\\Estructuras\\temporal.txt","r");
							CopyF(fq,fp);//copio el contenido del archivo temporal al original
							fclose(fp);
							fclose(fq);
							system("del C:\\Estructuras\\temporal.txt");//borra el archivo temporal
							break;
							
						case 2:
							system("cls");
							printf("Introduce ruta y nombre de archivo: ");
							gets(N);
							fp=AbrirArchivo(N,"r");
							fq=AbrirArchivo("C:\\Estructuras\\temporal.txt","w");
							printf("\nDespues de quien quieres ingresar el nuevo dato?: ");
							gets(D);
							t=0;
							do
							{
								fscanf(fp,"%s%i",T,&t);//voy a leer el tipo de archivo fp
								if(!feof(fp))//si aun no llego al fin de archivo
								{
									if(strcmp(D,T)==0)//si las cadenas son iguales 
									{
										fprintf(fq,"%s %i\n",T,t);//Guarda en el archivo temporal la cadena T
										H=Teclado();//Agrego los datos
										fprintf(fq,"%s %i\n",H.N,H.e);//Guarda en el archivo temporal los datos
									}
									else
										fprintf(fq,"%s %i\n",T,t);//Guarda en el archivo temporal
								}
							}while(!feof(fp));
							fclose(fp);
							fclose(fq);
							fp=AbrirArchivo(N,"w");
							fq=AbrirArchivo("C:\\Estructuras\\temporal.txt","r");
							CopyF(fq,fp);//copea el contenido del archivo temporal al original
							fclose(fp);
							fclose(fq);
							system("del C:\\Estructuras\\temporal.txt");//borra el archivo temporal
							break;
					}
				}while(a!=3);

			case 5:
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
			
			case 6:
				printf("Introduce ruta y nombre de archivo origen: ");
				gets(N);
				fp=AbrirArchivo(N,"r");
				fq=AbrirArchivo("C:\\Estructuras\\temporal.txt","w");
				c=0;
				do
				{
					fscanf(fp,"%s%i",T,&t);
					c++;//para ejemplo 4 vale 5
				}while(!feof(fp));
				c=c-1;
				rewind(fp);//esto hace que el apuntador de archivo se reposicione al inicio
				for(c3=0;c3<c;c3++)
				{
					for(c2=0;c2<c-c3;c2++)
					{
						fscanf(fp,"%s%i",T,&t);
					}
					fprintf(fq,"%s %i\n",T,t);
					rewind(fp);
				}
				fclose(fp);
				fclose(fq);
				fp=AbrirArchivo(N,"w");
				fq=AbrirArchivo("C:\\Estructuras\\temporal.txt","r");
				CopyF(fq,fp);
				fclose(fp);
				fclose(fq);
				system("del C:\\Estructuras\\temporal.txt");
			//	system("cls");
			//	printf("Invirtiendo ....");
			//	delay(50);
				break;			
		}
	}while(i!=7);
	getch();
	return 0;
}
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
