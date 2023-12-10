/*
Todos los casos son correctos
https://zoom.us/j/3659953988?pwd=QUsxSStJQTZqK25OWDRFTzNTZm5QZz09
TAREAS:
caso 6 y 7
Acomodar en un solo caso y hacer ordenamiento descendente
caso 11
Este es mi archivo final de listas simples.
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
struct libro
{
	char T[80],A[50],E[50],ED[20],P[20],ISBN[20],I[20];
	int ap;
	float p;
};
struct book
{
	char T[80],A[50],E[50],ED[20],P[20],ISBN[20],I[20];
	int ap;
	float p;
	struct book *sig; //lista autoreferenciada
};
typedef struct book * lista;
FILE* AbrirArchivo(char S[80],char Y[5]);
lista crear(void);
lista eliminar(lista head);
lista insertarA(lista head);
lista insertarFormaOrdenada(lista head);
lista insertari(lista head);
struct libro datos(void);
void insertarf(lista head);
void insertard(lista head);
void imprimirL(struct libro S);
void imprimir(lista head);
struct libro copiar2(lista L);
void ordenara(lista head);
void ordenard(lista head);
void copia(struct libro A,lista L);
int contar(lista head);
int main(void)
{
	lista head;
	struct libro L;
	int o,c,a,i,m;
	char Y[80];
	FILE *fs;
	do
	{
		printf("\tListas");
		printf("\n1.- Crear archivo nuevo");
		printf("\n2.- Insertar al final");
		printf("\n3.- Imprimir");
		printf("\n4.- Insertar al inicio");
		printf("\n5.- Insertar despues de");
		printf("\n6.- Guardar lista en un archivo");//tarea(ya)
		printf("\n7.- Leer lista desde un archivo");//tarea(ya)
		printf("\n8.- Ordenamiento (Ascendente y Descendente)");//tarea(ya)
		printf("\n10.- Eliminar libro");
		printf("\n11.- Insertar en forma ordenada");//Tarea(no)
		printf("\n12.- Insertar antes de");
		printf("\n13.- Salir");
		printf("\nElige una opcion: ");
		scanf("%i",&o);
		fflush(stdin);
		system("cls");
		switch(o)
		{
			case 1:
				head=crear();
				L=datos();
				copia(L,head);
				break;
			case 2:
				insertarf(head);
				break;	
			case 3:
				imprimir(head);
				break;
			case 4:
				head=insertari(head);
				break;
			case 5:
				insertard(head);
				break;
			case 6:
				system("cls");
				printf("Introduce ruta y nombre del archivo\t");
				gets(Y);
				fs=AbrirArchivo(Y,"wb");
				do
				{
					head=crear();//Reserva el espacio de memoria y lo asigna a head
					printf("Introduce los datos de un libro\n");
					L=datos();//Recibe la información
					fwrite(&L,sizeof(struct libro),1,fs);
					printf("Desas agregar otro?\n1.-Si\n2.-No\t");
					scanf("%i",&i);
					fflush(stdin);
					copia(L,head);//Copia en head
				}
				while(i!=2);
				fclose(fs);
				break;
			case 7:
				m=1;
				printf("Introduce ruta y nombre del archivo\t");
				gets(Y);
				fs=AbrirArchivo(Y,"rb");
				do
				{
					fread(&L,sizeof(struct libro),1,fs);
					if(!feof(fs))
					{
						printf("\n%i.-",m);
						imprimirL(L);
						m++;
					}	
				}
				while(!feof(fs));
				rewind(fs);
				getch();
				fclose(fs);
				break;
			case 8:
				do
				{
					system("cls");
					printf("1.- Ordenamiento Ascendente\n2.- Ordenamiento Descendente\n3.- Salir\nEscoge una opcion: ");
					scanf("%i",&a);
					fflush(stdin);
					switch(a)
					{
						case 1:
							ordenara(head);
							break;
						case 2:
							ordenard(head);
							break;
					}
				}while(a!=3);
				break;
			case 10:
				head=eliminar(head);
				break;
			case 11:
				head=insertarFormaOrdenada(head);
				break;
			case 12:
				head=insertarA(head);
				break;
		}
		system("cls");
	}while(o!=13);
	return 0;
}
lista insertarFormaOrdenada(lista head)
{
	struct libro L;
	char A[80];
	int b;
	lista aux,aux1,NODO;
	aux=head;
	printf("Inserta un nuevo libro: ");
	gets(A);
	if(strcmp(A,aux->T)==0)//si el libro que se desea agregar es uno ya existente no se agregara
	{
		printf("El libro ya existe en la lista, pulse una tecla para continuar");
		getch();
		return head;
	}
	if(strcmp(A,aux->T)<0)//si el primer elemento de la lista es > que el que se desea agregar, el libro se agregara al inicio
	{
		aux=insertari(aux);
		printf("%i",aux);
		return aux;
	}
	if(strcmp(A,aux->T)>0)//si el primer elemento de la lista es < que el que se desea agregar, el libro se agregara al final
	{
		insertarf(aux);
		printf("%i",aux);
		printf("%i",aux1);
		return head;
	}
	while(aux->sig!=NULL)
	{
		if(strcmp(A,aux->T)>0)
		{
			aux=aux->sig;
			insertarf(aux);
			if(strcmp(A,aux->T)<0)
			{
				aux=insertari(aux);
				return aux;
			}
		}
	}
	aux1=aux;
	aux=aux->sig;
}
lista insertarA(lista head)
{
	char A[80];
	int b;
	lista aux, aux1,NODO;
	struct libro L;
	aux=head;
	printf("Antes de quien quieres insertar: ");
	gets(A);
	//primero voy a querer insertar antes del primer libro, antes de la cabeza
	if(strcmp(A,aux->T)==0)
	{
		aux=insertari(aux);
		return aux;
	}
	//con este while se va a insertar antes de cualquer otro libro
	while(aux!=NULL)//aqui hubo un cambio
	{
		if(strcmp(A,aux->T)==0)
		{
			NODO=crear();//se crea el nuevo cajon
			L=datos();//pedir los datos y giuardarlos en el nodo
			copia(L,NODO);
			NODO->sig=aux;
			aux1->sig=NODO;
			return head;//retornamos la cabeza porque no se modifico
		}	
		aux1=aux;
		aux=aux->sig;
	}
	//ahora vamos a hacer el caso en el que se desee agregar antes de un libro que no existe
	if(aux==NULL)
	{
		system("cls");
		printf("El libro no se ha encontrado, desea agregarlo al final? ");
		printf("\n1.- Si 2.- No: ");
		scanf("%i",&b);
		if(b==1)
		{
			NODO=crear();//se crea el nuevo cajon
			L=datos();//pedir los datos y giuardarlos en el nodo
			copia(L,NODO);
			//aux1 se quedo en el ultimo cajon	
			aux1->sig=NODO;//cuando se crea un nodo se crea con todo y su nulo
			return head;
		}
	}
}
lista eliminar(lista head)
{
	lista aux,aux1;
	char A[80];
	aux=head;
	printf("Ingresa el titulo del libro que deseas eliminar: ");
	gets(A);
	if(strcmp(A,aux->T)==0)
	{
		aux1=aux->sig;
		free(aux);
		return aux1;
	}
	else
	{
		while(aux->sig!=NULL)
		{
			if(strcmp(A,aux->T)==0)
			{
				aux1->sig=aux->sig;
				printf("\naux=%s",aux->T);
				getch();
				free(aux);
				return head;
			}
			aux1=aux;
			aux=aux->sig;
		}
		if(strcmp(A,aux->T)==0)
		{
			free(aux);
			aux1->sig=NULL;
			return head;
		}
	}
}
struct libro copiar2(lista L)
{
	struct libro A;
	strcpy(A.T,L->T);
	strcpy(A.A,L->A);
	strcpy(A.E,L->E);
	A.ap=L->ap;
	strcpy(A.ED,L->ED);
	strcpy(A.ISBN,L->ISBN);
	strcpy(A.P,L->P);
	strcpy(A.I,L->I);
	A.p=L->p;
	return A;
}
void ordenard(lista head)//orden descendente
{
	int c,i,j;
	struct libro auxa,auxb,temp;
	lista aux1,aux2;
	c=contar(head);
	printf("\nCantidad: %i\n",c);
	for(i=0;i<c;i++)
	{
		aux1=head;
		aux2=aux1->sig;
		for(j=0;j<c;j++)
		{
			if(strcmp(aux2->T,aux1->T)>0)
			{
				auxa=copiar2(aux1);
				auxb=copiar2(aux2);
				temp=auxa;
				auxa=auxb;
				auxb=temp;
				copia(auxa,aux1);
				copia(auxb,aux2);
			}
			aux2=aux2->sig;
			aux1=aux1->sig;
		}
	}
}
void ordenara(lista head)
{
	int c,i,j;
	struct libro auxa,auxb,temp;
	lista aux1,aux2;
	c=contar(head);
	printf("\nCantidad: %i\n",c);
	for(i=0;i<c;i++)
	{
		aux1=head;
		aux2=aux1->sig;
		for(j=0;j<c;j++)
		{
			if(strcmp(aux2->T,aux1->T)<0)
			{
				auxa=copiar2(aux1);
				auxb=copiar2(aux2);
				temp=auxa;
				auxa=auxb;
				auxb=temp;
				copia(auxa,aux1);
				copia(auxb,aux2);
			}
			aux2=aux2->sig;
			aux1=aux1->sig;
		}
	}
}
int contar(lista head)
{
	int r=0;
	lista aux;
	aux=head;
	while(aux->sig!=NULL)
	{
		r++;
		aux=aux->sig;
	}
	return r;
}
void insertard(lista head)
{
	struct libro L;
	char A[80];
	int flag=0,a;
	lista aux,aux1,NODO;
	aux1=head;
	NODO=crear();
	printf("Introduce el titulo del libro anterior: ");
	gets(A);
	while(aux1->sig!=NULL)
	{
		if(strcmp(A,aux1->T)==0)
		{
			flag=1;
			break;
		}
		//aux=aux1;
		aux1=aux1->sig;
	}
	if(flag==1)
	{
		L=datos();
		copia(L,NODO);
		//NODO->sig=aux1;
		//aux->sig=NODO;
		NODO->sig=aux1->sig;
		aux1->sig=NODO;
	}
	if(flag==0)
	{
		printf("Titulo no encontrado\n1.- Insertar al final\n2.- Salir: ");
		scanf("%i",&a);
		fflush(stdin);
		if(a==1)
		{
			NODO=crear();
			L=datos();
			copia(L,NODO);
			aux1=head;
			while(aux1->sig!=NULL)
			{
				aux1=aux1->sig;
			}
			aux1->sig=NODO;
		}
	}
}
lista insertari(lista head)
{
	struct libro L;
	lista aux,NODO;
	aux=head;
	NODO=crear();
	NODO->sig=aux;
	L=datos();
	copia(L,NODO);
	return NODO;
}
void insertarf(lista head)
{
	struct libro L;
	/*
	int a=5,*p;
	p=&a;
	*/
	lista aux,NODO;
	aux=head;
	while(aux->sig!=NULL)
	{
		aux=aux->sig;
	}
	NODO=crear();
	L=datos();
	copia(L,NODO);
	aux->sig=NODO;
}
void imprimirL(struct libro S)
{
	printf("Tictulo:\t%s\n",S.T);
	printf("Autor:\t%s\n",S.A);
	printf("Editorial:\t%s\n",S.E);
	printf("ISBN:\t%s\n",S.ISBN);
	printf("Paics:\t%s\n",S.P);
	printf("Idioma:\t%s\n",S.I);
	printf("Año de publicaciocn:\t%i\n",S.ap);
	printf("Ediciocn:\t%s\n",S.ED);
	printf("Precio:\t%f\n\n\n",S.p);
	getch();
}
void imprimir(lista head)
{
	lista L;
	int i=1;
	L=head;
	do
	{
		printf("\n%i.- Titulo: ",i);
		printf("\nTitulo: %s",L->T);
		printf("\nAutor: %s",L->A);
		printf("\nEditorial: %s",L->E);
		printf("\nISBM: %s",L->ISBN);
		printf("\nPais de publicacion: %s",L->P);
		printf("\nIdioma: %s",L->I);
		printf("\nAño de publicacion: %i",L->ap);
		printf("\nPrecio: %f\n",L->p);
		i++;
		L=L->sig;
	}while(L!=NULL);
	getch();
}
void copia(struct libro A,lista L)//esta funcion copea de una structura a una lista
{
	strcpy(L->T,A.T);
	strcpy(L->A,A.A);
	strcpy(L->E,A.E);
	L->ap=A.ap;
	strcpy(L->ED,A.ED);
	strcpy(L->ISBN,A.ISBN);
	strcpy(L->P,A.P);
	strcpy(L->I,A.I);
	L->p=A.p;
}
lista crear(void)
{
	lista nodo;
	nodo=(lista)malloc(sizeof(struct book));
	if(nodo==NULL)
	{
		printf("\nError de asignacion de memoria, pulse una tecla para continuar");
		getch();
		exit(1);
	}
	nodo->sig=NULL; //No apunta a nadie mas
	return nodo;
}
struct libro datos(void)
{
	struct libro S;
	printf("\nIntroduce el titulo: ");
	gets(S.T);
	printf("\nIntroduce el autor: ");
	gets(S.A);
	printf("\nIntroduce la editorial: ");
	gets(S.E);
	printf("\nIntroduce la fecha de publicacion: ");
	scanf("%i",&S.ap);
	fflush(stdin);
	printf("\nIntroduce la edicion: ");
	gets(S.ED);
	printf("\nIntroduce el ISBN: ");
	gets(S.ISBN);
	printf("\nIntroduce el pais: ");
	gets(S.P);
	printf("\nIntroduce el idioma: ");
	gets(S.I);
	printf("\nIntroduce el precio: ");
	scanf("%f",&S.p);
	fflush(stdin);
	return S;
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
