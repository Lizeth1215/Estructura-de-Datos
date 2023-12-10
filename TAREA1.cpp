#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <winbgim.h>
#include <time.h>
//TAREA 1
/*Programa que dibuja barras con forme se da un porcentaje por teclado*/

int main(void)
{
	srand(time(NULL));
	int i,j,K[5],m,h,X[10],s;
	float y;
	char A[8],B[8];
	
	/*bar3d(x1,y1,x2,y2,p,top); x1,y1 y x2,y2 son las esquinas opuestas de una region rectangular 
	p es la profundidad de la barra y top es un valor boleano que indica si se dibuja el techo o no (0 o 1)*/
	
	//line(x1,y1,x2,y2); dibuja segmento de recta entre dos puntos
	
	for(i=0;i<5;i++)
	{
		printf("Ingrese el porcentaje %i/5: ",i+1);
		scanf("%i",&K[i]);
	}
	initwindow(800,600);//(1400,800);
	line(100,100,100,600);//eje y
	line(100,600,700,600);//eje x
	for(i=0;i<6;i++)//lineas chiuitas del eje x
	{
		line(100+100*i,595,100+100*i,605);
		itoa(i,A,10);
		strcat(A," ");
		outtextxy(i*100+100,610,A);
	}
	for(j=0;j<5;j++)//lineas chiquitas del eje y
	{
		srand(time(NULL));
		X[j]=(rand()%1000)/4;
		line(95,100+125*j,105,100+125*j);
		itoa(X[j]*j,B,10);//con esto aseguro que los numeros aleatorios que genere se impriman en pantalla en forma ascendente, empezando por 0
		strcat(B," %");
		outtextxy(40,600-j*125,B);
	}
	for(s=0;s<4;s++) //el numero que se imprime es el segundo, el que le sigue al cero
	{
		printf("\nlos numeros aleatorios son %i", X[s]);
	}
	/* operacion necesaria
		% = x 	pixeles=y
		0% = 	600 (700)
		K[i] = 	?
		100% = 	100
		y-100=(-5)(x-100)
		y-100=-5x+500
		y=-5x+600
	*/
	for(m=0;m<5;m++)//barras
	{
		setcolor(COLOR(rand(),rand(),rand()));
		setfillstyle(m+1,m+2);
		bar3d(130+100*m,600,160+100*m,((-5*K[m])/10)+600,50,1);
	}
	getch();
	closegraph();
	return 0;
}
