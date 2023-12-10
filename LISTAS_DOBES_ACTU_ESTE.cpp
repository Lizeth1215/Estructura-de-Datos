#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define pi 3.141592654
struct Libro
{
	char T[80],A[50],E[50],ED[20],P[20],ISBN[20],I[20],AUX[20];
	int ap;
	float p;
};
struct book
{
	char T[80],A[50],E[50],ED[20],P[20],ISBN[20],I[20],AUX[20];
	int ap;
	float p;
	struct book *left;
	struct book *right; //lista autoreferenciada
};
typedef struct book * ListaDoble; //tipo de dato lista
//typedef --> para poder apodos
ListaDoble crea (void); //debe estar enseguida de typedef
struct Libro datos (void);
void copia (struct Libro W,ListaDoble L);
void FinalIz (ListaDoble raiz);
void FinalDe (ListaDoble raiz);
void imprimeDe_Iz (ListaDoble raiz);
void imprimeIz_De (ListaDoble raiz);
void imprimeRaiz (ListaDoble raiz);
void InsertarDespues_Iz (ListaDoble raiz);
void Buscar (ListaDoble raiz);
/*LINK: https://zoom.us/j/3659953988?pwd=QUsxSStJQTZqK25OWDRFTzNTZm5QZz09*/
int main (void)
{
	ListaDoble raiz; //se transfiere a todas las funciones para acceder a todos los datos
	struct Libro L;
	int e;
	do
	{
		printf("1. Crear lista doble\n");
		printf("2. Insertar al final de la izquierda\n");
		printf("3. Insertar al final de la derecha\n");
		printf("4. Imprimir de derecha a izquierda\n");
		printf("5. Imprimir de izquierda a derecha\n");
		printf("6. Imprimir desde raiz\n");
		printf("7. Insertar despues de, a la izquierda\n");
		printf("8. Busqueda Google\n");
		printf("9. Salir\n");
		printf("Elige opcion: ");
		scanf("%i",&e);
		fflush(stdin);
		system("cls");
		switch (e)
		{
			case 1:
				raiz=crea();
				L=datos();
				copia(L,raiz);
				getch();
				break;
			case 2:
				FinalIz(raiz);
				getch();
				break;
			case 3:
				FinalDe(raiz);
				getch();
				break;
			case 4:
				imprimeDe_Iz(raiz);
				getch();
				break;
			case 5:
				imprimeIz_De(raiz);
				getch();
				break;
			case 6:
				imprimeRaiz (raiz);
				getch();
				break;
			case 7:
				InsertarDespues_Iz(raiz);
				getch();
				break;
			case 8:
				Buscar(raiz);
				getch();
				break;
		}
		system("cls");
	}while(e!=9);
	//EJERCICIO insertar despues de a la izquierda
	getch();
	return 0;
}
void Buscar (ListaDoble raiz) //acabar bien proyecto o como tarea, o ambos
{
	int i,j;
	char P[80],S[50];
	ListaDoble aux, aux_r;
	aux=raiz;
	while(aux->left!=NULL)
	{
		aux=aux->left;
	}
	aux_r=aux;
	printf("\nIntroduce el autor: ");
	i=0;
	do
	{
		P[i]=getch();
		P[i+1]='\0';
		while(aux->right!=NULL)
		{
			for(j=0;j<strlen(P);j++) //sacar subcadena del autor
			{
				S[j]=aux->A[j];
			}
			S[j]='\0';
			if(strcmp(S,P)==0)
			{
				printf("\n%s ",aux->A);
			}
			aux=aux->right;
		}
		printf("\n\n\n");
		aux=aux_r;
		i++;
	}while(P[i-1]!=13);
}
void InsertarDespues_Iz (ListaDoble raiz)
{
	ListaDoble nodo,aux,aux2;
	struct Libro W;
	char T1[80];
	int flag=0,r;
	aux2=raiz;
	printf("\n%cDespu%cs de qu%c libro? \t",168,130,130);
	gets(T1);
	while(aux2!=NULL)
	{
		if(strcmp(T1,aux2->T)==0)
		{
			flag=1;
			break;
		}
		//aux=aux2;
		aux2=aux2->left;
	}
	if(flag==1)//caso intermedio
	{
		nodo=crea();
		W=datos();
		copia(W,nodo);
		if(aux2->left==NULL)
		{
			nodo->right=aux2; //amarilla
			//azul ya creada por apuntar a NULL, igual verde
			aux2->left=nodo; //roja
		}
		else
		{
			nodo->left=aux2->left; //amarilla
			//aux2->left=nodo;
			nodo->right=aux2; //azul
			aux2->left=nodo; //roja
			aux2=nodo->left;
			aux2->right=nodo; //verde
		}
		
	}
	else
	{
		printf("\n\tERROR\n\tLibro no encontrado, deseas insertarlo al final?");
		printf("\n\tsi=1,\tno=0\n\t");
		scanf("%i",&r);
		fflush(stdin);
		system("cls");
		if(r==1)
		{
			nodo=crea();
			W=datos();
			copia(W,nodo);
			aux2=raiz;
			while(aux2->left!=NULL)
			{
				aux2=aux2->left;
			}
			aux2->left=nodo;
		}
	}
	printf("\nListo, presione una tecla para continuar\n");
}
void FinalDe (ListaDoble raiz)
{
	ListaDoble aux,nodo;
	struct Libro L;
	aux=raiz;
	printf("\n\tInsertando al final de la derecha...\t\n");
	while(aux->right!=NULL)
	{
		aux=aux->right;
	}
	nodo=crea();
	L=datos();
	copia(L,nodo);
	nodo->left=aux;
	aux->right=nodo;
	printf("\n\tListo, presione una tecla para continuar\n");
}
void FinalIz (ListaDoble raiz)
{
	ListaDoble aux,nodo;
	struct Libro L;
	aux=raiz;
	printf("\n\tInsertando al final de la izquierda...\t\n");
	while(aux->left!=NULL)
	{
		aux=aux->left;
	}
	nodo=crea();
	L=datos();
	copia(L,nodo);
	nodo->right=aux;
	aux->left=nodo;
	printf("\n\tListo, presione una tecla para continuar\n");
}
void imprimeIz_De (ListaDoble raiz) //imprimir de izquierda a derecha
{
/*	ISBM (Clave de cada libro), Pais, Idioma (I), Precio (p)
	TAREA: Que es ISBM y 3 ejemplos*/
	int i=1;
	ListaDoble S;
	S=raiz;
	printf("\n\tImpresion de izquierda a derecha\t\n");
	while(S->left!=NULL)
		S=S->left;
	do
	{
		printf("\nLibro %i\nT%ctulo: \t%s",i,161,S->T);
		printf("\nAutor: \t%s",S->A);
		printf("\nEditorial: \t%s",S->E);
		printf("\nPublicaci%cn: \t%i",162,S->ap);
		printf("\nEdici%cn: \t%s",162,S->ED);
		printf("\nISBN: \t%s",S->ISBN);
		printf("\nPa%cs: \t%s",161,S->P);
		printf("\nIdioma: \t%s",S->I);
		printf("\nPrecio: \t%f",S->p);
		printf("\n\n");
		i++;
		S=S->right;
	}while(S!=NULL);
	//getch();
}
void imprimeDe_Iz (ListaDoble raiz) //imprimir de derecha a izquierda
{
/*	ISBM (Clave de cada libro), Pais, Idioma (I), Precio (p)
	TAREA: Que es ISBM y 3 ejemplos*/
	int i=1;
	ListaDoble S;
	S=raiz;
	printf("\n\tImpresion de derecha a izquierda\t\n");
	while(S->right!=NULL)
		S=S->right;
	do
	{
		printf("\nLibro %i\nT%ctulo: \t%s",i,161,S->T);
		printf("\nAutor: \t%s",S->A);
		printf("\nEditorial: \t%s",S->E);
		printf("\nPublicaci%cn: \t%i",162,S->ap);
		printf("\nEdici%cn: \t%s",162,S->ED);
		printf("\nISBN: \t%s",S->ISBN);
		printf("\nPa%cs: \t%s",161,S->P);
		printf("\nIdioma: \t%s",S->I);
		printf("\nPrecio: \t%f",S->p);
		printf("\n\n");
		i++;
		S=S->left;
	}while(S!=NULL);
	//getch();
}
void imprimeRaiz (ListaDoble raiz)
{
/*	ISBM (Clave de cada libro), Pais, Idioma (I), Precio (p)
	TAREA: Que es ISBM y 3 ejemplos*/
	int i=1;
	ListaDoble S;
	S=raiz;
	printf("\n\tImpresion desde raiz\t\n");
	printf("\n\tRaiz:\n");
	//if(raiz->left!=NULL)
	do
	{
		printf("\nLibro %i\nT%ctulo: \t%s",i,161,S->T);
		printf("\nAutor: \t%s",S->A);
		printf("\nEditorial: \t%s",S->E);
		printf("\nPublicaci%cn: \t%i",162,S->ap);
		printf("\nEdici%cn: \t%s",162,S->ED);
		printf("\nISBN: \t%s",S->ISBN);
		printf("\nPa%cs: \t%s",161,S->P);
		printf("\nIdioma: \t%s",S->I);
		printf("\nPrecio: \t%f",S->p);
		printf("\n\n");
		i++;
		if(i==2)
			printf("\n\tIzquierdos: \n");
		S=S->left;
	}while(S!=NULL);
	S=raiz;
	printf("\n\tDerechos: \n");
	i=1;
	if(raiz->right!=NULL)
	{
		S=S->right;
		do
		{
			printf("\nLibro %i\nT%ctulo: \t%s",i,161,S->T);
			printf("\nAutor: \t%s",S->A);
			printf("\nEditorial: \t%s",S->E);
			printf("\nPublicaci%cn: \t%i",162,S->ap);
			printf("\nEdici%cn: \t%s",162,S->ED);
			printf("\nISBN: \t%s",S->ISBN);
			printf("\nPa%cs: \t%s",161,S->P);
			printf("\nIdioma: \t%s",S->I);
			printf("\nPrecio: \t%f",S->p);
			printf("\n\n");
			i++;
			S=S->right;
		}while(S!=NULL);
	}
}
void copia (struct Libro W,ListaDoble L)
{
/*Titulo (T), autor(A), editorial(E), a?o de publicacion (ap), edicion (ED), 
ISBN (Clave de cada libro), Pais, Idioma (I), Precio (p)*/
	strcpy(L->T,W.T);
	strcpy(L->A,W.A);
	strcpy(L->E,W.E);
	strcpy(L->ED,W.ED);
	strcpy(L->ISBN,W.ISBN);
	strcpy(L->P,W.P);
	strcpy(L->I,W.I);
	L->ap=W.ap;
	L->p=W.p;
}
struct Libro datos (void)
{
	struct Libro S;
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
ListaDoble crea (void)
{
	ListaDoble nodo;
	nodo=(ListaDoble)malloc(sizeof(struct book));
	if(nodo==NULL)
	{
		printf("\tError de asignacion de memoria\n\tPulse una tecla para continuar");
		getch();
		exit(1);
	}
	nodo->left=NULL;
	nodo->right=NULL; //No apunta a nadie mas
	return nodo;
}
