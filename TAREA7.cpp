#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
//TAREA 7. JUEGO DEL GATO
struct coordenadas
{
	int x,y;
};
struct coordenadas mouse (void);
void Tacha (void);
void Circulo (void);
int main (void)
{
	int band=0,i,j,flag=0, A[3][3],suma;
	struct coordenadas T,P,C;
	initwindow(700, 700);
	srand(time(NULL));//para quen no comience en la misma semilla
	//Bosquejo
	setlinestyle(1,1,3);
	setcolor(8);
	line(100+(400/3),100,100+(400/3),500);//linea vertical
	line(100+2*(400/3),100,100+2*(400/3),500);//linea vertical
	line(100,100+(400/3),500,100+(400/3));//linea horizontal
	line(100,100+2*(400/3),500,100+2*(400/3));
	setlinestyle(1,1,3);
	setcolor(15);
	line(115,565,165,585);//tache
	line(165,565,115,585);//tache
	rectangle(100,550,180,600);
	setlinestyle(2,1,3);
	setcolor(3);
	circle(289,575,14); //circulo
	rectangle(250,550,330,600);
	setlinestyle(2,1,3);
	setcolor(5);
	outtextxy(420,570,"SALIR");
	rectangle(400,550,480,600);
	for(i=0;i<3;i++)//asi limpio mi matreiz, para que pueda sumar de forma correcta, porque sino se alamacenan numeros
	{
		for(j=0;j<3;j++)
		{
			A[i][j]=0;
		}
	}
	do
	{
		setlinestyle(2,1,2);
		setcolor(COLOR(rand()%256,rand()%256,rand()%256));
		T=mouse();	
	//	printf("\n(%i, %i)",T.x,T.y);
		if((T.x>400&&T.x<480)&&(T.y>550&&T.y<600))//SALIR
		{
			band=1;		
			closegraph();
		}	
		if((T.x>100&&T.x<180)&&(T.y>550&&T.y<600))//rectangle(100,550,180,600) TACHE=1
		{
			P=mouse();
			do
			{
				if((P.x>100&&P.x<500)&&(P.y>100&&P.y<500))//rectangle(100,100,500,500)
				{
					if((P.x>100&&P.x<100+400/3)&&(P.y>100&&P.y<100+400/3))//rectangle(100,100,100+400/3,100+400/3); primner cuadro
					{
						line(120,120,100-20+400/3,100-20+400/3);
						line(100-20+400/3,120,120,100-20+400/3);
						flag=1;
						A[0][0]=1;
					}
					if((P.x>100+400/3&&P.x<100+2*400/3)&&(P.y>100&&P.y<100+400/3))//rectangle(100+400/3,100,100+(2*400/3),100+400/3);
					{
						line(100+400/3+20,120,100+(2*400/3)-20,100+(400/3)-20);
						line(100+(2*400/3)-20,120,100+400/3+20,100+(400/3)-20);
						flag=1;
						A[0][1]=1;
					}
					if((P.x>100+(2*400/3)&&P.x<100+3*400/3)&&(P.y>100&&P.y<100+400/3))//rectangle(100+2*400/3,100,100+(3*400/3),100+400/3);
					{
						line(100+2*400/3+20,120,100+(3*400/3)-20,100+(400/3)-20);
						line(100+(3*400/3)-20,120,100+2*400/3+20,100+(400/3)-20);
						flag=1;
						A[0][2]=1;
					}
					if((P.x>100&&P.x<100+400/3)&&(P.y>100+400/3&&P.y<100+2*400/3))//rectangle(100,100+400/3,100+400/3,100+2*400/3);
					{
						line(100+20,100+400/3+20,100+400/3-20,100+2*400/3-20);
						line(100+400/3-20,100+400/3+20,100+20,100+2*400/3-20);
						flag=1;
						A[1][0]=1;
					}	
					if((P.x>100+400/3&&P.x<100+2*400/3)&&(P.y>100+400/3&&P.y<100+2*400/3))//rectangle(100+400/3,100+400/3,100+2*400/3,100+2*400/3);
					{
						line(100+400/3+20,100+400/3+20,100+2*400/3-20,100+2*400/3-20);
						line(100+2*400/3-20,100+400/3+20,100+400/3+20,100+2*400/3-20);
						flag=1;
						A[1][1]=1;
					}
					if((P.x>100+2*400/3&&P.x<100+3*400/3)&&(P.y>100+400/3&&P.y<100+2*400/3))//rectangle(100+2*400/3,100+400/3,100+3*400/3,100+2*400/3);
					{
						line(100+2*400/3+20,100+400/3+20,100+3*400/3-20,100+2*400/3-20);
						line(100+3*400/3-20,100+400/3+20,100+2*400/3+20,100+2*400/3-20);
						flag=1;
						A[1][2]=1;
					}
					if((P.x>100&&P.x<100+400/3)&&(P.y>100+2*400/3&&P.y<100+3*400/3))//rectangle(100,100+2*400/3,100+400/3,100+3*400/3);
					{
						line(100+20,100+2*400/3+20,100+400/3-20,100+3*400/3-20);
						line(100+400/3-20,100+2*400/3+20,100+20,100+3*400/3-20);
						flag=1;
						A[2][0]=1;
					}	
					if((P.x>100+400/3&&P.x<100+2*400/3)&&(P.y>100+2*400/3&&P.y<100+3*400/3))//rectangle(100+400/3,100+2*400/3,100+2*400/3,100+3*400/3);
					{
						line(100+400/3+20,100+2*400/3+20,100+2*400/3-20,100+3*400/3-20);
						line(100+2*400/3-20,100+2*400/3+20,100+400/3+20,100+3*400/3-20);
						flag=1;
						A[2][1]=1;
					}
					if((P.x>100+2*400/3&&P.x<100+3*400/3)&&(P.y>100+2*400/3&&P.y<100+3*400/3))//rectangle(100+2*400/3,100+2*400/3,100+3*400/3,100+3*400/3);
					{
						line(100+2*400/3+20,100+2*400/3+20,100+3*400/3-20,100+3*400/3-20);
						line(100+3*400/3-20,100+2*400/3+20,100+2*400/3+20,100+3*400/3-20);
						flag=1;
						A[2][2]=1;
					}
				}
			}while(flag==0);
		}
		if((T.x>250&&T.x<330)&&(T.y>550&&T.y<600))//rectangle(250,550,330,600);
		{
			P=mouse();
			do
			{
				if((P.x>100&&P.x<500)&&(P.y>100&&P.y<500))//rectangle(100,100,500,500)
				{
					if((P.x>100&&P.x<100+400/3)&&(P.y>100&&P.y<100+400/3))//rectangle(100,100,100+400/3,100+400/3);
					{
						circle(100+400/6,100+200/3,50);
						flag=1;
						A[0][0]=5;
					}
					if((P.x>100+400/3&&P.x<100+2*400/3)&&(P.y>100&&P.y<100+400/3))//rectangle(100+400/3,100,100+(2*400/3),100+400/3);
					{
						circle(100+400/3+400/6,100+200/3,50);
						flag=1;
						A[0][1]=5;
					}
					if((P.x>100+(2*400/3)&&P.x<100+3*400/3)&&(P.y>100&&P.y<100+400/3))//rectangle(100+2*400/3,100,100+(3*400/3),100+400/3);
					{
						circle(100+2*400/3+400/6,100+200/3,50);
						flag=1;
						A[0][2]=5;
					}
					if((P.x>100&&P.x<100+400/3)&&(P.y>100+400/3&&P.y<100+2*400/3))//rectangle(100,100+400/3,100+400/3,100+2*400/3);
					{
						circle(100+400/6,100+400/3+200/3,50);
						flag=1;
						A[1][0]=5;
					}	
					if((P.x>100+400/3&&P.x<100+2*400/3)&&(P.y>100+400/3&&P.y<100+2*400/3))//rectangle(100+400/3,100+400/3,100+2*400/3,100+2*400/3);
					{
						circle(100+400/3+400/6,100+400/3+200/3,50);
						flag=1;
						A[1][1]=5;
					}
					if((P.x>100+2*400/3&&P.x<100+3*400/3)&&(P.y>100+400/3&&P.y<100+2*400/3))//rectangle(100+2*400/3,100+400/3,100+3*400/3,100+2*400/3);
					{
						circle(100+2*400/3+400/6,100+400/3+200/3,50);
						flag=1;
						A[1][2]=5;
					}
					if((P.x>100&&P.x<100+400/3)&&(P.y>100+2*400/3&&P.y<100+3*400/3))//rectangle(100,100+2*400/3,100+400/3,100+3*400/3);
					{
						circle(100+400/6,100+2*400/3+200/3,50);
						flag=1;
						A[2][0]=5;
					}	
					if((P.x>100+400/3&&P.x<100+2*400/3)&&(P.y>100+2*400/3&&P.y<100+3*400/3))//rectangle(100+400/3,100+2*400/3,100+2*400/3,100+3*400/3);
					{
						circle(100+400/3+400/6,100+2*400/3+200/3,50);
						flag=1;
						A[2][1]=5;
					}
					if((P.x>100+2*400/3&&P.x<100+3*400/3)&&(P.y>100+2*400/3&&P.y<100+3*400/3))//rectangle(100+2*400/3,100+2*400/3,100+3*400/3,100+3*400/3);
					{
						circle(100+2*400/3+400/6,100+2*400/3+200/3,50);
						flag=1;
						A[2][2]=5;
					}
				}
			}while(flag==0);
		}	
		for(suma=0,i=0;i<3;i++)//opcion 1. rectangle(100,100,100+400/3,100+400/3); primner cuadro
		{
			suma=suma+A[i][0];
		}
		if(suma==3)
		{
			printf("Gano X");
			line(100+400/6,100,100+400/6,100+3*400/3);
			delay(2000);
			closegraph();
		}
		if(suma==15)
		{
			printf("Gano O");
			line(100+400/6,100,100+400/6,100+3*400/3);
			delay(2000);
			closegraph();
			//line()
		}
		
		for(suma=0,i=0;i<3;i++)//rectangle(100+400/3,100,100+(2*400/3),100+400/3);
		{
			suma=suma+A[i][1];
		}
		if(suma==3)
		{
			printf("Gano X");
			line(100+400/3+400/6,100,100+400/3+400/6,100+3*400/3);
			delay(2000);
			closegraph();
		}
		if(suma==15)
		{
			printf("Gano O");
			line(100+400/3+400/6,100,100+400/3+400/6,100+3*400/3);
			delay(2000);
			closegraph();
		}
		for(suma=0,i=0;i<3;i++)//
		{
			suma=suma+A[i][2];
		}
		if(suma==3)
		{
			printf("Gano X");
			//line()
			delay(2000);
			closegraph();
		}
		if(suma==15)
		{
			printf("Gano O");
			//line()
			delay(2000);
			closegraph();
		}
		for(suma=0,i=0;i<3;i++)//
		{
			suma=suma+A[0][i];
		}
		if(suma==3)
		{
			printf("Gano X");
			//line()
			delay(2000);
			closegraph();
		}
		if(suma==15)
		{
			printf("Gano O");
			//line()
			delay(2000);
			closegraph();
		}
		for(suma=0,i=0;i<3;i++)//
		{
			suma=suma+A[1][i];
		}
		if(suma==3)
		{
			printf("Gano X");
			//line()
			delay(2000);
			closegraph();
		}
		if(suma==15)
		{
			printf("Gano O");
			//line()
			delay(2000);
			closegraph();
		}
		for(suma=0,i=0;i<3;i++)//
		{
			suma=suma+A[2][i];
		}
		if(suma==3)
		{
			printf("Gano X");
			//line()
			delay(2000);
			closegraph();
		}
		if(suma==15)
		{
			printf("Gano O");
			//line()
			delay(2000);
			closegraph();
		}
		for(suma=0,i=0;i<3;i++)//
		{
			suma=suma+A[i][i];
		}
		if(suma==3)
		{
			printf("Gano X");
			//line()
			delay(2000);
			closegraph();
		}
		if(suma==15)
		{
			printf("Gano O");
			//line()
			delay(2000);
			closegraph();
		}
		for(suma=0,i=0;i<3;i++)//
		{
			suma=suma+A[i][2-i];
		}
		if(suma==3)
		{
			printf("Gano X");
			//line()
			delay(2000);
			closegraph();
		}
		if(suma==15)
		{
			printf("Gano O");
			//line()
			delay(2000);
			closegraph();
		}
		
	}while(band==0);//(T.x<400&&T.x>480)&&(T.y<550&&T.y>600)
	getch();
	closegraph(); 
	return 0;
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
void Tacha (void)
{
	line(115,565,165,585);
	line(165,565,115,585);
}
void Circulo (void)
{
	circle(289,575,14); 
}
