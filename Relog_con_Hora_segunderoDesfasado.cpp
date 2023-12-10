//	PROGRAMA INCOMPLETO DE LA CLASE VIRTUAL DEL LUNES 14 DE FEBRERO
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
	int a,b,i,flag=0,rd=100,gn=100,bl=100;
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
	/*do
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
		setl<inestyle(1,0,5);
		setcolor(15);
		outtextxy(350,350,A);
		delay(50);
		setcolor(0);
	}while(!kbhit());*/
	
/*	sen (t)=co/h
	cos (t)=ca/h
	co=sen(t)*h
	y=sen(t)*h+350
	ca=cos(t)*h	
	x=cos(t)+h+350
	200 es el radio*/
	
	setcolor(15);
	circle(350,350,200);
	i=0;
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
		settextstyle(3,0,3);
		setcolor(15);
		outtextxy(100,100,A);
		setcolor(COLOR(rd,gn,bl));
		//delay(50);
		if(!kbhit()&&flag==0)
		{
			if(a*i==360)
			{
				rd=rand()%255;
				gn=rand()%255;
				bl=rand()%255;
				//setcolor(COLOR(rand()%255,rand()%255,rand()%255));
				i=0;
			}
			r=(a*i*pi)/180.0;
			moveto(350,350);
			//setcolor(COLOR(rand()%255,rand()%255,rand()%255));
			lineto((int)(cos(r)*200)+350,(int)(350-sin(r)*200));//tambien se puede hacer con linerel o simplemnete line
			delay(100);
			i++;
		}	
		if(kbhit())
		{
			flag=1;
			clearviewport();//limpia la pantalla
			i=0;
			getch();//se lleva la tecla guardada en kbhit
		}
		if(flag==1)
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
		}
		setcolor(0);
		outtextxy(20,20,A);
	}while(!kbhit());

	//getch();
	closegraph(); 
	return 0;
}


