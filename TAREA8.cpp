#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
#define pi 3.1415
//TAREA 8. PACMAN
//los circulos te dan una vida y los cuadrados te quitan una vida
void GanarVidas (void);
void PerderVidas (void);
int main (void)
{
	int i=0,flag=0,d=0,y=0,x,vida=4,v1=0,v2=0,v3=0,v4=0;
	char t;
	initwindow(1200,600);//(700,700)
	/*Vamos a programar el pacman, los grados para dibujar el pacman son 45 y 135*/
	GanarVidas();
	PerderVidas();
//	printf("%i",vida);
	do
	{
		setfillstyle(1,14);
		if(flag==0)//la boca apunta a la derecha
		{	
			pieslice(600+d,300+y,i,360-i,60);//así se dibuja el pacman. voy a ocupar banderas para hacer la animacion de que el pacman abre y cierra la boca		
			setfillstyle(1,0);
			pieslice(600+d,300+y,360-i,i,60);
			setcolor(0);
			arc(600+d,300+y,360-i,i,60);
		}
		if(flag==1)//con esto se mueve la cabeza hacia la izquierda
		{
			pieslice(600+d,300+y,i-180,360-i-180,60);
			setfillstyle(1,0);
			pieslice(600+d,300+y,360-i-180,i-180,60);
			setcolor(0);
			arc(600+d,300+y,i-180,i,60);
		}
		if(flag==2)//con esto la boca apunta hacia arriba
		{
			pieslice(600+d,300+y,i-270,360-i-270,60);
			setfillstyle(1,0);
			pieslice(600+d,300+y,360-i-270,i-270,60);
			setcolor(0);
			arc(600+d,300+y,i-270,i,60);
		}
		if(flag==3)//con esto la boca apunta hacia abajo
		{
			pieslice(600+d,300+y,i-90,360-i-90,60);
			setfillstyle(1,0);
			pieslice(600+d,300+y,360-i-90,i-90,60);
			setcolor(0);
			arc(600+d,300+y,i-90,i,60);
		}
		delay(100);
		if(i<45)
			i+=5;
		else	
			i=1;//si i=0 se pinta el circulo completo de negro, entonces si i=1, no va a cerrar totalmente la boca y por eos ya nova a parpadear
//con esta instruccion voy a comenzar a mover el pacman con la feclas (primeor a la derecha)
		if(kbhit())//si no se a apucharrado ninguna tecla no necesito leer esa tecla
		{
			t=getch();
			if(t<=0)
			{
				t=getch();
				if(t==77)//codigo ascii de la tecla de la fechita hacia la derecha
				{
					flag=0;
					if(d<=528)//400 y su pantalla x=1000
						d+=5;
				//	if(d==((x-80)*(x-80)+(y-50)*(y-50))<=225)//CHECAR
				//		GanarVidas();
				//		printf("hola");
					setfillstyle(1,0);//aqui voy a borrar el rastro que va dejando
					pieslice(600+d-5,300+y,360,0,60);
				}
				if(t==75)//aqui va amoverse hacia la izquierda
				{
					if(d>=-536)
						d-=5;
					flag=1;
					setfillstyle(1,0);//aqui voy a borrar el rastro que va dejando
					pieslice(600+d+5,300+y,360,0,60);
				}
				if(t==72)//aqui va amoverse hacia arriba
				{	
					flag=2;
					if(y>=-237)	
						y-=5;
					setfillstyle(1,0);//aqui voy a borrar el rastro que va dejando
					pieslice(600+d,300+y+5,360,0,60);
				}
				if(t==80)//aqui va amoverse hacia abajo
				{	
					flag=3;
					if(y<=227)	
						y+=5;
					setfillstyle(1,0);//aqui voy a borrar el rastro que va dejando
					pieslice(600+d,300+y-5,360,0,60);
				}
			}			
		}
		if(v1==0)//primera vida
		{
			if(sqrt((600+d-500)*(600+d-500)-(300+y-300)*(300+y-300))<60)
			{
				v1=1;
				vida=vida+1;
				printf("\nTengo %i vidas ",vida);
			}
		}
		if(v2==0)//vida 2
		{
			if(sqrt((600+d-80)*(600+d-80)-(300+y-50)*(300+y-50))<60)
			{
				v2=1;
				vida=vida+1;
				printf("\nTengo %i vidas ",vida);
			}
		}
		if(v3==0)//vida 2
		{
			if(sqrt((600+d-800)*(600+d-800)-(300+y-150)*(300+y-150))<60)
			{
				v3=1;
				vida=vida+1;
				printf("\nTengo %i vidas ",vida);
			}
		}
		if(v4==0)//vida 2
		{
			if(sqrt((600+d-30)*(600+d-30)-(300+y-500)*(300+y-500))<60)
			{
				v4=1;
				vida=vida+1;
				printf("\nTengo %i vidas ",vida);
			}
		}
		//lo mismo con los cuadritossss
			
		
	}while(!kbhit());
	
	
	getch();
	closegraph(); 
	return 0;
}
void GanarVidas (void)
{
	setcolor(7);
	circle(80,50,15);//ya
	circle(800,150,10);//ya
	circle(500,300,11);//ya
	circle(30,500,17);	//
	setfillstyle(1,5);
	floodfill(80,50,7);
	floodfill(800,150,7);
	floodfill(500,300,7);
	floodfill(30,500,7);
}
void PerderVidas (void)
{
	setcolor(15);
	rectangle(900,100,950,150);
	rectangle(1000,500,1100,550);
	rectangle(200,400,270,450);
	setfillstyle(1,3);
	floodfill(920,120,15);
	floodfill(1050,520,15);
	floodfill(220,420,15);
}
