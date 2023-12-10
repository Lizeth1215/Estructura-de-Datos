#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
//TAREA 2 los circulos deben ir en escala: rojos-verdes-azules-forma aleatoria-rojos-.... los colores deben incrementar en intensidad 
int main (void)
{
	int s,i,band=1,flag=0,a=1;
	srand(time(NULL)); //siempre que queira numeros o colores aleatorios debo poner esta instruccion
	initwindow(800, 500); 
	s=5;
	i=0;

	do{
		if(flag==0)//voy a pintar circulos de rojo
		{
				setcolor(COLOR(i+5,0,0));
				circle(400,250,s);
				delay(50);
				i+=5;
				s+=5;
				if(s==245)
			 		flag+=1;
		}
		if(flag==1) //con este if voy a borrar todos los circulos
		//los borro, es decir los pinto otra vez del ultimo al primero pintandolos de negro
		{
			setcolor(0);
			circle(400,250,s);
			delay(50);
			i-=5;
			s-=5;
			if(s<=0)
		 		flag+=1;
		}
		if(flag==2) //los voy a pintar de verde
		{
			setcolor(COLOR(0,i+5,0));
			circle(400,250,s);
			delay(50);
			i+=5;
			s+=5;
			if(s==245)
				flag+=1;	
		}
		if(flag==3) 
		{
			setcolor(0);
			circle(400,250,s);
			delay(50);
			i-=5;
			s-=5;
			if(s<=0)
		 		flag+=1;
		}
		if(flag==4) //los voy a pintar de azul
		{
			setcolor(COLOR(0,0,i+5));
			circle(400,250,s);
			delay(50);
			i+=5;
			s+=5;
			if(s==245)
				flag+=1;	
		}
		if(flag==5 || flag%2==1) 
		{
			setcolor(0);
			circle(400,250,s);
			delay(50);
			i-=5;
			s-=5;
			if(s<=0)
		 		flag+=1;
		 }
		if(flag==6) //los voy a pintar de forma aleatoria
		{
			setcolor(COLOR(rand()%255+1,rand()%255+1,rand()%255+1));
			circle(400,250,s);
			delay(50);
			i+=5;
			s+=5;
			if(s==250)
				flag+=1;
		}
		if(flag>7)
			flag=0;
	}while(!kbhit());
	getch();
	closegraph(); 
	return 0;
}
