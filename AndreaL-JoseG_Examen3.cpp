//Equipo: Andrea Lizeth Hernández Luna//José Alfredo Gómez García
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
//FILE* AbrirArchivo(char S[80],char Y[5]);//Listas simples
//84-497-0015-4
//10 dígitos: resto 10-->dígito de control X; nueve primeros dígitos por posición, sumar, dividir entre 11, resto:dígito de control
//13 dígitos:12 dígitos, primero por 1, luego por 3, luego por 1... dígito de control: número que hay que sumar para dividir por 10
struct caracteres
{
	char a;
	struct caracteres *sig;
};
typedef struct caracteres * lista;
int validaISBN(lista head,int flag);
void imprime_lista(lista head);
void crear_lista(lista head);
lista crear(char y);
int main(void)
{
	int s,a=0,flag;
	char y;//48
	lista head,nodo;
	/*do
	{
		y=getch();
		s=y;
		printf("%i\t",s-48);
	}while(4);
	getch();
	getch();*/
	do{
		system("cls");
		printf("1.-Escribir ISBN\n2.-Validar ISBN\n3.-Salir\nEscoje n%cmero de opci%cn\t",163,162);
		scanf("%i",&s);
		fflush(stdin);
		switch(s)
		{
			//printf("s=%i\n",s);
			//getch();
			case 1:
				system("cls");
				printf("El ISBN es de tipo:\n1.-10 d%cgitos\n2.-13 d%cgitos\n",161,161);
				scanf("%i",&flag);
				fflush(stdin);
				system("cls");
				y=getche();
				fflush(stdin);
				head=crear(y);
				crear_lista(head);
				/*printf("\n");
				imprime_lista(head);*/
				break;
			case 2:
				system("cls");
				a=validaISBN(head,flag);
				/*printf("\nregresa:%i\n",a);
				getch();*/
				if(a==1)
				{
					//printf("a=%i\n",a);
					//getch();
					printf("El ISBN ingresado es v%clido\nPresiona una tecla para continuar",160);//Válido 10 dígitos:1-111-111-11-1, 
					//caso particular:1-111-111-12-x
					//Válido 13 dígitos:1-111-111-111-11-6
					getch();
					fflush(stdin);
				}
				if(a==2)
				{
					//printf("a=%i\n",a);
					//getch();
					printf("El ISBN ingresado no es v%clido\nPresiona una tecla para continuar",160);					
					getch();
					fflush(stdin);
				}
				break;
		}		
	}while(s!=3);
	return 0;
}
int validaISBN(lista head,int flag)
{
	int s=0,h,i=1,m=0;
	lista aux1,aux2;
	char y;
	aux1=head;
	if(flag==1)//10 dígitos
	{
		do
		{
			y=aux1->a;
			//printf("%c\t",y);
			aux1=aux1->sig;
			if((y>'9'||y<'0')&&i<10&&y!='-')
			{				
				s=2;
				return s;
			}
			if(y<='9'&&y>='0'&&i<=10)
			{
				if(i<10)
				{
				h=y-48;
				h=h*i;
				m+=h;}
				i++;
				//10 dígitos: resto cero-->dígito de control X; nueve primeros dígitos por posición, sumar, dividir entre 11, resto:dígito de control
			}
			if((y=='x'||y=='X')&&i==10)
				i++;
		}while(aux1!=NULL);
		/*printf("m=%i,y=%c,ny=%i,i=%i",m,y,y,i);
		getch();*/
		if(i!=11)
		{	s=2;//2:inválido, menos o más de 10 dígitos
			return s;
		}
		if((y-48)==(m%11))
		{
			s=1;
			return s;
		}
		if(((m%11)==10)&&(y=='x'||y=='X'))
		{
			/*printf("checo\n");
			getch();*/
			s=1;
			return s;
		}
		if(((m%11)!=10)&&(y=='x'||y=='X'))
		{
			s=2;
			return s;
		}
	}
	if(flag==2)//13 dígitos
	{
		//13 dígitos:12 dígitos, primero por 1, luego por 3, luego por 1... dígito de control: número que hay que sumar para dividir por 10
		do
		{
			y=aux1->a;
			aux1=aux1->sig;
			if(y>'9'||y<'0'&&y!='-')
			{
				s=2;
				return s;
			}
			if(y<='9'&&y>='0'&&i<=13)
			{
				if(i<13)
				{
					h=y-48;
					if((i%2)==0)
						h=h*3;
					if((i%2)==1)
						h=h;
					m+=h;}
				i++;
			}
		}while(aux1!=NULL);
		if(i!=14)
		{	s=2;//2:inválido, menos o más de 13 dígitos
			return s;
		}
		if((10-(m%10))==(y-48))
		{
			s=1;
			return s;
		}
	}
}
void imprime_lista(lista head)
{
	lista aux;
	aux=head;
	do{
		printf("%c\t",aux->a);
		aux=aux->sig;
	}while(aux!=NULL);
}
void crear_lista(lista head)
{
	lista aux1,aux2;
	char y;
	aux1=head;
	do{
		y=getche();
		fflush(stdin);
		if(y!=13)
		{	aux2=crear(y);
			aux1->sig=aux2;
			aux1=aux2;}
	}while(y!=13);
}
lista crear(char y)
{
	lista nodo;
	nodo=(lista)malloc(sizeof(struct caracteres));
	if(nodo==NULL)
	{
		printf("\nError de asignacion de memoria, pulse una tecla para continuar");
		getch();
		exit(1);
	}
	nodo->a=y;
	nodo->sig=NULL;
	return nodo;
}
