//  1 1
//  7 4 5-A
//+ 3 3 7-B 
//-------
// 10 8 2-C
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>
#define pi 3.1415
FILE *AbrirArchivo(char N[80],char M[6]);
int main()
{
	
	FILE *fp,*fq,*fr;
	int a,b,i,j,k,suma,c;
	int A[10],B[10],B1[10],C[5];
	//char A[10],B[10],C[5];
	printf("---ARCHIVO A:---");
	fp=AbrirArchivo("C:\\Estructuras\\A.txt","r");//lee archivo A
	i=0;
	j=0;
	do
	{
		if(!feof(fp))//if(i==0||i==2*j-1)
		{
			fscanf(fp,"%i",&A[j]);//Lee del archivoo la cadena de caracteres
			printf("%i ",A[j]);//Imprime en pantalla la cadena de caracteres
			j++;
		}	
		i++;		
	}while(!feof(fp));
	fclose(fp);

	fq=AbrirArchivo("C:\\Estructuras\\B.txt","r");//lee archivo B
	i=0;
	j=0;
	printf("\n\t+");
	printf("\n---ARCHIVO B:---");
	do
	{	
		if(!feof(fp))//if(i==0||i==2*j-1)
		{
			fscanf(fq,"%i",&B[j]);//guarda en un arreglo entero
			printf("%i ",B[j]);
			j++;
		}	
		i++;				
	}while(!feof(fq));
	fclose(fq);
	
	//printf("\n%i+%i=%i",A[1],B[2],A[1]+B[2]);
	//Realizar la suma por columnas, digito por digito de derecha a izquierda
	k=0;
	for(i=2;i>=0;i--)
	{
	//	printf("\n%i+%i=%i",A[i],B[i],A[i]+B[i]);
		//B1[i]=A[i]+B[i];
		if(k==0 && A[i]+B[i]>=10)//para la primera vez,caso de que sea mayor que 10
		{
			a=(A[i]+B[i])/10;
			b=A[i]+B[i]-10;
			//printf("\n%i+%i=%i\n--b=%i",A[i],B[i],A[i]+B[i],b);
			C[i]=b;
			//printf("C=%i,%i",C[i],i);
			//printf("\n %i",a);
			k++;
		}
		if(A[i]+B[i]>=10&&k>=1) //segunda vez en adelante, caso de que sea mayor que 10
		{
			b=A[i]+B[i]-10+a;
			C[i]=b;
			a=0;
			a=(A[i]+B[i])/10;
			//printf("\n %i",a);
			//k++;
		}
		if(A[i]+B[i]<10&&k>=1||i==0)// caso en que la suma sea menor que 10
		{
			C[i]=A[i]+B[i]+a;
		}
	}
	C[2]=C[2]-1;
	C[0]=C[0]-1;
	
	
	fr=AbrirArchivo("C:\\Estructuras\\C.txt","w");//Abrir archivo C en modo escritura, donde quiero gurdar la suma
	printf("\n---Archivo C---:");
	for(i=0;i<3;i++)
	{
	//	printf("\n\n\n%i",C[i]);
		fprintf(fr,"%i",C[i]);
	}
	fclose(fr);
	fr=AbrirArchivo("C:\\Estructuras\\C.txt","r");//leer el archivo de la suma
	i=0;
	j=0;
	do
	{	if(!feof(fp))//if(i==0||i==2*j-1)
		{
			fscanf(fr,"%i",&C[j]);
			printf("%i",C[j]);
			j++;
		}	
		i++;				
	}while(!feof(fr));
	fclose(fr);
	/*do
	{
		{
			fscanf(fr,"%i",&B[i]);
			printf("%i",B[i]);
			j++;
		}	
		i++;				
	}while(!feof(fr));*/
	return 0;
}
FILE *AbrirArchivo(char N[80],char M[6])
{
	FILE *fp;
	fp=fopen(N,M);
	if(fp==NULL)
	{
		printf("Error de apertura de archivo,pulse una tecla para continar ");
		getch();
		exit(1);
		
	}
	return fp;
}
