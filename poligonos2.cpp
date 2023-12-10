#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
#define pi 3.14159265
/*drawpoly(vertices,polipoints) donde vertices es el numero de vertices de un poligono mas 1
y polipoints es un arreglo de enteros que tiene las coordenadas de los vertices de cada punto*/
//Triangulo que se inscribe en una circunferencia de radio 200
//NUEVA VERSION
//Programa que dibuja traingulos, cuadrados, pentagonos ya si hasta una figura de 20 lados, de regreso se va a dibujar la figura de 20 lados, y despues la de 19, la de 18 y así hasta dibujar una de 3
/*int main ()
{	
	int T[42],b=3,x,k=0,i,flag=0; //8 vertices va a tener un triangulo
	float rad,a=0;
	srand(time(NULL));
	initwindow(800,600);
	do{
		a=360.0/b;
		k=0;
		for (i=0;i<2*b+2;i=i+2)
		{	
			rad=a*k*pi/180.0;
			k++;
			T[i]=(int)(400+200*cos(rad));//400 es la mitad de x=800
			T[i+1]=(int)(300+200*sin(rad));//300 es la mitad de y=300
		}
		setcolor(COLOR(rand()%255,rand()%255,rand()%255));
		drawpoly(b+1,T);
		delay(500);
		setcolor(0);
		drawpoly(b+1,T);
		if(flag==1)
			b++;
		if(b==20)
			flag=-1;
		if(flag==-1)
			b--;
		if(b==3)
			flag=1;
	}while(!kbhit());	
	getch();
	closegraph(); 
	return 0;
}*/
//Programa que dibuja traingulos, cuadrados, pentagonos ya si hasta una figura de 20 lados con un ángulo de giro dado por teclado
int main ()
{	
	int T[42],b=3,x,k=0,i,flag=1,angulo,c; //8 vertices va a tener un triangulo
	float rad,a=0;
	printf("Escribe el angulo de giro: ");
	scanf("%i",&angulo);
	srand(time(NULL));
	initwindow(800,600);
	do{	
		for(c=1;c<360/angulo;c++)
		{
			a=360.0/b;//b+c*angulo;
			k=0;
			for (i=0;i<(2*b+2);i=i+2)
			{	
				rad=(a*k*pi/180.0)-(angulo*c*pi/180);
				k++;
				T[i]=(int)(400+200*cos(rad));//400 es la mitad de x=800
				T[i+1]=(int)(300+200*sin(rad));//300 es la mitad de y=300
			}
			setcolor(COLOR(rand()%255,rand()%255,rand()%255));
			drawpoly(b+1,T);
			delay(500);
			setcolor(0);
			drawpoly(b+1,T);	
		}
		getch;
	/*	b++;
		if(b==20)
			b=3;*/
		if(flag==1)
			b++;
		if(b==20)
			flag=-1;
		if(flag==-1)
			b--;
		if(b==3)
			flag=1;
	}while(!kbhit());	
	getch();
	closegraph(); 
	return 0;
}
