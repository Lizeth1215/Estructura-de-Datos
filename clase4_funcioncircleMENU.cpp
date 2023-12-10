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
/*circle(x,y,radio); donde(x,y) es el centro y x,y,radio son numeros enteros*/
struct coordenadas
{
	int x,y;
};
/*Graficar circunferencias dados dos puntos*/
void Menu(void);
struct coordenadas mouse ();
int Validacir (int x,int y,int r,struct coordenadas R);
int main ()
{
	struct coordenadas C,R,P;
	srand(time(NULL));
	initwindow(1000,1000);
/*	C=mouse();
	R=mouse();
	circle(C.x,C.y,(int)sqrt(((C.x-R.x)*(C.x-R.x))+((C.y-R.y)*(C.y,R.y))));*/
	//HACER MENU
/*	bar(0,0,100,1000);//rectangulo que encierra al menu
	line(100,0,100,1000);
	setcolor(0);
	circle(50,160,40);//Circulo
	setfillstyle(1,0);
	bar(10,340,90,400);//barras bar(10,470,90,510)
	setcolor(0);
	circle(50,580,40);//salir circle(50,890,40)
	setcolor(15);
	outtextxy(20,18,"Dubuja");
	outtextxy(18,152,"Circulo");
	outtextxy(22,365,"Barras");
	outtextxy(25,570,"Salir");*/
	Menu();
/*	R=mouse();
	if(Validacir(50,160,40,R)==1)
	{
		outtextxy(200,200,"ADENTRO");
	}/*
/*	P.x=50;
	P.y=160;
	Validacirc(P,40,R);*/
	do
	{
		P=mouse();
		while(Validacir(50,160,40,P)==1)
		{
			C=mouse();	
			if(C.x<100)
			{
				P=C;
				break;	
			}
			R=mouse();
			setcolor(COLOR(rand()%255,rand()%255,rand()%255));
			circle(C.x,C.y,(int)sqrt(((C.x-R.x)*(C.x-R.x))+((C.y-R.y)*(C.y,R.y))));		
		}	
		while(P.x>10&&P.x<90&&P.y>340&&P.y<400)
		{
			C=mouse();	
			if(C.x<100)
			{
				P=C;
				break;	
			}
			R=mouse();
			setfillstyle(1,3);
			bar(C.x,C.y,R.x,R.y);
		}	
	}while(Validacir(50,580,40,P)!=1);

//	getch();
	closegraph(); 
	return 0;
}
void Menu(void)
{
	setfillstyle(1,0);
	bar(0,0,100,1000);//rectangulo que encierra al menu
	line(100,0,100,1000);
	setcolor(15);
	circle(50,160,40);//Circulo
	setfillstyle(1,0);
	setfillstyle(1,15);
	bar(10,340,90,400);//barras bar(10,470,90,510)
	setcolor(15);
	circle(50,580,40);//salir circle(50,890,40)
	setcolor(15);
	outtextxy(20,18,"Dubuja");
	outtextxy(18,152,"Circulo");
	outtextxy(22,365,"Barras");
	outtextxy(25,570,"Salir");	
}
int Validacir (int x,int y,int r,struct coordenadas R)
{
	int i=0;
	if(r>(int)sqrt(((x-R.x)*(x-R.x))+((y-R.y)*(y,R.y))))
		i=1;
	return i;
}
struct coordenadas mouse ()
{
	struct coordenadas M;
	clearmouseclick(WM_LBUTTONDOWN);
	while(!ismouseclick(WM_LBUTTONDOWN))
		delay(50);
	getmouseclick(WM_LBUTTONDOWN,M.x,M.y);
	return M;
}
