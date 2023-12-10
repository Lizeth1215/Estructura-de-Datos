#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
//APUNTADORES
//Tarea: Resolver la cuadratica estrictamente con pase de referencia
//los arreglos por si solos son apuntadores
void calculo(float *pa, float *pb, float *pc, float *x1, float *x2, float *flag);
void imprime(float *pa, float *pb, float *pc, float *x1, float *x2, float *flag);
void coeficientes(char A[30], int *px);
int main(void)
{
//	int *px;
	int A[30];
	float x1,x2,pa,pb,pc,flag;
	//coeficientes(A,px);//sin asterisco es direccion
	printf("Ingrese el termino cuadratico (es distinto de cero): ");
	scanf("%i",&pa);
	printf("Ingrese el termino lineal: ");
	scanf("%i",&pb);
	printf("Ingrese el termino independiente: ");
	scanf("%i",&pc);
	//pintf("%f",pa);
	calculo(&pa,&pb,&pc,&x1,&x2,&flag);
	imprime(&pa,&pb,&pc,&x1,&x2,&flag);
	
	getch();
	return 0;
}
void coeficientes(char A[30], int *px)//esta funcion se va a mandar llamar 3 veces, una para a, b y c
{
	int a,b,c;
	printf("Ingrese el termino cuadratico (es distinto de cero): ");
	scanf("%i",&A[0]);
	printf("Ingrese el termino lineal: ");
	scanf("%i",&A[1]);
	printf("Ingrese el termino independiente: ");
	scanf("%i",&A[2]);
}
void calculo(float *pa, float *pb, float *pc, float *x1, float *x2, float *flag)//apuntador a a -> *pa //flag me sirve para decir si es solucion imaginarika o real
{
//	float *flag=0;
	float a;
	a=(float)((*pb**pb)-4**pa**pc);
	printf("\n El discriminante es: %f ",a);
	if((*pb**pb)-4**pa**pc >=0)
	{
		*flag=1;
	}
	if(*flag==1)
	{
		printf("Las raices son reales");
		*x1=(float)((-1**pb+sqrt((*pb**pb)-4**pa**pc))/(2**pa));
		*x2=(float)((-1**pb-sqrt((*pb**pb)-4**pa**pc))/(2**pa));
	}
	else
		printf("\n Las raices son complejas");
}
void imprime(float *pa, float *pb, float *pc, float *x1, float *x2, float *flag)
{
	if(*flag==1)
	{
		printf("\nLas raices son:\t\t x_1 = %f   y   x_2 = %f  ",*x1,*x2);
	}
	else
		printf("\n---Intenta con otros coeficientes---");
}
