/*Título(T), Autor(A), Editorial(E), Año de publicación(AP), Edición(ED), 
ISBN(Número identificador de cada libro), País(P), Idioma(I), Precio(s)
Investigar qué es el ISBN, traer ejemplos(3).
char T[80],A[50],E[50],ISBN[15],P[20],ED[20],I[10];
	int AP;
	float s;*/
//Tarea de MODIFICAR
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct libro
{
	char T[80];
	char A[50];
	char E[50];
	int AP;
	char ED[20];
	char ISBN[15];
	char P[20];
	char I[10];
	float s;
};
void OrdenDescendente(FILE *fs);
void OrdenAscendente(FILE *fs);
struct libro datos(void);
FILE* AbrirArchivo(char S[80],char Y[5]);
void imprime(struct libro S);
int contar (FILE*fs);
int main (void)
{
	char Y[80],M[80];
	struct libro A[3];//Cada elemento de A contiene un libro
	struct libro S;
	int i,s,h,m,band=0,a,b;
	FILE *fs;
	//S=datos();
	/*printf("Introduce ruta y nombre del archivo\t");
	gets(Y);*/
	
	/*fs=AbrirArchivo(Y,"wb");//wb write binario, el archivo es un archivo de acceso aleatorio, no secuencial, se puede acceder a cualquier parte del archivo de golpe
	fwrite(apuntador a la variable en la que se guaradarán los datos,tamaño de datos,cantidad del mismo tipo, apuntador archivo);
	fwrite(&S,sizeof(struct libro),1,fs);//sizeof:Todos los bytes de la estructura, guarda los datos de un libro*/
	
	/*fs=AbrirArchivo(Y,"rb");//rb read binario
	fread(&S,sizeof(struct libro),1,fs);
	imprime(S);*/
	
	/*fs=AbrirArchivo(Y,"wb");
	for(i=0;i<3;i++)
	{
		A[i]=datos();//Guarda los datos de tres libros
	}
	fwrite(&A,sizeof(struct libro),3,fs);*/
	
	/*Manejar tres datos a la vez
	fs=AbrirArchivo(Y,"rb");
	fread(&A,sizeof(struct libro),3,fs);
	for(i=0;i<3;i++)
		imprime(A[i]);	
	fclose(fs);*/
	
	do
	{
		system("cls");
		printf("1.-Crear archivo nuevo\n2.-Leer de un archivo\n3.-Adicionar a un archivo\n4.-Imprimir\n5.-Agregar despues de\n6.-Ordenamiento(Ascendente y Descendente)\n7.-Modificar\n8.-Salir\n");
		printf("Escoge una opcion: ");
		scanf("%i",&s);
		fflush(stdin);//Si no se limpia el flujo, el gets puede fallar al abrir el archivo
		switch(s)
		{
			case 1:
				printf("Introduce ruta y nombre del archivo\t");
				gets(Y);
				fs=AbrirArchivo(Y,"wb");
				do
				{
					printf("Introduce los datos de un libro\n");
					S=datos();
					fwrite(&S,sizeof(struct libro),1,fs);
					printf("Desas agregar otro?\n1.-Si\n2.-No\t");
					scanf("%i",&i);
					fflush(stdin);
				}
				while(i!=2);
				fclose(fs);
				break;
			case 2:
				m=1;
				printf("Introduce ruta y nombre del archivo\t");
				gets(Y);
				fs=AbrirArchivo(Y,"rb");
				do
				{
					fread(&S,sizeof(struct libro),1,fs);
					if(!feof(fs))
					{
						printf("\n%i.-",m);
						imprime(S);
						m++;
					}	
				}
				while(!feof(fs));
				rewind(fs);
			//	printf("%i",contar(fs));
				getch();
				fclose(fs);
				break;
			case 3:
				printf("Introduce ruta y nombre del archivo\t");
				gets(Y);
				fs=AbrirArchivo(Y,"ab");//ad binario
				do
				{
					printf("Introduce los datos de un libro\n");
					S=datos();
					fwrite(&S,sizeof(struct libro),1,fs);
					printf("Desas agregar otro?\n1.-Si\n2.-No\t");
					scanf("%i",&i);
					fflush(stdin);
				}
				while(i!=2);
				fclose(fs);
				break;
			case 4:
				do
				{
					system("cls");
					printf("1.-Por posicion\n2.-Por titulo\n3.-Salir");
					printf("\nEscoge una opcion: ");
					scanf("%i",&i);
					fflush(stdin);
					switch(i)
					{
						case 1:
							printf("Introduce ruta y nombre del archivo\t");
							gets(Y);
							fs=AbrirArchivo(Y,"rb");
							h=contar(fs);
							rewind(fs);
							printf("Escoge un libro del 1 al %i\n",h);
							scanf("%i",&m);
							fflush(stdin);
							//fseek(apuntador archivo,bytes a omitir,(SEEK_SET)(SEEK_END)(SEEK_CUR))//desde el inicio, desde el final, desde la posición del cursor
							if(1<=m && m<=h)
							{
								fseek(fs,(m-1)*sizeof(struct libro),SEEK_SET);//m*sizeof(struct libro), omite tantas veces el peso de una estructura, un libro
								fread(&S,sizeof(struct libro),1,fs);//un mundo feliz
								imprime(S);
								getch();
							}
							else
							{
								printf("\nLibro no encontrado, pulsa una tecla para continuar ");
								getch();
								
							}
							fclose(fs);
							break;
						case 2:
							printf("Introduce ruta y nombre del archivo\t");
							gets(Y);
							fs=AbrirArchivo(Y,"rb");
							rewind(fs);
							printf("Introduce el titulo del libro a buscar: ");
							gets(Y);
							do
							{
								fread(&S,sizeof(struct libro),1,fs);
								if(strcmp(S.T,Y)==0)
								{
									imprime(S);
									band=1;
									break;
								}
							}while(!feof(fs));
							if(band==0)
							{
								printf("\nTitulo no encontrado, presione una tecla para continuar");
								getch();
							}
							fclose(fs);
					}
				}while(i!=3);
				break;
			case 5://agregar despues de sin archivo temporal
				system("cls");
				printf("Introduce ruta y nombre del archivo\t");
				gets(Y);
				fs=AbrirArchivo(Y,"rb");
				h=contar(fs);
				printf("h=%i\n",h);
				getch();
				rewind(fs);
				printf("Despues de que libro deseas agregar: ");
				gets(M);
				s=1;
				do//este ciclo me dice en que posicion se encuentra el libro a buscar
				{
					fread(&S,sizeof(struct libro),1,fs);
					if(strcmp(M,S.T)==0)
						break;
					s++;
				}while(!feof(fs));
			//	printf("s=%i\n",s);
				getch();
				//rewind(fs);
				fclose(fs);
				fs=AbrirArchivo(Y,"ab");
				strcpy(S.T,"blanco");
				fwrite(&S,sizeof(struct libro),1,fs);
				fclose(fs);
				fs=AbrirArchivo(Y,"rb+");//se abre en modo de lectura y escritura
				//h es el total de archivos
				for(m=h;m>=s+1;m--)//s es la posicion del libro89 que se busca
				{
					fseek(fs,(m-1)*sizeof(struct libro),SEEK_SET);//m-1 se coloca en la posicion del libro m, justo al inicio
					fread(&S,sizeof(struct libro),1,fs);
					fseek(fs,m*sizeof(struct libro),SEEK_SET);
					fwrite(&S,sizeof(struct libro),1,fs);
				}
				//con estas instrucciones se va a copear el nuevo libro en la posicion correcta
				fseek(fs,s*sizeof(struct libro),SEEK_SET);
				S=datos();
				fwrite(&S,sizeof(struct libro),1,fs);//hasta aqui
				fclose(fs);
				break;	
			case 6:
				system("cls");
				printf("1.-Orden Ascendente\n2.-Orden Descendente\n3.-Salir");
				printf("\nEscoge una opcion: ");
				scanf("%i",&b);
				fflush(stdin);
				switch(b)
				{
					case 1:
						printf("introduce ruta y nombre del archivo: ");
						gets(Y);
						fs=AbrirArchivo(Y,"rb+");
						OrdenAscendente(fs);
						fclose(fs);
						break;
					case 2:
						printf("introduce ruta y nombre del archivo: ");
						gets(Y);
						fs=AbrirArchivo(Y,"rb+");
						OrdenDescendente(fs);	
						fclose(fs);
						break;
				}
				if(b==3);
					break;
			case 7://MODIFICAR
				system("cls");
				printf("Introduce ruta y nombre del archivo\t");
				gets(Y);
				fs=AbrirArchivo(Y,"rb+");//lectura y escritura
				printf("¿Que opcion deseas modificar?");
				printf("\n1.-Todo\n2.-Titulo\n3.-Autor\n4.-Editorial\n5.-Año de publicacion\n6.-Edicion\n7.-ISBN\n8.-Pais\n9.-Idioma\n10.-Precio\n11.-Salir");
				printf("\nEscoge una opcion: ");
				scanf("%i",&a);
				fflush(stdin);
				if(a==11)
					break;
				printf("Introduce el titulo del libro a buscar: ");
				gets(M);
				i=1;
				band=0;
				do
				{
					fread(&S,sizeof(struct libro),1,fs);
					if(strcmp(S.T,M)==0)
					{
						band=1;
						break;
					}
					i++;
				}while(!feof(fs));	
				if(band==0)
				{
					printf("Titulo del libro no encontrado, presione una tecla para continuar");
					getch();
				}
				else
				{
					switch(a)
					{
						case 1://MODIFICAR TODO
							fseek(fs,(i-1)*sizeof(struct libro),SEEK_SET);//Muestra los datos originales del libro i-1
							fread(&S,sizeof(struct libro),1,fs);//lee los datos
							imprime(S);//imprime los datos del libro
							fseek(fs,(i-1)*sizeof(struct libro),SEEK_SET);
							printf("Introduce el nuevo titulo \t: ");
							gets(S.T);
							fwrite(S.T,sizeof(char)*80,1,fs);
							fseek(fs,(i-1)*sizeof(struct libro)+sizeof(char)*80,SEEK_SET);
							printf("Introduce el nuevo autor \t: ");
							gets(S.A);
							fwrite(S.A,sizeof(char)*50,1,fs);
							fseek(fs,(i-1)*sizeof(struct libro)+sizeof(char)*80+sizeof(char)*50,SEEK_SET);//omite titulo y autor
							printf("Introduce la nueva editorial\t: ");
							gets(S.E);
							fwrite(S.E,sizeof(char)*50,1,fs);
							fseek(fs,(i-1)*sizeof(struct libro)+sizeof(char)*80+sizeof(char)*50+sizeof(char)*50,SEEK_SET);//omite titulo y autor
							printf("Introduce el nuevo año\t: ");
							scanf("%i",&S.AP);
							fflush(stdin);
							fwrite(&(S.AP),sizeof(int),1,fs);
							fseek(fs,(i-1)*sizeof(struct libro)+sizeof(char)*80+sizeof(char)*50+sizeof(char)*50+sizeof(int),SEEK_SET);
							printf("Introduce la nueva edicion \t: ");
							gets(S.ED);
							fwrite(S.ED,sizeof(char)*20,1,fs);
							fseek(fs,(i-1)*sizeof(struct libro)+sizeof(char)*80+sizeof(char)*50+sizeof(char)*50+sizeof(int)+sizeof(char)*20,SEEK_SET);//con esta instruccion me desplazo al renglon donde esta el ISBN que quiero modificar
							printf("Introduce el nuevo ISBN \t: ");
							gets(S.ISBN);
							fwrite(S.ISBN,sizeof(char)*15,1,fs);
							fseek(fs,(i-1)*sizeof(struct libro)+sizeof(char)*80+sizeof(char)*50+sizeof(char)*50+sizeof(int)+sizeof(char)*20+sizeof(char)*15,SEEK_SET);
							printf("Introduce el nuevo pais\t: ");
							gets(S.P);
							fwrite(S.P,sizeof(char)*20,1,fs);
							fseek(fs,(i-1)*sizeof(struct libro)+sizeof(char)*80+sizeof(char)*50+sizeof(char)*50+sizeof(int)+sizeof(char)*20+sizeof(char)*15+sizeof(char)*20,SEEK_SET);
							printf("Introduce el nuevo idioma \t: ");
							gets(S.I);
							fwrite(S.I,sizeof(char)*10,1,fs);
							fseek(fs,(i-1)*sizeof(struct libro)+sizeof(char)*80+sizeof(char)*50+sizeof(char)*50+sizeof(int)+sizeof(char)*20+sizeof(char)*15+sizeof(char)*20+sizeof(char)*10,SEEK_SET);
							printf("Introduce el nuevo precio \t: ");
							scanf("%f",&S.s);
							fflush(stdin);
							fwrite(&(S.s),sizeof(float),1,fs);
							fclose(fs);
							break;
						case 2://TITULO 
							fseek(fs,(i-1)*sizeof(struct libro),SEEK_SET);//Muestra los datos originales del libro i-1
							fread(&S,sizeof(struct libro),1,fs);//lee los datos
							imprime(S);//imprime los datos del libro
							fseek(fs,(i-1)*sizeof(struct libro),SEEK_SET);
							printf("Introduce el nuevo titulo \t: ");
							gets(S.T);
							fwrite(S.T,sizeof(char)*80,1,fs);//Guardar el arreglo donde esta años
							fclose(fs);
							break;
						case 3://AUTOR 
							fseek(fs,(i-1)*sizeof(struct libro),SEEK_SET);//Muestra los datos originales del libro i-1
							fread(&S,sizeof(struct libro),1,fs);//lee los datos
							imprime(S);//imprime los datos del libro
							fseek(fs,(i-1)*sizeof(struct libro)+sizeof(char)*80,SEEK_SET);
							printf("Introduce el nuevo autor \t: ");
							gets(S.A);
							fwrite(S.A,sizeof(char)*50,1,fs);//Guardar el arreglo donde esta años
							fclose(fs);
							break;
						case 4://EDITORIAL
							fseek(fs,(i-1)*sizeof(struct libro),SEEK_SET);//Muestra los datos originales del libro i-1
							fread(&S,sizeof(struct libro),1,fs);
							imprime(S);
							fseek(fs,(i-1)*sizeof(struct libro)+sizeof(char)*80+sizeof(char)*50,SEEK_SET);//omite titulo y autor
							printf("Introduce la nueva editorial\t: ");
							gets(S.E);
							fwrite(S.E,sizeof(char)*50,1,fs);//Guardar el arreglo donde esta la editorial
							fclose(fs);
							break;
						case 5://AÑO 
							fseek(fs,(i-1)*sizeof(struct libro),SEEK_SET);//Muestra los datos originales del libro i-1
							fread(&S,sizeof(struct libro),1,fs);
							imprime(S);
							fseek(fs,(i-1)*sizeof(struct libro)+sizeof(char)*80+sizeof(char)*50+sizeof(char)*50,SEEK_SET);//omite titulo y autor
							printf("Introduce el nuevo año\t: ");
							scanf("%i",&S.AP);
							fflush(stdin);
							system("cls");
							fwrite(&(S.AP),sizeof(int),1,fs);//Guardar el arreglo donde esta la editorial. lleva amperson cuando es entero
							fclose(fs);
							break;
						case 6://EDICIÓN 
							fseek(fs,(i-1)*sizeof(struct libro),SEEK_SET);//Muestra los datos originales del libro i-1
							fread(&S,sizeof(struct libro),1,fs);//lee los datos
							imprime(S);//imprime los datos del libro
							fseek(fs,(i-1)*sizeof(struct libro)+sizeof(char)*80+sizeof(char)*50+sizeof(char)*50+sizeof(int),SEEK_SET);
							printf("Introduce la nueva edicion \t: ");
							gets(S.ED);
							fwrite(S.ED,sizeof(char)*20,1,fs);//Guardar el arreglo donde esta años
							fclose(fs);
							break;
						case 7://ISBN 
							fseek(fs,(i-1)*sizeof(struct libro),SEEK_SET);//Muestra los datos originales del libro i-1
							fread(&S,sizeof(struct libro),1,fs);//lee los datos
							imprime(S);//imprime los datos del libro
							fseek(fs,(i-1)*sizeof(struct libro)+sizeof(char)*80+sizeof(char)*50+sizeof(char)*50+sizeof(int)+sizeof(char)*20,SEEK_SET);//con esta instruccion me desplazo al renglon donde esta el ISBN que quiero modificar
							printf("Introduce el nuevo ISBN \t: ");
							gets(S.ISBN);
							fwrite(S.ISBN,sizeof(char)*15,1,fs);//Guardar el arreglo donde esta el ISBN
							fclose(fs);
							break;
						case 8://PAIS 
							fseek(fs,(i-1)*sizeof(struct libro),SEEK_SET);//Muestra los datos originales del libro i-1
							fread(&S,sizeof(struct libro),1,fs);//lee los datos
							imprime(S);//imprime los datos del libro
							fseek(fs,(i-1)*sizeof(struct libro)+sizeof(char)*80+sizeof(char)*50+sizeof(char)*50+sizeof(int)+sizeof(char)*20+sizeof(char)*15,SEEK_SET);
							printf("Introduce el nuevo pais\t: ");
							gets(S.P);
							fwrite(S.P,sizeof(char)*20,1,fs);//Guardar el arreglo donde esta años
							fclose(fs);
							break;
						case 9://IDIOMA 
							fseek(fs,(i-1)*sizeof(struct libro),SEEK_SET);//Muestra los datos originales del libro i-1
							fread(&S,sizeof(struct libro),1,fs);//lee los datos
							imprime(S);//imprime los datos del libro
							fseek(fs,(i-1)*sizeof(struct libro)+sizeof(char)*80+sizeof(char)*50+sizeof(char)*50+sizeof(int)+sizeof(char)*20+sizeof(char)*15+sizeof(char)*20,SEEK_SET);
							printf("Introduce el nuevo idioma \t: ");
							gets(S.I);
							fwrite(S.I,sizeof(char)*10,1,fs);//Guardar el arreglo donde esta años
							fclose(fs);
							break;
						case 10://PRECIO
							fseek(fs,(i-1)*sizeof(struct libro),SEEK_SET);//Muestra los datos originales del libro i-1
							fread(&S,sizeof(struct libro),1,fs);//lee los datos
							imprime(S);//imprime los datos del libro
							fseek(fs,(i-1)*sizeof(struct libro)+sizeof(char)*80+sizeof(char)*50+sizeof(char)*50+sizeof(int)+sizeof(char)*20+sizeof(char)*15+sizeof(char)*20+sizeof(char)*10,SEEK_SET);
							printf("Introduce el nuevo precio \t: ");
							scanf("%f",&S.s);
							fflush(stdin);
							system("cls");
							fwrite(&(S.s),sizeof(float),1,fs);//Guardar el arreglo donde esta años
							fclose(fs);
							break;
					}
				}
			break;
		}
	}while(s!=8);
	return 0;
}
void OrdenAscendente(FILE *fs)
{
	struct libro S,S2,S3;
	int a,j,i;
	a=contar(fs);
	getch();
	a--;
	rewind(fs);
	for(j=0;j<a;j++)
		{
			for(i=0;i<a;i++)
				{
					fread(&S,sizeof(struct libro),1,fs);
					fread(&S2,sizeof(struct libro),1,fs);
					if(strcmp(S.T,S2.T)==1)
						{
							S3=S;
							S=S2;
							S2=S3;
							fseek(fs,i*sizeof(struct libro),SEEK_SET);
							fwrite(&S,80*sizeof(char),1,fs);
							fseek(fs,(i+1)*sizeof(struct libro),SEEK_SET);
							fwrite(&S2,80*sizeof(char),1,fs);
						}
				fseek(fs,(i+1)*sizeof(struct libro),SEEK_SET);
				}
		rewind(fs);
		}
}
void OrdenDescendente(FILE *fs)
{
	struct libro S,S2,S3;
	int a,j,i;
	a=contar(fs);
	getch();
	a--;
	rewind(fs);
	for(j=0;j<a;j++)
		{
			for(i=0;i<a;i++)
				{
					fread(&S,sizeof(struct libro),1,fs);
					fread(&S2,sizeof(struct libro),1,fs);
					if(strcmp(S.T,S2.T)==-1)
						{
							S3=S;
							S=S2;
							S2=S3;
							fseek(fs,i*sizeof(struct libro),SEEK_SET);
							fwrite(&S,80*sizeof(char),1,fs);
							fseek(fs,(i+1)*sizeof(struct libro),SEEK_SET);
							fwrite(&S2,80*sizeof(char),1,fs);
						}
				fseek(fs,(i+1)*sizeof(struct libro),SEEK_SET);
				}
		rewind(fs);
		}
}
int contar (FILE*fs)
{
	int s=0;
	struct libro S;
	do
	{
		fread(&S,sizeof(struct libro),1,fs);
		s++;
	}while(!feof(fs));
	printf("%i\n",s-1);
	getch();
	return (s-1);
}
void imprime(struct libro S)
{
	printf("Tictulo:\t%s\n",S.T);
	printf("Autor:\t%s\n",S.A);
	printf("Editorial:\t%s\n",S.E);
	printf("Año de publicaciocn:\t%i\n",S.AP);
	printf("Ediciocn:\t%s\n",S.ED);
	printf("ISBN:\t%s\n",S.ISBN);
	printf("Paics:\t%s\n",S.P);
	printf("Idioma:\t%s\n",S.I);
	printf("Precio:\t%f\n\n\n",S.s);
	getch();
	/*Título(T), Autor(A), Editorial(E), Año de publicación(AP), Edición(ED), 
ISBN, País(P), Idioma(I), Precio(s)
Investigar qué es el ISBN, traer ejemplos(3).
char T[80],A[50],E[50],ISBN[15],P[20],ED[20],I[10];
	int AP;
	float s;*/
}
FILE* AbrirArchivo(char S[80],char Y[5])
{
	FILE*s;
	s=fopen(S,Y);
	if (s==NULL)
	{
		printf("Error de apertura de archivo, presiona una tecla para continuar\n");
		getch();
		exit(1);
	}
	return s;
}
struct libro datos(void)
{
	struct libro S;
	printf("Introduce el tictulo\t");
	gets(S.T);
	printf("Introduce el autor\t");
	gets(S.A);
	printf("Introduce la editorial\t");
	gets(S.E);
	printf("Introduce el año de publicaciocn\t");
	scanf("%i",&S.AP);
	fflush(stdin);
	printf("Introduce la ediciocn\t");
	gets(S.ED);
	printf("Introduce el ISBN\t");
	gets(S.ISBN);
	printf("Introduce el paics\t");
	gets(S.P);
	printf("Introduce el idioma\t");
	gets(S.I);
	printf("Introduce el precio\t");
	scanf("%f",&S.s);
	fflush(stdin);
	return S;
}
