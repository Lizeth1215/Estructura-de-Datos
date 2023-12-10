#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
#define pi 3.14159265
//TAREA 3. Con Menu, Tres casos 
int main ()
{	
	int A[42],x,k=0,i,band=1,angulo,c,m,y,l,j; //8 vertices va a tener un triangulo
	float rad,a=0;
	printf("1.-Estrellas\n 2.-Estrellas con tiempo\n 3.-Estrellas con rotacion\n Escoja una opcion: ");
	scanf("%i",&y);
	if(y==3)
	{
		printf("\nEscribe el angulo de giro: ");
		scanf("%i",&angulo);
	}
	srand(time(NULL));
	initwindow(800,600);	
	do{	
		switch(y)
		{
			case 1:
					do
					{
						if(band==1)
						{
							for(m=3;m<=10;m++)
							{
								a=360.0/m;
								l=a*k*pi/180.0;//convierto a rad
								k++;
								j=0;
								for(i=0;i<(m*4)+2;i+=4)//para que no sobreescriban y ocupe todas las posiciones del arreglo
								//m=3 -> 13, m=4 -> 17
								{
									A[i]=(int)(400+200*cos((j*2*pi/(m*2))+l)); //400 es la mitad de x=800
									A[i+1]=(int)(300-200*sin((j*2*pi/(m*2))+l));//300 es la mitad de y=600
									j++;
									A[i+2]=(int)(400+200/3*cos((j*2*pi/(m*2))+l));
									A[i+3]=(int)(300-200/3*sin((j*2*pi/(m*2))+l));
									j++;	
								}
								setcolor(COLOR(rand()%255,rand()%255,rand()%255));
								drawpoly((m*2)+1,A);
								delay(300);
								setcolor(0);
								drawpoly((m*2)+1,A);	
								if(m==10)
									band+=1;
							}
						}		
						if(band==2)
						{
							for(m=10;m>=3;m--)
							{
								a=360.0/m;
								l=a*k*pi/180.0;//convierto a rad
								k++;
								j=0;
								for(i=0;i<(m*4)+2;i+=4)//para que no sobreescriban y ocupe todas las posiciones del arreglo
								{
									A[i]=(int)(400+200*cos((j*2*pi/(m*2))+l)); //400 es la mitad de x=800
									A[i+1]=(int)(300-200*sin((j*2*pi/(m*2))+l));//300 es la mitad de y=600
									j++;
									A[i+2]=(int)(400+200/3*cos((j*2*pi/(m*2))+l));
									A[i+3]=(int)(300-200/3*sin((j*2*pi/(m*2))+l));
									j++;	
								}
								setcolor(COLOR(rand()%255,rand()%255,rand()%255)); 
								drawpoly((m*2)+1,A);
								delay(300);
								setcolor(0);
								drawpoly((m*2)+1,A);	
								if(m==3)
									band+=1;
							}
						}
						if(band==3)
							band=1;
					}while(!kbhit());
					break;
			case 2: 
					do
					{
						if(band==1)
						{
							for(m=3;m<=10;m++)
							{
								a=360.0/m;
								l=a*k*pi/180.0;//convierto a rad
								k++;
								j=0;
								for(i=0;i<(m*4)+2;i+=4)//para que no sobreescriban y ocupe todas las posiciones del arreglo
								{
									A[i]=(int)(400+200*cos((j*2*pi/(m*2))+l)); //400 es la mitad de x=800
									A[i+1]=(int)(300-200*sin((j*2*pi/(m*2))+l));//300 es la mitad de y=600
									j++;
									A[i+2]=(int)(400+200/3*cos((j*2*pi/(m*2))+l));
									A[i+3]=(int)(300-200/3*sin((j*2*pi/(m*2))+l));
									j++;	
								}
								setcolor(COLOR(rand()%255,rand()%255,rand()%255));
								drawpoly((m*2)+1,A);
								delay(500);
								setcolor(0);
								drawpoly((m*2)+1,A);	
								if(m==10)
									band+=1;
							}
						}	
						if(band==2)
						{
							for(m=10;m>=3;m--)
							{
								a=360.0/m;
								l=a*k*pi/180.0;//convierto a rad
								k++;
								j=0;
								for(i=0;i<(m*4)+2;i+=4)//para que no sobreescriban y ocupe todas las posiciones del arreglo
								{
									A[i]=(int)(400+200*cos((j*2*pi/(m*2))+l)); //400 es la mitad de x=800
									A[i+1]=(int)(300-200*sin((j*2*pi/(m*2))+l));//300 es la mitad de y=600
									j++;
									A[i+2]=(int)(400+200/3*cos((j*2*pi/(m*2))+l));
									A[i+3]=(int)(300-200/3*sin((j*2*pi/(m*2))+l));
									j++;	
								}
								setcolor(COLOR(rand()%255,rand()%255,rand()%255)); 
								drawpoly((m*2)+1,A);
								delay(500);
								setcolor(0);
								drawpoly((m*2)+1,A);	
								if(m==3)
									band+=1;
							}
						}
						if(band==3)
							band=1;
					}while(!kbhit());
						break;	
			case 3:
					do
					{
					if(band==1)
					{
						for(m=3;m<=10;m++)
						{
							for(k=1;k<360/angulo;k++)
							{
								a=360.0/m;
								j=0;
								c=0;
								l=(a*c*pi/180.0)-(angulo*k*pi/180.0);//convierto a rad
								c++;
								for(i=0;i<(m*4)+2;i+=4)//para que no sobreescriban y ocupe todas las posiciones del arreglo
								{
									A[i]=(int)(400+200*cos((j*2*pi/(m*2))+l)); //400 es la mitad de x=800
									A[i+1]=(int)(300-200*sin((j*2*pi/(m*2))+l));//300 es la mitad de y=600
									j++;
									A[i+2]=(int)(400+200/3*cos((j*2*pi/(m*2))+l));
									A[i+3]=(int)(300-200/3*sin((j*2*pi/(m*2))+l));
									j++;	
								}
								setcolor(4);//COLOR(rand()%255,rand()%255,rand()%255)
								drawpoly((m*2)+1,A);
								delay(500);
								setcolor(0);
								drawpoly((m*2)+1,A);	
								if(m==10)
								band+=1;
							}
						}
					}	
					if(band==2)
					{
						for(m=10;m>=3;m--)
						{
							for(k=1;k<=360/angulo;k++)
							{
								a=360.0/m;
								c=0;
								j=0;
								l=(a*c*pi/180.0)-(angulo*k*pi/180.0);
								c++;
								for(i=0;i<(m*4)+2;i+=4)//para que no sobreescriban y ocupe todas las posiciones del arreglo
								{
									A[i]=(int)(400+200*cos((j*2*pi/(m*2))+l)); //400 es la mitad de x=800
									A[i+1]=(int)(300-200*sin((j*2*pi/(m*2))+l));//300 es la mitad de y=600
									j++;
									A[i+2]=(int)(400+200/3*cos((j*2*pi/(m*2))+l));
									A[i+3]=(int)(300-200/3*sin((j*2*pi/(m*2))+l));
									j++;	
								}
								setcolor(4); //COLOR(rand()%255,rand()%255,rand()%255)
								drawpoly((m*2)+1,A);
								delay(500);
								setcolor(0);
								drawpoly((m*2)+1,A);	
								if(m==3)
									band+=1;
							}
						}
					}
					if(band>3)
						band=1;
				}while(!kbhit());
				break;			
		}
	}while(y==1 && y==2 && y==3);	
	getch();
	closegraph(); 
	return 0;
}
