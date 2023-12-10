#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
#define pi 3.14159265
//Programa que dibuja un planeta con putpixel y hace que gire al rededor de una orbita
struct Puntos
{
	int M[9][9];
};
//putpixel(x,y,color); dibuja un pixel en la pantalla de color COLOR
void MoverNombre (int x, int y);
struct Puntos Nombre(void);
int main ()
{
	initwindow(800,600);
	MoverNombre(100,100);
	//delay(10);
	
	getch();
	closegraph(); 
	return 0;
}
void MoverNombre (int x, int y)
{
	int i,j,r,g,b,k;
	struct Puntos T;
	srand(time(NULL));
	T=Nombre();
	k=0;
	do
	{
		for(i=0;i<9;i++)
		{
			//for(j=k;j<(41+k)%81;j++)
			for(j=0;j<8;j++)
			{
				switch(T.M[i][j+k])
				{	
				case 1://color rosa mexicano
						r=255;
						g=0;
						b=0;
						break;		
				case 2://color blanco
						r=255;
						g=255;
						b=128;
						break;
				}
				putpixel(x+j,y+i,COLOR(r,g,b));
			}
		}	
		delay(10);
		k++;
	}while(k<8);	
}
struct Puntos Nombre(void)
{					
	struct Puntos T;
	int j,i,P[9][9]={{0,0,0,0,0,0,0,0},
				     {0,0,1,0,0,1,0,0},
				     {0,0,1,0,0,1,0,0},
				     {0,0,1,1,1,1,0,0},
				     {0,0,1,0,0,1,0,0},
				     {0,0,1,0,0,1,0,0},
				     {0,0,1,0,0,1,0,0},
				     {0,0,0,0,0,0,0,0}
					 };
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			T.M[i][j]=P[i][j];
		}
	}
	return T;
}


