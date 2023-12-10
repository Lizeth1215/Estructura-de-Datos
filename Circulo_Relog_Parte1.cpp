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
	//moveto(350,350);
	//linerel(250,250);
	//lineto(350,350);
/*	sen (t)=co/h
	cos (t)=ca/h
	co=sen(t)*h
	y=sen(t)*h+350
	ca=cos(t)*h	
	x=cos(t)+h+350
	200 es el radio*/
//PROGRAMA QUE DIVIDE UN CIRCUOO EN Angulos dados por teclado y despues dibuja las manesillas de relog
int main (void)
{
	int a,b,i;
	char A[10],B[4];
	struct tm *timenow;//struct tm es un tipo de dato es un apuntador
	float r;
	srand(time(NULL));//para quen no comience en la misma semilla
	printf("introduce el angulo de desplazamiento:");
	scanf("%i",&a);
	initwindow(700, 700);
	
	setcolor(15); 
	circle(350,350,200);
	i=0;
	do
	{
		if(a*i==360)
		{
			setcolor(COLOR(rand()%255,rand()%255,rand()%255));
			i=0;
		}
		r=(a*i*pi)/180.0;
		moveto(350,350);
		//setcolor(COLOR(rand()%255,rand()%255,rand()%255));
		lineto((int)(cos(r)*200)+350,(int)(350-sin(r)*200));//tambien se puede hacer con linerel o simplemnete line
		delay(100);
		i++;
		
	}while(!kbhit());
	getch();//se lleva la tecla guardada en kbhit
	clearviewport();//limpia la pantalla
	
	i=0;
	do
	{
		setcolor(10);
		r=(a*i*pi)/180.0;
		moveto(350,350);
		lineto((int)(cos(r)*200)+350,(int)(350-sin(r)*200));//tambien se puede hacer con linerel o simplemnete line
		delay(100);
		setcolor(0);
		moveto(350,350);
		lineto((int)(cos(r)*200)+350,(int)(350-sin(r)*200));
		i++;		
	}while(!kbhit());
	getch();
	closegraph(); 
	return 0;
}
