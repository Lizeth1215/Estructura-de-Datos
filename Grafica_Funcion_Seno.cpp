#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
#define pi 3.141517
//GRAFICAR EN EL PLANO CARTESIANO LA FUNCION SENO	
//CON QUE? CON PITPIXEL();
int main (void)
{
	int i,m=-11;
	float r;
	char C[5];
	initwindow(1200,600);
	line(600,50,600,550);//eje y
	line(50,300,1150,300);//eje x
	for(i=1;i<=23;i++)//rayitas chiquitas eje x
	{
		line(50*i,295,50*i,305);
		if(50*i!=600)
		{
			itoa(m,C,10);
			outtextxy(50*i-4,320,C);
		}
		m++;
	}
	m=5;
	for(i=1;i<=11;i++)//rayitas chiquitas eje y
	{
		line(595,i*50,605,50*i);
		if(50*i!=300)
		{
			itoa(m,C,10);
			outtextxy(570,50*i-4,C);
		}
		m--;
	}
	for(i=0;i<=360;i++)//(i=0;i<=360;i++)
	{
		r=(i*pi)/180.0;
		putpixel(600+(int)(r*50),(int)(300-sin(r)*50),1);	
	}
	
	getch();
	closegraph(); 
	return 0;
}
