#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
/*Programa que dibuja circulos  hasta llegar al limite de la pantalla superior*/

/*bar3d(x1,y1,x2,y2,p,top); (x1,y1) y (x2,y2) son las esquinas opuestas de una region rectangular, 
p es la profundidad de la barra y top es un valor boleano que indica si se dibuja el techo o no*/
/*line(x1,y1,x2,y2); dibuja un segmento de recta entre ese par de puntos*/
/*circle(x,y,radio); donde(x,y) es el centro y x,y,radio son numeros enteros*/
int main (void)
{
	int s,j,band=1;
	srand(time(NULL));
	initwindow(1400, 800); 
//	circle(700,400,200);
	s=5;
/*	do{
		setcolor(j);
		circle(700,400,s);
		delay(100);
		j=0;
		setcolor(j);
		circle(700,400,s);
		s+=5;
		j=1;
		if(s==400)
			s=5;
		
	}while(!kbhit());*/
	
	/*setcolor(COLOR(rand()%255,rand()%255,rand()%255));
	do{
		circle(700,400,s);
		delay(100);
	//	circle(700,400,s);
		s+=5*band;
		if(s==400)
		{
			setcolor(0);
			band=-1;
		}
		if(s==0)
		{
			band=1;
			setcolor(COLOR(rand()%255,rand()%255,rand()%255));
		}
		
	}while(!kbhit());*/

	setcolor(COLOR(rand()%255,rand()%255,rand()%255));
	do{
		circle(700,400,s);
		delay(100);
	//	circle(700,400,s);
		s+=5*band;
		if(band==1)
		{
			setcolor(COLOR(rand()%255,rand()%255,rand()%255));
			if(s==400)
			{
				band=-1;
			}
		}
		if(band==-1)
		{
			setcolor(0);
			if(s==0)
			{
				band=1;
			}
		}
	
		
	}while(!kbhit());
	getch();
	closegraph(); 
	return 0;
}
