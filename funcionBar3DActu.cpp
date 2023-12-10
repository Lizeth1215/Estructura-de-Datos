#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <winbgim.h>
#include <time.h>
/*Programa que dibuja barras con forme se da un porcentaje por teclado*/

int main(void)
{
	int i,j,K[5],m,h;
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
	
	//bar3d(500,300,700,500,50,1);
	//line(100,100,100,700);//eye y
	//line(100,700,1100,700);
	
	line(100,100,100,600);//eje y
	line(100,600,700,600);//eje x
	
	srand(time(NULL));
	for(i=0;i<6;i++)//lineas chiuitas del eje x
	{
		line(100+100*i,595,100+100*i,605);
		itoa(i,A,10);
		strcat(A," ");
		outtextxy(i*100+100,610,A);
	}
	for(j=0;j<5;j++)//lineas chiquitas del eje y
	{
		line(95,100+125*j,105,100+125*j);
		itoa(j*25,B,10);
		strcat(B," %");
		outtextxy(55,600-j*125,B);
	}
	
/*	for(i=1;i<6;i++)//eje x 300+200+...
	{
		line(i*200,700,i*200,708);
		itoa(i,A,10);
		strcat(A," ");
		outtextxy(i*200,708,A);
	}
	
	for(j=1;j<5;j++)//eje y 100+150+...
	{
		line(100,100+150*j,92,100+150*j);
		itoa(j*25,B,10);
		strcat(B," %");
		outtextxy(55,700-j*150,B);
	}*/
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
		//K[m]=rand()%600+100;
		//y=-6*K[m]-500;
		bar3d(130+100*m,600,160+100*m,-5*K[m]+600,50,1);
	}
	
	//k=rand()%600+100;
	//bar3d(225,700,375,k,50,1);
	
	getch();
	closegraph();
	return 0;
}
