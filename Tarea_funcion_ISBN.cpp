#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int verificador (char ISBN[15]);
int main (void)
{
	char ISBN[15];
	int n;
	printf("Escribe un codigo ISBN: ");
	scanf("%s",ISBN);
	n=verificador (ISBN);
	
	getch();
	return 0;
}
int verificador (char ISBN[15])
{
	int band=0,m;
	m=strlen(ISBN);
	if(m==13)
		printf("Codigo ISBN correcto");
	else
		printf("Codigo ISBN incorrecto");
	if (ISBN[0]==9 && ISBN[1]==7 && ISBN[2]==8)
		band=1;
	 if(ISBN[0]==9 && ISBN[1]==7 && ISBN[2]==9)
		 band=1;
	if(band==1)
		printf("\nCodigo ISBN correcto");
		
}

