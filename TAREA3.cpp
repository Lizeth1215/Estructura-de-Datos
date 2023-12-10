#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<math.h>
#include<time.h>
#include<winbgim.h>
struct coordenadas
{
	int x,y;
};
struct coordenadas mouse (void);
int ValidCir (int x, int y, int r,struct coordenadas R);
void menu (void);
int main (void)
{
	struct coordenadas C,R,P;
	initwindow(1000,1000);
	menu();
	do
	{
		P=mouse();	
		while(ValidCir(50,160,40,P)==1)//circle(50,160,40);
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
				menu();			
		}
		while(P.x>10&&P.x<90&&P.y>340&&P.y<400) //bar(10,340,90,400);
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
			menu();
		}	
	}while(ValidCir(50,580,40,P)!=1);//circle(50,580,40);
	closegraph();
	return 0;
}

void menu (void)
{	
	setfillstyle(1,0);
	bar(0,0,100,1000);//rectangulo que encierra al menu
	setcolor(15);
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
int ValidCir (int x, int y, int r,struct coordenadas R)
{
	int i=0;
	if(r>(int)sqrt(((x-R.x)*(x-R.x))+((y-R.y)*(y-R.y))))
		i=1;
	return i;
}
struct coordenadas mouse (void)
{
	struct coordenadas M;
	clearmouseclick(WM_LBUTTONDOWN);
	while(!ismouseclick(WM_LBUTTONDOWN))
		delay(50);
	getmouseclick(WM_LBUTTONDOWN,M.x,M.y);
	return M;
}
