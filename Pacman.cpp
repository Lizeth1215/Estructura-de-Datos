#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
#define pi 3.1415
/*HASTA AQUI SE DIBUJA EL PACMAN ABRIENDO Y CERRANDO LA BOCA
	do
	{
		if(flag==0)
		{
			setfillstyle(1,15);
			pieslice(350,350,i,360-i,100);//así se dibuja el pacman
			//voy a ocupar banderas para hacer la animacion de que el pacman abre y cierra la boca		
		}
		//delay(100);
		setfillstyle(1,0);//trama y color
		pieslice(350,350,360-i,i,100);
		setcolor(0);
		arc(350,350,360-i,i,100);
		delay(100);
		if(i<45)
			i+=5;
		else
			i=1;//si i=0 se pinta el circulo completo de negro, entonces si i=1, no va a cerrar totalmente la boca y por eos ya nova a parpadear
		
	}while(!kbhit());*/
	/*pieslice(x,y,ang1,ang2,radio);*/
/*int main (void)
{
	int i=0,flag=1,d=0,y=0;
	char t;
	initwindow(700,700);
	//pieslice(100,100,0,360,100);//circulo completo
	//pieslice(100,100,360,0,100);//circulo completo
	//pieslice(350,350,0,45,100);
	//Vamos a programar el pacman, los grados para dibujar el pacman son 45 y 135
	do
	{
		if(flag==0)
		{
			setfillstyle(1,14);
			pieslice(350+d,350+y,i,360-i,100);//así se dibuja el pacman
			//voy a ocupar banderas para hacer la animacion de que el pacman abre y cierra la boca		
			//delay(100);
			setfillstyle(1,0);//trama y color
			pieslice(350+d,350+y,360-i,i,100);
			setcolor(0);
			arc(350+d,350+y,360-i,i,100);
			delay(100);
			if(i<45)
				i+=5;
			else
				i=1;//si i=0 se pinta el circulo completo de negro, entonces si i=1, no va a cerrar totalmente la boca y por eos ya nova a parpadear
		}
		if(flag==1)//con esto se mueve la cabeza hacia la izquierda
		{
			setfillstyle(1,14);
			pieslice(350+d,350+y,i-180,360-i-180,100);//así se dibuja el pacman
			//voy a ocupar banderas para hacer la animacion de que el pacman abre y cierra la boca		
			//delay(100);
			setfillstyle(1,0);//trama y color
			pieslice(350+d,350+y,360-i-180,i-180,100);
			setcolor(0);
			arc(350+d,350+y,i-180,i,100);
			delay(100);
			if(i<45)
				i+=5;
			else
				i=1;//si i=0 se pinta el circulo completo de negro, entonces si i=1, no va a cerrar totalmente la boca y por eos ya nova a parpadear
		}
		if(flag==2)//con esto se mueve la cabeza hacia la izquierda
		{
			setfillstyle(1,14);
			pieslice(350+d,350+y,i-270,360-i-270,100);//así se dibuja el pacman
			//voy a ocupar banderas para hacer la animacion de que el pacman abre y cierra la boca		
			//delay(100);
			setfillstyle(1,0);//trama y color
			pieslice(350+d,350+y,360-i-270,i-270,100);
			setcolor(0);
			arc(350+d,350+y,i-270,i,100);
			delay(100);
			if(i<45)
				i+=5;
			else
				i=1;//si i=0 se pinta el circulo completo de negro, entonces si i=1, no va a cerrar totalmente la boca y por eos ya nova a parpadear
		}
		if(flag==3)//con esto se mueve la cabeza hacia la izquierda
		{
			setfillstyle(1,14);
			pieslice(350+d,350+y,i-90,360-i-90,100);//así se dibuja el pacman
			//voy a ocupar banderas para hacer la animacion de que el pacman abre y cierra la boca		
			//delay(100);
			setfillstyle(1,0);//trama y color
			pieslice(350+d,350+y,360-i-90,i-90,100);
			setcolor(0);
			arc(350+d,350+y,i-90,i,100);
			delay(100);
			if(i<45)
				i+=5;
			else
				i=1;//si i=0 se pinta el circulo completo de negro, entonces si i=1, no va a cerrar totalmente la boca y por eos ya nova a parpadear
		}
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
					if(d<=238)//400 y su pantalla x=1000
						d+=5;
					setfillstyle(1,0);
					pieslice(350+d-5,350+y,360,0,100);
				}
				if(t==75)//aqui va amoverse hacia la izquierda
				{
					if(d>=-238)
						d-=5;
					flag=1;
					setfillstyle(1,0);
					pieslice(350+d+5,350+y,360,0,100);
				}
				if(t==72)//aqui va amoverse hacia arriba
				{	
					flag=2;
					if(y>=-238)	
						y-=5;
					setfillstyle(1,0);
					pieslice(350+d,350+y+5,360,0,100);
				}
				if(t==80)//aqui va amoverse hacia abajo
				{	
					flag=3;
					if(y<=230)	
						y+=5;
					setfillstyle(1,0);
					pieslice(350+d,350+y-5,360,0,100);
				}
			}
			//aqui voy a borrar el rastro que va dejando
			//setfillstyle(1,0);
			//pieslice(350+d-5,350,360,0,100);
			//pieslice(350+d+5,350,360,0,100);			
		}
	}while(!kbhit());

	getch();
	closegraph(); 
	return 0;
}*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
#define pi 3.1415
//PACMAN MEJORADO
int main (void)
{
	int i=0,flag=0,d=0,y=0;
	char t;
	initwindow(1200,600);//(700,700)
	/*Vamos a programar el pacman, los grados para dibujar el pacman son 45 y 135*/
	do
	{
		if(flag==0)//la boca apunta a la derecha
		{
			setfillstyle(1,14);
			pieslice(600+d,300+y,i,360-i,60);//así se dibuja el pacman. voy a ocupar banderas para hacer la animacion de que el pacman abre y cierra la boca		
			setfillstyle(1,0);//trama y color
			pieslice(600+d,300+y,360-i,i,60);
			setcolor(0);
			arc(600+d,300+y,360-i,i,60);
			delay(100);
			if(i<45)
				i+=5;
			else
				i=1;//si i=0 se pinta el circulo completo de negro, entonces si i=1, no va a cerrar totalmente la boca y por eos ya nova a parpadear
		}
		if(flag==1)//con esto se mueve la cabeza hacia la izquierda
		{
			setfillstyle(1,14);
			pieslice(600+d,300+y,i-180,360-i-180,60);//así se dibuja el pacman
			setfillstyle(1,0);//trama y color
			pieslice(600+d,300+y,360-i-180,i-180,60);
			setcolor(0);
			arc(600+d,300+y,i-180,i,60);
			delay(100);
			if(i<45)
				i+=5;
			else
				i=1;//si i=0 se pinta el circulo completo de negro, entonces si i=1, no va a cerrar totalmente la boca y por eos ya nova a parpadear
		}
		if(flag==2)//con esto la boca apunta hacia arriba
		{
			setfillstyle(1,14);
			pieslice(600+d,300+y,i-270,360-i-270,60);//así se dibuja el pacman
			setfillstyle(1,0);//trama y color
			pieslice(600+d,300+y,360-i-270,i-270,60);
			setcolor(0);
			arc(600+d,300+y,i-270,i,60);
			delay(100);
			if(i<45)
				i+=5;
			else
				i=1;//si i=0 se pinta el circulo completo de negro, entonces si i=1, no va a cerrar totalmente la boca y por eos ya nova a parpadear
		}
		if(flag==3)//con esto la boca apunta hacia abajo
		{
			setfillstyle(1,14);
			pieslice(600+d,300+y,i-90,360-i-90,60);//así se dibuja el pacman
			setfillstyle(1,0);//trama y color
			pieslice(600+d,300+y,360-i-90,i-90,60);
			setcolor(0);
			arc(600+d,300+y,i-90,i,60);
			delay(100);
			if(i<45)
				i+=5;
			else
				i=1;//si i=0 se pinta el circulo completo de negro, entonces si i=1, no va a cerrar totalmente la boca y por eos ya nova a parpadear
		}
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
	}while(!kbhit());
	getch();
	closegraph(); 
	return 0;
}
