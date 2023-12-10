#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<winbgim.h>

int main (void)
{
	int medida,s;
	void *p;//tipo apuntador
	srand(time(NULL));
	
	initwindow(1200,600);
	
	/*OVNI PRESTADO
	rectangle(200,200,300,300);
	setcolor(1);
	ellipse(250,260,0,360,40,15);
	setfillstyle(1,7);
	floodfill(250,261,1);
	arc(250,249,0,180,22);
	setfillstyle(1,4);
	floodfill(250,235,1);
	line(250,227,250,218);
	circle(250,212,7);
	setfillstyle(1,2);
	floodfill(250,207,1);*/
	
//setcolor(15);
	rectangle(300,230,400,330);
	setcolor(1);//COLOR(20,1,254)
	ellipse(350,272,-2,180,12,10);
	setfillstyle(1,7);//asi voy a rellenar un rectangulo 7=gris
	floodfill(350,250,1);//rellenar rectangulo
	ellipse(350,281,5,360,30,10);
	setfillstyle(1,1);//asi voy a rellenar un rectangulo
	//floodfill(351,287,1);
	

	circle(351,287,2);
	setfillstyle(1,4);
	floodfill(351,287,1);
	circle(365,285,2);
//	setfillstyle(1,4);
	floodfill(365,285,1);
	circle(336,287,2);
	//setfillstyle(1,4);
	floodfill(336,287,1);
	circle(323,281,2);
//	setfillstyle(1,4);
	floodfill(323,281,1);
	circle(377,281,2);
//	setfillstyle(1,4);
	floodfill(377,281,1);
	
	medida=imagesize(300,230,400,330);; //numero de bites que se requieren para calcular una region rectangular en memoria
	p=malloc(medida); //Reserva de memoria permanente (durante el uso del programa)
	getimage(300,230,400,330,p);; //Lee la region y guarda los datos en el espacio reservado
	
	//putimage(600,300,p,0); //coordenadas de nueva posicion
	
	/*for(s=0;s<500;s+=10)
	{
		setcolor(COLOR(rand()%255,rand()%255,rand()%255));
		rectangle(600-s,300-s,600+s,300+s);
	}*/
	
	putimage(1000,300,p,0);

	getch();
	closegraph();
	return 0;
}
