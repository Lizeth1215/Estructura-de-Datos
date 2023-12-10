//istograma
//Programa que dibuja el plano cartesiano
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
/*bar3d(x1,y1,x2,y2,p,top); (x1,y1) y (x2,y2) son las esquinas opuestas de una region rectangular, 
p es la profundidad de la barra y top es un valor boleano que indica si se dibuja el techo o no*/
/*line(x1,y1,x2,y2); dibuja un segmento de recta entre ese par de puntos*/
int main (void)
{
	int i,j;
	char A[8],B[8];
	initwindow(1400, 800); 
//	bar3d(500,300,700,500,500,1);//solo puede ser 0 o 1
	line(100,100,100,600);//eje y
	line(100,600,700,600);//eje x
	for(i=0;i<5;i++)//lineas chiuitas del eje x
	{
		line(100+125*i,595,100+125*i,605);
	}
	for(j=0;j<4;j++)//lineas chiquitas del eje y
	{
		line(95,100+125*j,105,100+125*j);
	}

	getch();
	closegraph(); 
	return 0;
}

