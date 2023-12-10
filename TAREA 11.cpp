#include<stdio.h>	
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<math.h>
#include<time.h>
//Tengo dos archivos que contienen una frase y voy a determinar si estas son palindromas. No voy a considerar los espacios
int main (void)
{
	FILE *fp,*fq;
	char A1[80], A2[80];
	int i;
	fp=fopen("C:\\Estructuras\\Archivo1.txt","w");//El archivo puede o no existir, si este existe borra el contenido que haya y sino existe lo crea
	fq=fopen("C:\\Estructuras\\Archivo2.txt","w");
	printf("Introduce una frase al archivo1: ");//En caso de que exista, continuamos con este letrero
	gets(A1);//guarda en una cadena
	fprintf(fp,"%s ",A1);
	printf("Introduce una frase al archivo2: ");
	gets(A2);
	fprintf(fq,"%s ",A2);
	
	fclose(fp);
	fclose(fq);
	getch();
	return 0;
}

