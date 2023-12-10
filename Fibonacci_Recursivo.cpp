//tarea:Imprimir n terminos de la sere de fibonaci en recursivo
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
#include<iostream>
int Fibonacii(int n);
int main(void)
{
	int a,b,f=1,i,n;
	printf("Ingrese el termino n de la serie de Fibonaci: ");
	scanf("%i",&a);
	f=Fibonacii(a);
	printf("\n La serie fibonacii del termino %i  es: %i",a,f);
	
	getch();
	return 0;
}
int Fibonacii(int a)
{
	if(a==0)
		return 0;
	if(a==1)
		return 1;
	else
		return (Fibonacii(a-1)+Fibonacii(a-2));
}
