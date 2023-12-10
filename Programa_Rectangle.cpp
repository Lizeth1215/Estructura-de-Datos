#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
#define pi 3.141517
//rectangle(x1,y1,x2,y2); Solo dibuja el contorno
int main (void)
{
	int i,m=-11;
	initwindow(1200,600);
	setcolor(5);
	rectangle(50,50,400,300);
	setfillstyle(9,7);//asi voy a rellenar unrectangulo
	floodfill(70,70,5);//esta sirve para rellenar el rectangulo
//ese punto(101,101) tiene que estar dentro del rectangulo
//para que se rellene el rectangulo debo de escribir el mismo color que en el setcolor
//porque si no encuentra el color se desborda
	
	getch();
	closegraph(); 
	return 0;
}
