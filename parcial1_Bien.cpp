#include<winbgim.h>
#include<conio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdio.h>
struct coordenadas
{
	int x,y;	
};
struct coordenadas mousexy();
int main()
{
    int y=0,a=0,s,S[5];
    char Y[8],M[2],h;
    struct coordenadas A;
	A.x=1025;    
	A.y=175;
	srand(time(NULL));
	/*h=getch();
	t=getch();
	printf("\n%i  %i",h,t);
	getch();*/
	initwindow(1600,900);
	settextstyle(1,0,2);	
	for(s=1;s<=5;s++)
	{
		for(a=0;a<9;a++)
			Y[a]=0;
		setfillstyle(1,0);
		bar(900,200,1000,300);
		bar(600,500,800,700);
		outtextxy(600,200,"Introduce el dato");
		itoa(s,M,10);
		outtextxy(900,200,M);
		a=0;
		do
		{
			h=getch();
			if(h!=13)
			{
				Y[a]=h;
				a++;
				outtextxy(600,500,Y);
			}	
		}
		while(h!=13);
		Y[a]='\0';
		S[s]=atoi(Y);
	}
	for(s=1;s<=5;s++)
		printf("%i\n",S[s]);
	bar(600,200,1000,300);
	bar(600,500,800,700);
	setfillstyle(1,15);
	a=0;
	for(s=1;s<=5;s++)
	{
		a+=S[s];
	}
	settextstyle(1,0,2);
	bar(1000,50,1050,100);
	outtextxy(1100,50,"Separar todos");
	bar(1000,150,1050,200);
	outtextxy(1100,150,"Unir todos");
	bar(1000,250,1050,300);
	outtextxy(1100,250,"Separar el 1");
	bar(1000,350,1050,400);
	outtextxy(1100,350,"Separar el 2");
	bar(1000,450,1050,500);
	outtextxy(1100,450,"Separar el 3");
	bar(1000,550,1050,600); 
	outtextxy(1100,550,"Separar el 4");
	bar(1000,650,1050,700); 
	outtextxy(1100,650,"Separar el 5");
	bar(1000,750,1050,800);
	outtextxy(1100,750,"Salir");
	setcolor(0);
	do
	{
		if(A.x>1000&&A.x<1050&&A.y<200&&A.y>150)//unir todo
		{
			y=0;
			setfillstyle(1,0);
			bar(300,250,700,700);
			for(s=1;s<=5;s++)
			{
				setfillstyle(1,COLOR(rand()%250,rand()%250,rand()%250));
				pieslice(500,450,y,y+((S[s]*360)/a),150);
				y+=(S[s]*360)/a;
			}
		}
		A=mousexy();		
		if(A.x>1000&&A.x<1050&&A.y<100&&A.y>50)//separar todo
		{
			y=0;
			setfillstyle(1,0);
			bar(300,250,700,700);
			for(s=1;s<=5;s++)
			{	
				setfillstyle(1,0);
				pieslice(500,450,y-1,y+((S[s]*360)/a)+1,150);
				setfillstyle(1,COLOR(rand()%250,rand()%250,rand()%250));
				pieslice(500,450,y,y+((S[s]*360)/a),150+20*(s%3));
				y+=(S[s]*360)/a;
			}
		}
		if((A.x>1000&&A.x<1050)&&(A.y>250&&A.y<300))//separar 1
		{
			y=0;
			setfillstyle(1,0);
			bar(300,250,700,700);
			for(s=1;s<=5;s++)
			{	
				if(s==1)
				{
					setfillstyle(1,0);
					pieslice(500,450,y-1,y+((S[s]*360)/a)+1,150);
					setfillstyle(1,COLOR(rand()%250,rand()%250,rand()%250));
					pieslice(500,450,y,y+((S[s]*360)/a),170);
				}
				else
				{
					setfillstyle(1,COLOR(rand()%250,rand()%250,rand()%250));
					pieslice(500,450,y,y+((S[s]*360)/a),150);
				}
			y+=(S[s]*360)/a;
			}
		}
		if((A.x>1000&&A.x<1050)&&(A.y>350&&A.y<400))//separar 2
		{
			y=0;
			setfillstyle(1,0);
			bar(300,250,700,700);
			for(s=1;s<=5;s++)
			{	
				if(s==2)
				{
					setfillstyle(1,0);
					pieslice(500,450,y-1,y+((S[s]*360)/a)+1,150);
					setfillstyle(1,COLOR(rand()%250,rand()%250,rand()%250));
					pieslice(500,450,y,y+((S[s]*360)/a),170);
				}
				else
				{
					setfillstyle(1,COLOR(rand()%250,rand()%250,rand()%250));
					pieslice(500,450,y,y+((S[s]*360)/a),150);
				}
			y+=(S[s]*360)/a;
			}
		}
		if((A.x>1000&&A.x<1050)&&(A.y>450&&A.y<500))//separar 3
		{
			y=0;
			setfillstyle(1,0);
			bar(300,250,700,700);
			for(s=1;s<=5;s++)
			{	
				if(s==3)
				{
					setfillstyle(1,0);
					pieslice(500,450,y-1,y+((S[s]*360)/a)+1,150);
					setfillstyle(1,COLOR(rand()%250,rand()%250,rand()%250));
					pieslice(500,450,y,y+((S[s]*360)/a),170);
				}
				else
				{
					setfillstyle(1,COLOR(rand()%250,rand()%250,rand()%250));
					pieslice(500,450,y,y+((S[s]*360)/a),150);
				}
			y+=(S[s]*360)/a;
			}
		}
		if((A.x>1000&&A.x<1050)&&(A.y>550&&A.y<600))//separar 4
		{
			y=0;
			setfillstyle(1,0);
			bar(300,250,700,700);
			for(s=1;s<=5;s++)
			{	
				if(s==4)
				{
					setfillstyle(1,0);
					pieslice(500,450,y-1,y+((S[s]*360)/a)+1,150);
					setfillstyle(1,COLOR(rand()%250,rand()%250,rand()%250));
					pieslice(500,450,y,y+((S[s]*360)/a),170);
				}
				else
				{
					setfillstyle(1,COLOR(rand()%250,rand()%250,rand()%250));
					pieslice(500,450,y,y+((S[s]*360)/a),150);
				}
			y+=(S[s]*360)/a;
			}
		}
		if((A.x>1000&&A.x<1050)&&(A.y>650&&A.y<700))//separar 5
		{
			y=0;
			setfillstyle(1,0);
			bar(300,250,700,700);
			for(s=1;s<=5;s++)
			{	
				if(s==5)
				{
					setfillstyle(1,0);
					pieslice(500,450,y-1,y+((S[s]*360)/a)+1,150);
					setfillstyle(1,COLOR(rand()%250,rand()%250,rand()%250));
					pieslice(500,450,y,y+((S[s]*360)/a),170);
				}
				else
				{
					setfillstyle(1,COLOR(rand()%250,rand()%250,rand()%250));
					pieslice(500,450,y,y+((S[s]*360)/a),150);
				}
			y+=(S[s]*360)/a;
			}
		}		
	}
	while(A.x<1000||A.x>1050||A.y<750||A.y>800);
	//outtextxy();
    closegraph();
	return 0;
}
struct coordenadas mousexy()
{
    struct coordenadas A;
	clearmouseclick(WM_LBUTTONDOWN);
    const int DELAY = 50;
    int x,y;
    while (!ismouseclick(WM_LBUTTONDOWN))
        delay(DELAY);
    getmouseclick(WM_LBUTTONDOWN,A.x,A.y);
    return A;
}

