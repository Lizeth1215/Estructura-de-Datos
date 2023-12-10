#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
#define pi 3.141517
/*arc(x,y,ang 1,ang 2,radio);*/
/*programa que va a pintar arcos hasta que presione una tecla*/
/*setlinestyle(estilo,trama,grosor); el primero de 0 a 4 y el ultimo de 1 a 3
	 setlinestyle(0,5,1); 
	 line(10,10,100,100);*/
/*linerel(dx,dy) donde dx y dy son los desplazamientos relativos en (x,y), hay desplazamientos positivos y negativos
moveto(x,y)moverse a una posicion especifica, mueve el apuntador grafico
lineto(x,y)*/

int main (void)
{
	int a,b,i;
	char A[10],B[4];
	struct tm *timenow;//struct tm es un tipo de dato es un apuntador
	float r;
	
	time_t T;//Vamos a jalar la hora del rejog, tipo de dato que viene definido en la libreria time
//	time(&T);//el amperson pide la direccion de la variable T para guardar algo ahi
//	timenow=localtime(&T);
	//printf("La hora de tu sistema es: %i:%i:%i",timenow->tm_hour,timenow->tm_min,timenow->tm_sec);
	//getch();
	
	srand(time(NULL));//para quen no comience en la misma semilla
	initwindow(700, 700);
	
	do
	{
		time(&T);//Estas instrucciones deben por fuerza estara dentro para que el segundero vaya cambiando
		timenow=localtime(&T);//esta tambien
		itoa(timenow->tm_hour,A,10);//convertir el numero a una cadena
		strcat(A,":");
		itoa(timenow->tm_min,B,10);
		strcat(A,B);//concatena dos cadenas
		strcat(A,":");
		itoa(timenow->tm_sec,B,10);
		strcat(A,B);
		settextstyle(1,0,5);
		setcolor(15);
		outtextxy(230,330,A);
		delay(50);
		setcolor(0);
		outtextxy(230,330,A);
	}while(!kbhit());
	
	getch();
	closegraph(); 
	return 0;
}

