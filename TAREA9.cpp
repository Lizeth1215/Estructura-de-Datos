#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
#define pi 3.1415

//PROGRAMA QUE DIBUJE EN PANTALLA EL SEGUNDERO
int main (void)
{
	int a,b,i,flag=0;
	char A[10],B[4];
	struct tm *timenow;//struct tm es un tipo de dato es un apuntador
	float r;
	
	time_t T;//Vamos a jalar la hora del rejog, tipo de dato que viene definido en la libreria time
//	time(&T);//el amperson pide la direccion de la variable T para guardar algo ahi
//	timenow=localtime(&T);
	//printf("La hora de tu sistema es: %i:%i:%i",timenow->tm_hour,timenow->tm_min,timenow->tm_sec);
	//getch();
	
	srand(time(NULL));//para quen no comience en la misma semilla
	printf("introduce el angulo de desplazamiento:");
	scanf("%i",&a);
	initwindow(700, 700);
//	setcolor(15);
	i=0;
	do
	{
		time(&T);//Estas instrucciones deben por fuerza estara dentro para que el segundero vaya cambiando
		timenow=localtime(&T);//esta tambien
		itoa(timenow->tm_hour,A,10);//convertir el numero a una cadena para poder mostrarlo en la pantalla grafica
		strcat(A,":");
		itoa(timenow->tm_min,B,10);
		strcat(A,B);//concatena dos cadenas
		strcat(A,":");
		itoa(timenow->tm_sec,B,10);
		strcat(A,B);
		settextstyle(3,0,3);//cambia el tamaño, estilo y trama del modo grafico
		setcolor(15);
		outtextxy(100,100,A);
		//delay(50);
		//setcolor(0);
		//outtextxy(100,100,A);	
	
		if(flag==0)
		{
			setcolor(15);//blanco
			circle(350,350,200);
			setcolor(10);
			r=(a*i*pi)/180.0;
			moveto(350,350);
			lineto((int)(+cos(r)*200)+350,(int)(350+sin(r)*200));//tambien se puede hacer con linerel o simplemnete line
			delay(100);
			i++;	
			i=0;
			flag=1;
		}
		if(flag==1)
		{
			setcolor(10);//verde manzana
			r=(a*i*pi)/180.0;
			moveto(350,350);
			lineto((int)(cos(r)*200)+350,(int)(350+sin(r)*200));//tambien se puede hacer con linerel o simplemnete line
			delay(100);
			setcolor(0);//negro borra las demas lineas
			moveto(350,350);
			lineto((int)(cos(r)*200)+350,(int)(350+sin(r)*200));
			i++;	
		}
	}while(!kbhit());
	//getch();
	closegraph(); 
	return 0;
}
