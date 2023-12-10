#include<stdio.h>	
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<math.h>
#include<time.h>
//Tercer examen parcial.
//Andrea Lizeth Hernández Luna, José Alfredo Gómez García

FILE *AbrirArchivo (char N[80], char M[5]);
int main (void)
{
	FILE *fp, *fq1, *fq, *fq2,*fq3,*fq4,*fq5,*fq6,*fq7,*fq8;
	int a,i,j;	
	char H[80],RE[80];
	
	fp=fopen("C:\\Estructuras\\hoy.txt","rb");

	fq=fopen("C:\\Estructuras\\hoy1.txt","w");
	fclose(fq);
	fq2=fopen("C:\\Estructuras\\hoy2.txt","w");
	fclose(fq2);
	fq3=fopen("C:\\Estructuras\\hoy3.txt","w");
	fclose(fq3);
	fq4=fopen("C:\\Estructuras\\hoy4.txt","w");
	fclose(fq4);
	fq6=fopen("C:\\Estructuras\\hoy6.txt","w");
	fclose(fq6);
	fq8=fopen("C:\\Estructuras\\hoy8.txt","w");
	fclose(fq8);
	
	if(fp==NULL)
		{
			printf("Archivo no encontrado");
			getch();
			exit(1);
		}
	printf("El contenido del archivo es: ");
	do
	{
		fscanf(fp,"%s",H);
		if(!feof(fp))
			printf("%s ",H);
	}while(!feof(fp));
	fclose(fp);
	
	fp=fopen("C:\\Estructuras\\hoy.txt","rb");
	do
	{
		fscanf(fp,"%s",H);
		if(!feof(fp))
		//	printf("\n%s",H);		
		
		if(strlen(H)==1)
		{
			fq=fopen("C:\\Estructuras\\hoy1.txt","a");
			fprintf(fq,"%s\n ",H);
			fclose(fq);	
		}	
		if(strlen(H)==2)	
		{
			fq2=fopen("C:\\Estructuras\\hoy2.txt","a");
			fprintf(fq2,"%s\n ",H);	
			fclose(fq2);
		}			
		if(strlen(H)==3)
		{
			fq3=fopen("C:\\Estructuras\\hoy3.txt","a");
			fprintf(fq3,"%s\n ",H);
			fclose(fq3);
		}
		if(strlen(H)==4)
		{
			fq4=fopen("C:\\Estructuras\\hoy4.txt","a");
			fprintf(fq4,"%s\n ",H);
			fclose(fq4);
		}
		if(strlen(H)==5)
		{
			fq5=fopen("C:\\Estructuras\\hoy5.txt","a");
			fprintf(fq5,"%s\n ",H);
			fclose(fq5);
		}
		if(strlen(H)==6)
		{
			fq6=fopen("C:\\Estructuras\\hoy6.txt","a");
			if(!feof(fp))
				fprintf(fq6,"%s\n ",H);
			fclose(fq6);
		}
		if(strlen(H)==7)
		{
			fq7=fopen("C:\\Estructuras\\hoy7.txt","a");
			fprintf(fq7,"%s\n ",H);
			fclose(fq7);
		}
		if(strlen(H)==8)
		{
			fq8=fopen("C:\\Estructuras\\hoy8.txt","a");
			fprintf(fq8,"%s\n ",H);
			fclose(fq8);
		}					
	}while(!feof(fp));
	fclose(fp);
	getch();
	return 0;
}

FILE *AbrirArchivo (char N[80], char M[5])
{
	FILE *w;
	w=fopen(N,M);
	if(w==NULL)
	{
		printf("\nError de apertura de archivo, pulsa enter para continuar");
		getch();
		exit(1);
	}
	return w;
}
