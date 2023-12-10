#include<winbgim.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
//Modificaciones a las estructuras
struct texto
{
	char S[100];
	char A[50],B[50],C[50],D[50],E[50],F[50];//Sugerencias de búsqueda
};
struct coordenadas
{
	int x,y;
};
struct libro
{
	char T[80],A[50],E[50],ISBN[15],P[20],ED[20],I[10],C[15];//C: Colección
	int AP,NI;//NI: número de inventario
	float s;
};
struct book
{
	char T[80],A[50],E[50],ISBN[15],P[20],ED[20],I[10],C[15];
	int AP,NI;
	float s;
	struct book *sig,*ant;
};
typedef struct book * lista;
void imprimirbd(void);//imprime toda la base de datos, para revisar cosillas y hacer pruebas
void modificar_titulo(void);
void eliminar_titulo(void);
void agregar_titulo(void);
struct texto sugerencias_busqueda(char S[100]);//Recibe un texto y retorna 6 sugerencias de búsqueda de títulos o autores
struct texto buscador(int x,int y,int x1,int y1);
struct libro datos(void);//no si esta funcion vaya aqui
void MenuModificarEliminar(void);
void seleccionarlibroscomprador(int C[15]);
void MenuDerechosInternacionales(void);
void MenuElNegrito(void);
void MenuCatalogos(void);
void MenuSucursales(void);
void MenuMonederos(void);
void MenuServicios(void);
void MenuOportunidades(void);
void MenuProductos(void);
void MenuAudiolibros(void);
void MenuCategorias(void);
void MenuNuestrosSellos(void);
void MenuSecciones(void);
void MenuAcademicos(void);
void MenuLibros(void);
void ValidarCord(struct coordenadas c, char A[80],int B[15]);
void seleccionarlibros(int C[15]);
void MenuDeArriba(void);
void MenuMas18(void);
void MenuStevenson(void);
void MenuObrasEscogidas(void);
void MenuNoVivirasParaTuProximoCumpleanos(void);
void MenuMujeron(void);
void MenuMoviDick(void);
void MenuMariaInes(void);
void MenuHistoriaDeUnaMujer(void);
void MenuAtrapadosEnElLaberinto(void);
void MenuUnLlamadoALaFelicidad(void);
void MenuLascivias(void);
struct coordenadas MenuInicio(void);
void MenuComprador(void);
void imagen(char A[80],int x,int y);
void imagen (char A[100],int l,int a,int x,int y);
struct coordenadas mousexy (void);
int iniciarsesion(void);
struct texto escritura(int x,int y,int x1,int y1);
FILE *Abrir_Archivo(char A1[100],char A2[4]);
void carrito(int A[15]);
struct book* crear(void);
void libro_a_book(struct libro Y,struct book *S);
void comprar (int s);
int main(void)
{
	struct coordenadas c;
	/*imprimirbd();
	getch();*/
	initwindow(1360,720);
	setfillstyle(SOLID_FILL,15);//pantalla blanca
	floodfill(0,0,5);
	c=MenuInicio();
}
void MenuComprador(void)
{
	struct coordenadas S;
	int x,y,flag,band;
	S.x=-1;S.y=-1;
	cleardevice();
	setfillstyle(SOLID_FILL,15);//pantalla blanca
	floodfill(0,0,5);
	setfillstyle(1,15);
	floodfill(1,1,1);
	imagen("C:\\Proyecto\\PorruaLog.bmp",533,10);//Esta es la ruta en la que estoy poniendo las imagenes en mi compu
	imagen("C:\\Proyecto\\flechaAtras.bmp",0,0);
	imagen("C:\\Proyecto\\PorruaIso.bmp",1250,30);
	imagen("C:\\Proyecto\\buscador.bmp",20,55);
	imagen("C:\\Proyecto\\carrito.bmp",1180,45);
	imagen("C:\\Proyecto\\InicioSesionS.bmp",725,0);
	imagen("C:\\Proyecto\\comunidadporrua.bmp",1100,55);
	imagen("C:\\Proyecto\\opciones.bmp",0,150);
	//libros
	imagen("C:\\Proyecto\\MoviDick.bmp",20,225);
	imagen("C:\\Proyecto\\HistoriaDeUnaMujer.bmp",140,225);
	imagen("C:\\Proyecto\\Mujeron.bmp",260,225);
	imagen("C:\\Proyecto\\ObrasEscogidas.bmp",380,225);
	imagen("C:\\Proyecto\\UnLlamadoALaFelicidad.bmp",500,225);
	imagen("C:\\Proyecto\\+18.bmp",620,225);
	imagen("C:\\Proyecto\\AtrapadosEnElLaberinto.bmp",740,225);
	imagen("C:\\Proyecto\\NoVivirasParaTuProximoCumpleanos.bmp",860,225);
	imagen("C:\\Proyecto\\Lascivia.bmp",980,225);
	imagen("C:\\Proyecto\\MariaInes.bmp",1100,225);
	imagen("C:\\Proyecto\\Stevenson.bmp",1220,225);
	imagen("C:\\Proyecto\\RecomendacionesDelMes.bmp",15,420);
}
void seleccionarlibros(int C[15])//regreso 1
{
	struct coordenadas S;
	struct texto B;
	int band,flag,A[15];
	MenuComprador();
	/*for(band=0;band<=15;band++){A[band]=0;}
	for(band=0;band<=15;band++){printf("%i\t",C[band]);}
	printf("\n");*/
	band=0;
	do{
		while(band!=1&&band!=2&&band!=3&&band!=4&&band!=5&&band!=6&&band!=7&&band!=8&&band!=9&&band!=10&&band!=11&&band!=12&&band!=13&&band!=14&&band!=15&&band!=16&&band!=17&&band!=18&&band!=19&&band!=20&&band!=21&&band!=22&&band!=23&&band!=24&&band!=25)
		{
			if(band==0)
				S=mousexy();
			if(S.x>0&&S.x<32&&S.y>0&&S.y<24)//Atras
				band=1;
			if(S.x>20&&S.x<120&&S.y>225&&S.y<410)//MoviDick
				band=2;
			if(S.x>140&&S.x<240&&S.y>225&&S.y<410)//HistoriaDeUnaMujer
				band=3;
			if(S.x>260&&S.x<360&&S.y>225&&S.y<410)//Mujeron
				band=4;
			if(S.x>380&&S.x<480&&S.y>225&&S.y<410)//ObrasEscogidas
				band=5;
			if(S.x>500&&S.x<600&&S.y>225&&S.y<410)//UnLlamadoALaFelicidad
				band=6;
			if(S.x>620&&S.x<720&&S.y>225&&S.y<410)//Mas18
				band=7;
			if(S.x>740&&S.x<840&&S.y>225&&S.y<410)//AtrapadosEnElLaberinto
				band=8;
			if(S.x>860&&S.x<960&&S.y>225&&S.y<410)//NoVivirasParaTuProximoCumpleaños
				band=9;
			if(S.x>980&&S.x<1080&&S.y>225&&S.y<410)//rectangle(980,225,1080,410)
				band=10;
			if(S.x>1100&&S.x<1200&&S.y>225&&S.y<410)//MariaInes
				band=11;
			if(S.x>1220&&S.x<1320&&S.y>225&&S.y<410)//Stevenson
				band=12;
			if(S.x>0&&S.x<90&&S.y>150&&S.y<212)//rectangle(0,150,90,212);//LIBROS
				band=13;
			if(S.x>90&&S.x<350&&S.y>150&&S.y<212)//rectangle(90,150,350,212);//audiolibros
				band=14;
			if(S.x>350&&S.x<500&&S.y>150&&S.y<212)//rectangle(350,150,500,212);//productos
				band=15;
			if(S.x>500&&S.x<690&&S.y>150&&S.y<212)//rectangle(500,150,690,212);oportunidades
				band=16;
			if(S.x>690&&S.x<830&&S.y>150&&S.y<212)//rectangle(690,150,830,212);servicios
				band=17;
			if(S.x>830&&S.x<980&&S.y>150&&S.y<212)//rectangle(830,150,980,212);monederos
				band=18;
			if(S.x>980&&S.x<1130&&S.y>150&&S.y<212)//rectangle(980,150,1130,212);sucursales
				band=19;
			if(S.x>1130&&S.x<1300&&S.y>150&&S.y<212)//rectangle(1130,150,1300,212);catalogos
				band=20;
			if(S.x>15&&S.x<465&&S.y>420&&S.y<634)//rectangle(15,420,465,634);Recomendados del mes
				band=21;
			if(S.x>465&&S.x<910&&S.y>420&&S.y<634)//rectangle(465,420,915,634);Recomendados del mes
				band=22;
			if(S.x>725&&S.x<1272&&S.y>0&&S.y<35)//rectangle(725,0,1272,35);Iniciar sesion
				band=23;
			if(S.x>20&&S.x<300&&S.y>55&&S.y<109)//rectangle(20,55,300,109);Barra buscador
				band=24;
			if(S.x>1189&&S.x<1251&&S.y>52&&S.y<117)//Carrito de compras  S.x=1189; S.y=52;  S.x=1251; S.y=117
				band=25;
		}
		if(band==1)
			S=MenuInicio();
		if(band==2)
		{
			MenuMoviDick();
			if(C[1]==1)
				imagen("C:\\Proyecto\\anadido.bmp",635,419);
			S=mousexy();
			if(S.x>635&&S.x<920&&S.y>419&&S.y<463)
				{C[1]=1;}
			else
				ValidarCord(S,"C:\\Proyecto\\MoviDickS.bmp",C);
		}
		if(band==3)
		{
			MenuHistoriaDeUnaMujer();
			if(C[2]==1)
				imagen("C:\\Proyecto\\anadido.bmp",635,419);
			S=mousexy();
			if(S.x>635&&S.x<920&&S.y>419&&S.y<463)
				{C[2]=1;}
			else
				ValidarCord(S,"C:\\Proyecto\\HistoriaDeUnaMujerS.bmp",C);
		}
		if(band==4)
		{
			MenuMujeron();
			if(C[3]==1)
				imagen("C:\\Proyecto\\anadido.bmp",635,419);
			S=mousexy();
			setcolor(0);
			bar(635,419,920,463);
			if(S.x>635&&S.x<920&&S.y>419&&S.y<463)
				{C[3]=1;}
			else
				ValidarCord(S,"C:\\Proyecto\\MujeronS.bmp",C);
		}
		if(band==5)
		{
			MenuObrasEscogidas();
			if(C[4]==1)
				imagen("C:\\Proyecto\\anadido.bmp",635,419);
			S=mousexy();
			if(S.x>635&&S.x<920&&S.y>419&&S.y<463)
				{C[4]=1;}
			else
				ValidarCord(S,"C:\\Proyecto\\ObrasEscogidasS.bmp",C);
		}
		if(band==6)
		{
			MenuUnLlamadoALaFelicidad();
			if(C[5]==1)
				imagen("C:\\Proyecto\\anadido.bmp",635,419);
			S=mousexy();
			if(S.x>635&&S.x<920&&S.y>419&&S.y<463)
				{C[5]=1;}
			else
				ValidarCord(S,"C:\\Proyecto\\UnLlamadoALaFelicidadS.bmp",C);
		}
		if(band==7)
		{
			MenuMas18();
			if(C[6]==1)
				imagen("C:\\Proyecto\\anadido.bmp",635,419);
			S=mousexy();
			if(S.x>635&&S.x<920&&S.y>419&&S.y<463)
				{C[6]=1;}
			else
				ValidarCord(S,"C:\\Proyecto\\+18S.bmp",C);
		}
		if(band==8)
		{
			MenuAtrapadosEnElLaberinto();
			if(C[7]==1)
				imagen("C:\\Proyecto\\anadido.bmp",635,419);
			S=mousexy();
			if(S.x>635&&S.x<920&&S.y>419&&S.y<463)
				{C[7]=1;}
			else
				ValidarCord(S,"C:\\Proyecto\\AtrapadosEnElLaberintoS.bmp",C);
		}
		if(band==9)
		{
			MenuNoVivirasParaTuProximoCumpleanos();
			if(C[8]==1)
				imagen("C:\\Proyecto\\anadido.bmp",635,419);
			S=mousexy();
			if(S.x>635&&S.x<920&&S.y>419&&S.y<463)
				{C[8]=1;}
			else
				ValidarCord(S,"C:\\Proyecto\\NoVivirasParaTuProximoCumpleanosS.bmp",C);
		}
		if(band==10)
		{
			MenuLascivias();
			if(C[9]==1)
				imagen("C:\\Proyecto\\anadido.bmp",635,419);
			S=mousexy();
			if(S.x>635&&S.x<920&&S.y>419&&S.y<463)
				{C[9]=1;}
			else
				ValidarCord(S,"C:\\Proyecto\\LasciviaS.bmp",C);
		}
		if(band==11)
		{
			MenuMariaInes();
			if(C[10]==1)
				imagen("C:\\Proyecto\\anadido.bmp",635,419);
			S=mousexy();
			if(S.x>635&&S.x<920&&S.y>419&&S.y<463)
				{C[10]=1;}
			else
				ValidarCord(S,"C:\\Proyecto\\MariaInesS.bmp",C);
		}
		if(band==12)
		{
			MenuStevenson();
			if(C[11]==1)
				imagen("C:\\Proyecto\\anadido.bmp",635,419);
			S=mousexy();
			if(S.x>635&&S.x<920&&S.y>419&&S.y<463)
				{C[11]=1;}
			else
				ValidarCord(S,"C:\\Proyecto\\StevensonS.bmp",C);
		}
		if(band==13)
		{
			MenuLibros();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\OpcionesAcademicos2.bmp",C);
		}
		if(band==14)
		{
			MenuAudiolibros();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\electronicos2.bmp",C);
		}
		if(band==15)
		{
			MenuProductos();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\productos2.bmp",C);
		}
		if(band==16)
		{
			MenuOportunidades();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\oportunidades.bmp",C);
		}
		if(band==17)
		{
			MenuServicios();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\Servicios.bmp",C);
		}
		if(band==18)
		{
			MenuMonederos();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\monederos2.bmp",C);
		}
		if(band==19)
		{
			MenuSucursales();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\Sucursales2.bmp",C);
		}
		if(band==20)
		{
			MenuCatalogos();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\catalogos.bmp",C);
		}
		if(band==21)
		{
			MenuElNegrito();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\ElnegritoS.bmp",C);
		}
		if(band==22)
		{
			MenuDerechosInternacionales();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\DerechosInternacionalesS.bmp",C);
		}
		if(band==23)
			flag=iniciarsesion();
		if(band==24)
			{B=buscador(20,60,250,100);
			if(strcmp(B.S,"Moby dick")==0){band=2;}
			if(strcmp(B.S,"Historia de una mujer")==0){band=3;}
			if(strcmp(B.S,"Mujeron")==0){band=4;}
			if(strcmp(B.S,"Obras escojidas")==0){band=5;}
			if(strcmp(B.S,"Un llamado a la felicidad")==0){band=6;}
			if(strcmp(B.S,"+18")==0){band=7;}
			if(strcmp(B.S,"Atrapados en el laberinto")==0){band=8;}
			if(strcmp(B.S,"No viviras para tu proximo cumpleaños")==0){band=9;}
			if(strcmp(B.S,"Lascivia")==0){band=10;}
			if(strcmp(B.S,"Maria ines")==0){band=11;}//M
			if(strcmp(B.S,"Stevenson")==0){band=12;}
			}
		if(band==25)
			carrito(C);
	}while(4);
}
void seleccionarlibroscomprador(int C[15])//vendedor
{
	struct coordenadas S;
	struct texto B;
	int band,A[12];
	MenuComprador();
	imagen("C:\\Proyecto\\ModificarInventario.bmp",875,55);//rectangle(875,55,1025,134);
	band=0;
	do{		
		while(band!=1&&band!=2&&band!=3&&band!=4&&band!=5&&band!=6&&band!=7&&band!=8&&band!=9&&band!=10&&band!=11&&band!=12&&band!=13&&band!=14&&band!=15&&band!=16&&band!=17&&band!=18&&band!=19&&band!=20&&band!=21&&band!=22&&band!=23&&band!=24)
		{
			if(band==0)
				S=mousexy();
			if(S.x>0&&S.x<32&&S.y>0&&S.y<24)//Atras
				band=1;
			if(S.x>20&&S.x<120&&S.y>225&&S.y<410)//MoviDick
				band=2;
			if(S.x>140&&S.x<240&&S.y>225&&S.y<410)//HistoriaDeUnaMujer
				band=3;
			if(S.x>260&&S.x<360&&S.y>225&&S.y<410)//Mujeron
				band=4;
			if(S.x>380&&S.x<480&&S.y>225&&S.y<410)//ObrasEscogidas
				band=5;
			if(S.x>500&&S.x<600&&S.y>225&&S.y<410)//UnLlamadoALaFelicidad
				band=6;
			if(S.x>620&&S.x<720&&S.y>225&&S.y<410)//Mas18
				band=7;
			if(S.x>740&&S.x<840&&S.y>225&&S.y<410)//AtrapadosEnElLaberinto
				band=8;
			if(S.x>860&&S.x<960&&S.y>225&&S.y<410)//NoVivirasParaTuProximoCumpleaños
				band=9;
			if(S.x>980&&S.x<1080&&S.y>225&&S.y<410)//rectangle(980,225,1080,410)
				band=10;
			if(S.x>1100&&S.x<1200&&S.y>225&&S.y<410)//MariaInes
				band=11;
			if(S.x>1220&&S.x<1320&&S.y>225&&S.y<410)//Stevenson
				band=12;
			if(S.x>0&&S.x<90&&S.y>150&&S.y<212)//rectangle(0,150,90,212);//LIBROS
				band=13;
			if(S.x>90&&S.x<350&&S.y>150&&S.y<212)//rectangle(90,150,350,212);//audiolibros
				band=14;
			if(S.x>350&&S.x<500&&S.y>150&&S.y<212)//rectangle(350,150,500,212);//productos
				band=15;
			if(S.x>500&&S.x<690&&S.y>150&&S.y<212)//rectangle(500,150,690,212);oportunidades
				band=16;
			if(S.x>690&&S.x<830&&S.y>150&&S.y<212)//rectangle(690,150,830,212);servicios
				band=17;
			if(S.x>830&&S.x<980&&S.y>150&&S.y<212)//rectangle(830,150,980,212);monederos
				band=18;
			if(S.x>980&&S.x<1130&&S.y>150&&S.y<212)//rectangle(980,150,1130,212);sucursales
				band=19;
			if(S.x>1130&&S.x<1300&&S.y>150&&S.y<212)//rectangle(1130,150,1300,212);catalogos
				band=20;
			if(S.x>15&&S.x<465&&S.y>420&&S.y<634)//rectangle(15,420,465,634);Recomendados del mes
				band=21;
			if(S.x>465&&S.x<910&&S.y>420&&S.y<634)//rectangle(465,420,915,634);Recomendados del mes
				band=22;
			if(S.x>875&&S.x<1025&&S.y>55&&S.y<134)//rectangle(875,55,1025,134);ModificarInventario
				band=23;
			if(S.x>20&&S.x<300&&S.y>55&&S.y<109)//rectangle(20,55,300,109);Barra buscador
				band=24;
		}
		if(band==1)
			S=MenuInicio();
		if(band==2)
		{
			MenuMoviDick();
			ValidarCord(S,"C:\\Proyecto\\MoviDickS.bmp",A);
		}
		if(band==3)
		{
			MenuHistoriaDeUnaMujer();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\HistoriaDeUnaMujerS.bmp",A);
		}
		if(band==4)
		{
			MenuMujeron();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\MujeronS.bmp",A);
		}
		if(band==5)
		{
			MenuObrasEscogidas();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\ObrasEscogidasS.bmp",A);
		}
		if(band==6)
		{
			MenuUnLlamadoALaFelicidad();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\UnLlamadoALaFelicidadS.bmp",A);
		}
		if(band==7)
		{
			MenuMas18();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\+18S.bmp",A);
		}
		if(band==8)
		{
			MenuAtrapadosEnElLaberinto();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\AtrapadosEnElLaberintoS.bmp",A);
		}
		if(band==9)
		{
			MenuNoVivirasParaTuProximoCumpleanos();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\NoVivirasParaTuProximoCumpleanosS.bmp",A);
		}
		if(band==10)
		{
			MenuLascivias();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\LasciviaS.bmp",A);
		}
		if(band==11)
		{
			MenuMariaInes();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\MariaInesS.bmp",A);
		}
		if(band==12)
		{
			MenuStevenson();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\StevensonS.bmp",A);
		}
		if(band==13)
		{
			MenuLibros();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\OpcionesAcademicos2.bmp",A);
		}
		if(band==14)
		{
			MenuAudiolibros();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\electronicos2.bmp",A);
		}
		if(band==15)
		{
			MenuProductos();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\productos2.bmp",A);
		}
		if(band==16)
		{
			MenuOportunidades();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\oportunidades.bmp",A);
		}
		if(band==17)
		{
			MenuServicios();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\Servicios.bmp",A);
		}
		if(band==18)
		{
			MenuMonederos();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\monederos2.bmp",A);
		}
		if(band==19)
		{
			MenuSucursales();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\Sucursales2.bmp",A);
		}
		if(band==20)
		{
			MenuCatalogos();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\catalogos.bmp",A);
		}
		if(band==21)
		{
			MenuElNegrito();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\ElnegritoS.bmp",A);
		}
		if(band==22)
		{
			MenuDerechosInternacionales();
			S=mousexy();
			ValidarCord(S,"C:\\Proyecto\\DerechosInternacionalesS.bmp",A);
		}
		if(band==23)
			MenuModificarEliminar();
		if(band==24)
			{B=buscador(20,55,300,109);
			if(strcmp(B.S,"Moby dick")==0){band=2;}
			if(strcmp(B.S,"Historia de una mujer")==0){band=3;}
			if(strcmp(B.S,"Mujeron")==0){band=4;}
			if(strcmp(B.S,"Obras escojidas")==0){band=5;}
			if(strcmp(B.S,"Un llamado a la felicidad")==0){band=6;}
			if(strcmp(B.S,"+18")==0){band=7;}
			if(strcmp(B.S,"Atrapados en el laberinto")==0){band=8;}
			if(strcmp(B.S,"No viviras para tu proximo cumpleaños")==0){band=9;}
			if(strcmp(B.S,"Lascivia")==0){band=10;}
			if(strcmp(B.S,"Maria ines")==0){band=11;}//M
			if(strcmp(B.S,"Stevenson")==0){band=12;}
			}
	}while(4);
}
void carrito(int A[15])//Crea la lista de libros que se agregaron al carrito, la muestra y procede al pago
//la funcion carrito recibe esa cadena de enteros y con estos crea una lista
{
	struct book *head,*aux1,*aux2;
	struct libro Y;
	struct coordenadas H;
	FILE *fs;
	int z,B[15];
	char S[10];
	float p=0.0;
	MenuDeArriba();
	fs=Abrir_Archivo("C:\\Proyecto\\Base","rb");
	head=crear();
	for(z=0;z<=15;z++){B[z]=0;}
	z=300;
	do
	{
		fread(&Y,sizeof(struct libro),1,fs);
		if(strcmp(Y.T,"Moby dick")==0&&A[1]==1)//con estos if me detecta los libros que agregue al carrito y en lo siguiente va a crear una lista
			{libro_a_book(Y,head);break;}
		if(strcmp(Y.T,"Historia de una mujer")==0&&A[2]==1)
			{libro_a_book(Y,head);break;}
		if(strcmp(Y.T,"Mujeron")==0&&A[3]==1)
			{libro_a_book(Y,head);break;}
		if(strcmp(Y.T,"Obras escojidas")==0&&A[4]==1)
			{libro_a_book(Y,head);break;}
		if(strcmp(Y.T,"Un llamado a la felicidad")==0&&A[5]==1)
			{libro_a_book(Y,head);break;}
		if(strcmp(Y.T,"+18")==0&&A[6]==1)
			{libro_a_book(Y,head);break;}
		if(strcmp(Y.T,"Atrapados en el laberinto")==0&&A[7]==1)
			{libro_a_book(Y,head);break;}
		if(strcmp(Y.T,"No viviras para tu proximo cumpleaños")==0&&A[8]==1)
			{libro_a_book(Y,head);break;}
		if(strcmp(Y.T,"Lascivia")==0&&A[9]==1)
			{libro_a_book(Y,head);break;}
		if(strcmp(Y.T,"Maria ines")==0&&A[10]==1)
			{libro_a_book(Y,head);break;}
		if(strcmp(Y.T,"Stevenson")==0&&A[11]==1)
			{libro_a_book(Y,head);break;}
	}while(!feof(fs));
	rewind(fs);
	aux1=head;
	do
	{
		fread(&Y,sizeof(struct libro),1,fs);//busca los titulos en la base de datos, saca la informacion de la base de datos y saca una lista doblemente ligada, 
		//luego imprime los titulos y el precio de la base de datos 
		if(strcmp(Y.T,"Moby dick")==0&&A[1]==1&&strcmp(head->T,"Moby dick")!=0)
			{aux2=crear();libro_a_book(Y,aux2);aux1->sig=aux2;aux2->ant=aux1;aux1=aux2;}
		if(strcmp(Y.T,"Historia de una mujer")==0&&A[2]==1&&strcmp(head->T,"Historia de una mujer")!=0)
			{aux2=crear();libro_a_book(Y,aux2);aux1->sig=aux2;aux2->ant=aux1;aux1=aux2;}
		if(strcmp(Y.T,"Mujeron")==0&&A[3]==1&&strcmp(head->T,"Mujeron")!=0)
			{aux2=crear();libro_a_book(Y,aux2);aux1->sig=aux2;aux2->ant=aux1;aux1=aux2;}
		if(strcmp(Y.T,"Obras escojidas")==0&&A[4]==1&&strcmp(head->T,"Obras escojidas")!=0)
			{aux2=crear();libro_a_book(Y,aux2);aux1->sig=aux2;aux2->ant=aux1;aux1=aux2;}
		if(strcmp(Y.T,"Un llamado a la felicidad")==0&&A[5]==1&&strcmp(head->T,"Un llamado a la felicidad")!=0)
			{aux2=crear();libro_a_book(Y,aux2);aux1->sig=aux2;aux2->ant=aux1;aux1=aux2;}
		if(strcmp(Y.T,"+18")==0&&A[6]==1&&strcmp(head->T,"+18")!=0)
			{aux2=crear();libro_a_book(Y,aux2);aux1->sig=aux2;aux2->ant=aux1;aux1=aux2;}
		if(strcmp(Y.T,"Atrapados en el laberinto")==0&&A[7]==1&&strcmp(head->T,"Atrapados en el laberinto")!=0)
			{aux2=crear();libro_a_book(Y,aux2);aux1->sig=aux2;aux2->ant=aux1;aux1=aux2;}
		if(strcmp(Y.T,"No viviras para tu proximo cumpleaños")==0&&A[8]==1&&strcmp(head->T,"No viviras para tu proximo cumpleaños")!=0)
			{aux2=crear();libro_a_book(Y,aux2);aux1->sig=aux2;aux2->ant=aux1;aux1=aux2;}
		if(strcmp(Y.T,"Lascivia")==0&&A[9]==1&&strcmp(head->T,"Lascivia")!=0)
			{aux2=crear();libro_a_book(Y,aux2);aux1->sig=aux2;aux2->ant=aux1;aux1=aux2;}
		if(strcmp(Y.T,"Maria ines")==0&&A[10]==1&&strcmp(head->T,"Maria ines")!=0)
			{aux2=crear();libro_a_book(Y,aux2);aux1->sig=aux2;aux2->ant=aux1;aux1=aux2;}
		if(strcmp(Y.T,"Stevenson")==0&&A[11]==1&&strcmp(head->T,"Stevenson")!=0)
			{aux2=crear();libro_a_book(Y,aux2);aux1->sig=aux2;aux2->ant=aux1;aux1=aux2;}
	}while(!feof(fs));
	fclose(fs);
	MenuDeArriba();
	aux1=head;
	setbkcolor(15);
	setcolor(COLOR(150,150,150));
	settextstyle(8,0,2);
	outtextxy(150,250,"Resumen de compra");
	do
	{//hace la suma de los precios
		itoa(aux1->s,S,10);
		outtextxy(50,z,aux1->T); outtextxy(400,z,S);
		p+=aux1->s;
		z+=20;
		aux1=aux1->sig;
	}while(aux1!=NULL);
	setfillstyle(1,COLOR(150,150,150));
	outtextxy(50,z+10,"Total:");
	line(50,z+8,450,z+8);
	itoa(p,S,10);
	outtextxy(400,z+10,S);
	bar(340,z+40,390,z+60);
	setbkcolor(COLOR(200,200,200));
	outtextxy(340,z+40,"Continuar");
	do
		H=mousexy();
	while(H.x>340&&H.x<390&&H.y>z+40&&H.y<z+60);
	aux1=head;
	setbkcolor(15);
	outtextxy(600,300,"Numero de tarjeta");
	rectangle(600,320,1100,360);
	escritura(605,320,1090,350);
	outtextxy(600,370,"Codigo de seguridad");
	rectangle(600,390,1100,430);
	escritura(605,390,1090,420);
	outtextxy(600,440,"Direccion de envio");
	rectangle(600,460,1100,500);
	escritura(605,460,1090,490);
	setfillstyle(1,COLOR(100,100,100));
	bar(990,520,1040,540);
	setbkcolor(COLOR(200,200,200));
	outtextxy(990,520,"Confirmar");//al dar clic aqui ejecuta la funcion comprar
	do
		H=mousexy();
	while(H.x>950&&H.x<1040&&H.y>520&&H.y<540);
	do
	{
		comprar(aux1->NI);//esta funcion va a comprar los libros, es decir los elimina de la base de datos
		aux1=aux1->sig;
	}while(aux1!=NULL);
	outtextxy(350,600,"Tu compra fue realizada con exito, que la disfrutes!");
	do
		H=mousexy();
	while(H.x>0&&H.x<32&&H.y>0&&H.y<24);
	seleccionarlibros(B);
}
void comprar (int s)//"Vende" el libro de numero de inventario s
{
	struct libro Y;
	struct coordenadas S;
	FILE *fs,*fy;
	fs=Abrir_Archivo("C:\\Proyecto\\Base","rb+");
	fy=Abrir_Archivo("C:\\Proyecto\\Basetemp","wb");
	do{
		fread(&Y,sizeof(struct libro),1,fs);
		//S.A;S.AP;S.C;S.E;S.ED;S.I;S.ISBN;S.NI;S.P;S.s;S.T;
		if(Y.NI!=s&&!feof(fs))
			fwrite(&Y,sizeof(struct libro),1,fy);
	}while(!feof(fs));
	fclose(fy);
	fclose(fs);
	system("copy C:\\Proyecto\\Basetemp C:\\Proyecto\\Base");
	system("del C:\\Proyecto\\Basetemp");
}
void MenuDeArriba(void)
{
	cleardevice();
	setfillstyle(SOLID_FILL,15);//pantalla blanca
	floodfill(0,0,5);	
	imagen("C:\\Proyecto\\PorruaLog.bmp",533,10);
	imagen("C:\\Proyecto\\flechaAtras.bmp",0,0);
	imagen("C:\\Proyecto\\PorruaIso.bmp",1250,30);
	imagen("C:\\Proyecto\\buscador.bmp",20,55);
	imagen("C:\\Proyecto\\Usuario.bmp",1200,45);
	imagen("C:\\Proyecto\\carrito.bmp",1010,40);
	imagen("C:\\Proyecto\\comunidadporrua.bmp",1100,45);
	imagen("C:\\Proyecto\\opciones.bmp",0,150);
	setcolor(COLOR(236,103,26));
	setfillstyle(SOLID_FILL,COLOR(236,103,26));
	rectangle(0,200,1360,220);
	floodfill(140,210,COLOR(236,103,26));
}
void MenuModificarEliminar(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\opcionesVendedor.bmp",170,270);
	struct coordenadas A;
	int flag,band,B[15];
	for(band=0;band<=15;band++){B[band]=0;}
	band=0;
	do
	{
		if(band==0)
			A=mousexy();
		if(A.x>0&&A.x<32&&A.y>0&&A.y<24)//Atras
			band=1;
		if(A.x>1200&&A.x<1260&&A.y>45&&A.y<105)//validar iniciar sesion
			band=2;
		if(A.x>170&&A.x<620&&A.y>270&&A.y<432)//Agregar libro(170,270,620,432)
			band=3;
		if(A.x>620&&A.x<1070&&A.y>270&&A.y<432)//Modificar libro(620,270,1070,432)
			band=4;
		if(A.x>470&&A.x<770&&A.y>432&&A.y<594)//Eliminar libro(470,432,770,594)
			band=5;
	}while(band!=1&&band!=2&&band!=3&&band!=4&&band!=5);
	if(band==1)
		seleccionarlibroscomprador(B);
	if(band==2)
		flag=iniciarsesion();	
	if(band==3)
	{
		agregar_titulo();
		//imprimirbd();	
	}
	if(band==4)
		modificar_titulo();
	if(band==5)
		eliminar_titulo();			
}
void MenuDerechosInternacionales(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\DerechosInternacionales.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);	
}
void MenuElNegrito(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\ElNegrito.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);	
}
void MenuCatalogos(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\catalogos2.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);	
}
void MenuSucursales(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\Sucursales.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);	
}
void MenuMonederos(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\Monederos.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);	
}
void MenuServicios(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\Servicios2.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);	
}
void MenuOportunidades(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\recomendaciones1.bmp",30,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);	
}
void MenuProductos(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\productos.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);	
}
void MenuAudiolibros(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\electronicos.bmp",30,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);	
}
void MenuLibros(void)
{
	struct coordenadas A;
	MenuDeArriba();
	imagen("C:\\Proyecto\\OpcionesLibros.bmp",50,250);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);
	A=mousexy();
	if(A.x>50&&A.x<265&&A.y>250&&A.y<605)
		MenuCategorias();
	if(A.x>265&&A.x<480&&A.y>250&&A.y<605)
		MenuNuestrosSellos();
	if(A.x>480&&A.x<695&&A.y>250&&A.y<605)
		MenuSecciones();
	if(A.x>695&&A.x<910&&A.y>250&&A.y<605)
		MenuAcademicos();
}
void MenuAcademicos(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\OpcionesAcademicos1.bmp",30,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);	
}
void MenuSecciones(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\leidos.bmp",30,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);
}
void MenuNuestrosSellos(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\OpcionesSellos.bmp",150,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);
}
void MenuCategorias(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\novedades1.bmp",30,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);
}

void MenuLascivias(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\LasciviaC.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);
}
void MenuUnLlamadoALaFelicidad(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\UnLlamadoALaFelicidadC.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);
}
void MenuMas18(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\+18C.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);
}
void MenuAtrapadosEnElLaberinto(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\AtrapadosEnElLaberintoC.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);
}
void MenuHistoriaDeUnaMujer(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\HistoriaDeUnaMujerC.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);
}
void MenuMariaInes(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\MariaInesC.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);
}
void MenuMoviDick(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\MoviDickC.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);
}
void MenuMujeron(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\MujeronC.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);
}
void MenuNoVivirasParaTuProximoCumpleanos(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\NoVivirasParaTuProximoCumpleañosC.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);
}
void MenuObrasEscogidas(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\ObrasEscogidasC.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);
}
void MenuStevenson(void)
{
	MenuDeArriba();
	imagen("C:\\Proyecto\\StevensonC.bmp",130,230);
	imagen("C:\\Proyecto\\siguiente.bmp",1184,424);
}

struct coordenadas MenuInicio(void)
{
	cleardevice();
	int band,flag,B[15];
	struct coordenadas c;
	for(band=0;band<=15;band++){B[band]=0;}
	setfillstyle(SOLID_FILL,15);//pantalla blanca
	setfillstyle(1,15);
	floodfill(1,1,1);
	imagen("C:\\Proyecto\\PorruaLog.bmp",533,10);
	//Negro
	setcolor(COLOR(0,0,0));
	setfillstyle(SOLID_FILL,COLOR(0,0,0));
	rectangle(10,150,1350,200);
	floodfill(90,170,COLOR(0,0,0));
	//amarillas
	setcolor(COLOR(254,242,0));
	setfillstyle(SOLID_FILL,COLOR(254,242,0));
	rectangle(80,0,110,720);
	floodfill(100,100,COLOR(254,242,0));
	rectangle(1260,0,1290,720);
	floodfill(1270,100,COLOR(254,242,0));
	//naranjas
	setcolor(COLOR(236,103,26));
	setfillstyle(SOLID_FILL,COLOR(236,103,26));
	rectangle(10,200,1350,220);
	floodfill(140,210,COLOR(236,103,26));
	//gris
	setcolor(COLOR(127,127,127));
	setfillstyle(SOLID_FILL,COLOR(127,127,127));
	rectangle(130,0,160,720);
	floodfill(140,100,COLOR(127,127,127));
	rectangle(1192,0,1222,720);
	floodfill(1193,100,COLOR(127,127,127));
	imagen("C:\\Proyecto\\salir.bmp",950,500);
	imagen("C:\\Proyecto\\comodeseaingresar.bmp",442,220);
	imagen("C:\\Proyecto\\comprador_vendedor.bmp",510,310);
	
	band=0;
	do
	{
		if(band==0)
			c=mousexy();
		//Salir
		if((c.x>950 && c.x<1130) && (c.y>500 && c.y<598))//rectangle(950,500,1130,598);
			band=1;
		//comprador
		if((c.x>510 && c.x<761) && (c.y>310 && c.y<453))//rectangle(510,310,761,453)
			band=2;
		//vendedor
		if((c.x>510 && c.x<761) && (c.y>450 && c.y<590))//rectangle(510,450,761,590)
			band=3;
	}while(band!=1 && band!=2 && band!=3);
	if(band==1)
		closegraph();
	if(band==2)
		seleccionarlibros(B);
	if(band==3)
	{
		flag=iniciarsesion();
		do
		{
			if(flag==1)//es decir, si ingrese el ususrio y contraseña correctos entre en el modo administrador
				seleccionarlibroscomprador(B);//modo admi
			if(flag==0)//entre como comprador, me pide volver a intentar entrar como administrador
				flag=iniciarsesion();
		}while(flag!=0||flag!=1);	
	}
	struct coordenadas A;
	A=mousexy();
	return A;
}
int iniciarsesion(void)
{
	cleardevice();
	int a,y,s;
	struct texto U,C;
	struct coordenadas A;
	A.x=-1;A.y=-1;
	for(s=1360;s>-640;s-=80)
	{
		y=s;
		setfillstyle(1,COLOR(40,40,40));
		for(a=0;a<=640;a+=80)
		{
			if(y>0&&y<=1360)
				bar(y-80,a,y,a+80);
			y+=80;
		}
		delay(10);
		setfillstyle(1,15);
		y=s;
		for(a=0;a<=640;a+=80)
		{
			if(y>0&&y<=1360)
				bar(y-80,a,y,a+80);
			y+=80;
		}
	}
	setcolor(COLOR(70,70,70));
	MenuDeArriba();
	imagen("C:\\Proyecto\\Usuario.bmp",650,240);
	imagen("C:\\Proyecto\\Iniciar sesion.bmp",580,305);
	setfillstyle(1,0);
	bar(509,380,811,430);
	imagen("C:\\Proyecto\\Nombre de usuario.bmp",510,381);
	bar(509,450,811,500);
	imagen("C:\\Proyecto\\Contrasena.bmp",510,451);
	setbkcolor(15);
	s=2;
	do
	{
		setfillstyle(1,15);
		A=mousexy();	
		if(A.x>=500&&A.x<=860&&A.y>=380&&A.y<=430)//iniciar sesion
		{
			bar(510,381,810,429);
			U=escritura(515,381,800,415);
			a=1;//Verifica que se haya ingresado un usuario
		}
		if(A.x>0&&A.x<32&&A.y>0&&A.y<24)//salir
			MenuInicio();
		if(A.x>=500&&A.x<=860&&A.y>=450&&A.y<=500)//congraseña
		{
			bar(510,451,810,499);
			C=escritura(515,451,800,485);
			y=5;//Verifica que se haya ingresado una contraseña
		}
		if(strcmp(U.S,"admin")==0&&strcmp(C.S,"271093")==0)//Usuario y contraseña del administrador
			s=1;
		if(strcmp(U.S,"admin")!=0&&a==1&&y==5)//Caso en el que ya se ingresó usuario y contraseña pero no los del admin
			s=0;
	}while(s==2);
	return s;//s=1: Modo administrador, s=0: Modo usuario
}
struct texto escritura(int x,int y,int x1,int y1)//Imprime lo que se vaya escribiendo en la caja de texto con esquinas x,y,x1,y1
{
	char s;
	struct texto S;
	int a;
	fflush(stdin);
	for(a=0;a<=100;a++)
		S.S[a]=0;
	a=0;
	setfillstyle(1,15);
	//bar(x,y,x1,y1);
	setcolor(COLOR(150,150,150));
	settextstyle(8,0,2);
	do
	{
		s=getch();//Enter:13, Borrar:8
		fflush(stdin);
		if(s!=13&&s!=8)
		{
			S.S[a]=s;
			a++;
		}
		if(s==8&&a>0)
		{
			bar(x,y+10,x1,y1+10);
			S.S[a-1]=0;
			a--;
		}
		outtextxy(x,y+10,S.S);
	}while(s!=13);
	return S;
}
struct coordenadas mousexy (void)
{
	struct coordenadas S;
	clearmouseclick(WM_LBUTTONDOWN);
	while(!ismouseclick(WM_LBUTTONDOWN))
		delay(10);
	getmouseclick(WM_LBUTTONDOWN,S.x,S.y);
	return S;
}
void ValidarCord(struct coordenadas c, char A[80],int B[15])
{
	if((c.x>0 && c.x<32) && (c.y>0 && c.y<24))//Atras
		seleccionarlibros(B);	
	if((c.x>1184 && c.x<1214) && c.y>424 && c.y<454)//siguiente (sinopsis)
	{
		MenuDeArriba();
		imagen(A,140,240);
		c=mousexy();
		ValidarCord(c,A,B);
	}	
}
void imagen(char A[80],int x,int y)
{
	FILE *fp;
	int renglon=0,control,buffersize,ancho,alto,j,i;
	unsigned char *buffer;
	fp=Abrir_Archivo(A,"rb");
	fseek(fp,10,SEEK_SET);
	fread(&control,4,1,fp);
	fseek(fp,18,SEEK_SET);
	fread(&ancho,4,1,fp);
	fseek(fp,22,SEEK_SET);
	fread(&alto,4,1,fp);
	renglon=((3*ancho)+3)/4*4;
	buffersize=(ancho*alto+1)*4;
	buffer=(unsigned char *)malloc(buffersize);
	if(!buffer){
		printf("\nError de buffer\nPulse una tecla para continuar...");
		getch();
		exit(1);
	}
	fseek(fp,control,SEEK_SET);
	control=fread(buffer,1,renglon*alto,fp);
	if(control!=renglon*alto){
		printf("\nError de lectura de buffer\nPulse una tecla para continuar...");
		getch();
		exit(1);
	}
	for(i=alto-1;i>=0;i--){
		for(j=ancho-1;j>=0;j--){
			buffer[4*(ancho*i+j+1)+3]=0;
			buffer[4*(ancho*i+j+1)+2]=buffer[i*renglon+3*j+2];
			buffer[4*(ancho*i+j+1)+1]=buffer[i*renglon+3*j+1];
			buffer[4*(ancho*i+j+1)]=buffer[i*renglon+3*j];	
		}
	}
	buffer[0]=ancho&0xFF;
	buffer[1]=(ancho>>8)&0xFF;
	buffer[2]=alto&0xFF;
	buffer[3]=(alto>>8)&0xFF;
	putimage(x,y,buffer,0);
	free(buffer);
}
void agregar_titulo(void)
{
	struct libro S,Y;
	struct texto H;
	struct coordenadas B;
	int flag,flagNI;
	FILE*fs;
	char A[20];
	settextstyle(1,0,1);
	MenuDeArriba();
	do
	{
		setfillstyle(1,15);
		//bar(150,300,1000,500);
		setcolor(0);
		setbkcolor(15);
		bar(200,250,1200,650);
		outtextxy(200,250,"Titulo: ");
		H=escritura(360,240,560,260); strcpy(S.T,H.S);
		setcolor(0);
		outtextxy(200,280,"Autor: ");
		H=escritura(360,270,560,290); strcpy(S.A,H.S);
		setcolor(0);
		outtextxy(200,310,"Editorial: ");
		H=escritura(360,300,560,320); strcpy(S.E,H.S);
		setcolor(0);
		outtextxy(200,340,"Año");
		H=escritura(360,330,560,350); strcpy(A,H.S);
		S.AP=atoi(A);
		setcolor(0);
		outtextxy(200,370,"Edicion: ");
		H=escritura(360,360,560,380); strcpy(S.ED,H.S);
		setcolor(0);
		outtextxy(200,400,"ISBN: ");
		H=escritura(360,390,560,410); strcpy(S.ISBN,H.S);
		setcolor(0);
		outtextxy(200,430,"Pais");
		H=escritura(360,420,560,440); strcpy(S.P,H.S);
		setcolor(0);
		outtextxy(200,460,"Idioma: ");
		H=escritura(360,450,560,470); strcpy(S.I,H.S);
		setcolor(0);
		outtextxy(200,490,"Precio: ");
		H=escritura(360,480,560,500); strcpy(A,H.S);
		S.s=atof(A);
		setcolor(0);
		outtextxy(200,520,"Coleccion: ");
		H=escritura(360,510,560,530); strcpy(S.C,H.S);
		fs=Abrir_Archivo("C:\\Proyecto\\Base","ab+");//En base se guardará toda la información de la librería
		//Todo esto verifica que no existan dos libros con el mismo número de inventario o que haya uno con número 0
		S.NI=0;
		do
		{
			flagNI=0;
			setcolor(0);
			outtextxy(200,550,"NInventario");
			H=escritura(360,540,560,560);strcpy(A,H.S);
			setcolor(0);
			do
			{
				fread(&Y,sizeof(struct libro),1,fs);
				if(Y.NI==atoi(A))
				{
					flagNI=1;
					break;
				}
			
			}while(!feof(fs));
			rewind(fs);
			if(flagNI==1||atoi(A)==0)
				outtextxy(220,580,"Numero invalido");
			else
			{
			//	bar(520,540,720,560);
				S.NI=atoi(A);
			}
		}while(S.NI==0);//Hasta acá, ya después se escribe en la base de datos
		fwrite(&S,sizeof(struct libro),1,fs);
		fclose(fs);
		setcolor(0);
		//do
		//{
			outtextxy(200,610,"Datos ingresados correctamente, ingresar otro libro?, 1-> si 2-> no");//Esto en realidad debería ir con letreros y mousexy
			H=escritura(1100,590,1150,600);
			strcpy(A,H.S);
			flag=atoi(A);
			setcolor(COLOR(255,255,255));
			setfillstyle(SOLID_FILL,COLOR(255,255,255));
			rectangle(200,580,1300,650);
			floodfill(340,610,COLOR(255,255,255));
			setcolor(15);
			bar(360,240,9000,580);
		//}while(flag==1);
	}while(flag!=2);
	/*bar(100,250,1300,800);
	/*B=mousexy();
	if(B.x>0&&B.x<32&&B.y>0&&B.y<24)//atras*/
		MenuModificarEliminar();
}
void eliminar_titulo(void)//faltaaa
{
	struct libro S,Y;
	struct texto H;
	struct coordenadas B;
	int flag,a;
	char A[20],AP[20],NI[20],P[20];
	FILE*fs,*fy;
	//settextstyle(1,0,1);
	MenuDeArriba();
	do
	{
		A[0]=0;
		setfillstyle(1,15);
		bar(100,250,1300,800);
		fs=Abrir_Archivo("C:\\Proyecto\\Base","rb+");
		flag=0;
		do{
			setfillstyle(1,15);
			setcolor(0);
			setbkcolor(15);
			if(A[0]!=0)
				{outtextxy(200,280,"Libro no encontrado, intenta nuevamente");bar(870,240,950,270);}
			outtextxy(200,250,"Introduce ISBN o #numero de inventario: ");//aparece dos veces este letro
			H=escritura(870,240,950,260);strcpy(A,H.S);
			if(A[0]=='#')//Caso numero de inventario, el primer caracter es #
			{
				flag=1;
				a=0;do{
				A[a]=A[a+1];
				a++;
				}while(A[a]!=0);
			}	
			if(flag==0)//Caso ISBN, ninguno de los otros dos se cumplió
				flag=3;
			do
			{
				fread(&S,sizeof(struct libro),1,fs);
				if(flag==1&&S.NI==atoi(A))
				{
					flag=0;
					break;
				}
				if(flag==2&&strcmp(S.ISBN,A)==0)
				{
					flag=0;
					break;
				}
				if(flag==3&&strcmp(S.T,A)==0)
				{
					flag=0;
					break;
				}
			}while(!feof(fs));
			rewind(fs);
			if(flag==0)
			{
				bar(200,280,800,300);
				/*B=mousexy();
				if(B.x>0&&B.x<32&&B.y>0&&B.y<24)//atras
				MenuModificarEliminar();*/
			}
		}while(flag!=0);
		itoa(S.AP,AP,10);
		itoa(S.NI,NI,10);
		itoa(S.s,P,10);
		outtextxy(300,280,"Este es el libro que deseas eliminar? 1-> Si 2-> No: ");
		setcolor(0);
		outtextxy(400,310,"Titulo: ");
		outtextxy(670,310,S.T);
		setcolor(0);
		outtextxy(400,340,"Autor: ");
		outtextxy(670,340,S.A);
		setcolor(0);
		outtextxy(400,370,"Editorial: ");
		outtextxy(670,370,S.E);
		setcolor(0);
		outtextxy(400,400,"Año de publicacion: ");
		outtextxy(670,400,AP);
		setcolor(0);
		outtextxy(400,430,"Edicion: ");
		outtextxy(670,430,S.ED);
		setcolor(0);
		outtextxy(400,460,"ISBN: ");
		outtextxy(670,460,S.ISBN);
		setcolor(0);
		outtextxy(400,490,"Pais: ");
		outtextxy(670,490,S.P);
		setcolor(0);
		outtextxy(400,520,"Idioma: ");
		outtextxy(670,520,S.I);
		setcolor(0);
		outtextxy(400,550,"Precio: ");
		outtextxy(670,550,P);
		setcolor(0);
		outtextxy(400,580,"Coleccion: ");
		outtextxy(670,580,S.C);
		setcolor(0);
		outtextxy(400,610,"Numero inventario: ");
		outtextxy(670,610,NI);
		H=escritura(970,270,1050,280);strcpy(A,H.S);flag=atoi(A);
		if(flag==1)//si es el libro que quiero modificar
		{	
			fy=Abrir_Archivo("C:\\Proyecto\\Basetemp","wb");
			do
			{
				fread(&Y,sizeof(struct libro),1,fs);
				//S.A;S.AP;S.C;S.E;S.ED;S.I;S.ISBN;S.NI;S.P;S.s;S.T;
				if(Y.NI!=S.NI&&!feof(fs))
					fwrite(&Y,sizeof(struct libro),1,fy);
			}while(!feof(fs));
			fclose(fy);
			fclose(fs);
			system("copy C:\\Proyecto\\Basetemp C:\\Proyecto\\Base");
			system("del C:\\Proyecto\\Basetemp");
			outtextxy(750,450,"---Datos eliminados correctamente---");
			outtextxy(750,480,"¿Eliminar otro? 1-> si 2-> no: ");
			H=escritura(1150,470,1200,490);strcpy(A,H.S);flag=atoi(A);
		}
		else
		{
			fclose(fs);
			outtextxy(750,450,"Buscar otro? 1-> Si 2-> no: ");
			H=escritura(1150,440,1200,460);strcpy(A,H.S);flag=atoi(A);
		}
	}while(flag!=2);
	/*bar(100,250,1300,800);
	B=mousexy();
	if(B.x>0&&B.x<32&&B.y>0&&B.y<24)//atras*/
		MenuModificarEliminar();
}
void modificar_titulo(void)//trabajar en esta
{
	struct libro S,Y;
	struct coordenadas M, B;
	struct texto H;
	int flag,band,a;
	char A[20],AP[20],NI[20],P[20];
	FILE*fs,*fy;
	//settextstyle(1,0,1);
	MenuDeArriba();
	do
	{
		A[0]=0;
		setfillstyle(1,15);
		bar(100,250,1300,800);
		fs=Abrir_Archivo("C:\\Proyecto\\Base","rb+");
		flag=0;
		do
		{
			setfillstyle(1,15);
			setcolor(0);
			setbkcolor(15);
			if(A[0]!=0)
				{outtextxy(200,280,"Libro no encontrado, intenta nuevamente");bar(870,240,950,270);}
			outtextxy(200,250,"Introduce ISBN o #numero de inventario: ");//aparece dos veces este letro
			H=escritura(870,240,950,260);strcpy(A,H.S);
			if(A[0]=='#')
			{
				flag=1;
				a=0;do{
				A[a]=A[a+1];
				a++;
				}while(A[a]!=0);
			}
			if(flag==0)//ISBN
				flag=3;
			do{
				fread(&S,sizeof(struct libro),1,fs);
				if(flag==1&&S.NI==atoi(A))
				{
					flag=0;
					break;
				}
				if(flag==2&&strcmp(S.ISBN,A)==0)
				{
					flag=0;
					break;
				}
				if(flag==3&&strcmp(S.T,A)==0)
				{
					flag=0;
					break;
				}
			}while(!feof(fs));
			rewind(fs);
			if(flag==0)
			{
				bar(200,280,800,300);//aparece este letrero inmediatamente depsues de dar clic
				/*B=mousexy();
				if(B.x>0&&B.x<32&&B.y>0&&B.y<24)//atras
				MenuModificarEliminar();*/
			}
				
		}while(flag!=0);
		itoa(S.AP,AP,10);
		itoa(S.NI,NI,10);
		itoa(S.s,P,10);
		outtextxy(300,280,"Este es el libro que deseas modificar? 1-> Si 2-> No: ");
		setcolor(0);
		outtextxy(400,310,"Titulo: ");
		outtextxy(670,310,S.T);
		setcolor(0);
		outtextxy(400,340,"Autor: ");
		outtextxy(670,340,S.A);
		setcolor(0);
		outtextxy(400,370,"Editorial: ");
		outtextxy(670,370,S.E);
		setcolor(0);
		outtextxy(400,400,"Año de publicacion: ");
		outtextxy(670,400,AP);
		setcolor(0);
		outtextxy(400,430,"Edicion: ");
		outtextxy(670,430,S.ED);
		setcolor(0);
		outtextxy(400,460,"ISBN: ");
		outtextxy(670,460,S.ISBN);
		setcolor(0);
		outtextxy(400,490,"Pais: ");
		outtextxy(670,490,S.P);
		setcolor(0);
		outtextxy(400,520,"Idioma: ");
		outtextxy(670,520,S.I);
		setcolor(0);
		outtextxy(400,550,"Precio: ");
		outtextxy(670,550,P);
		setcolor(0);
		outtextxy(400,580,"Coleccion: ");
		outtextxy(670,580,S.C);
		setcolor(0);
		outtextxy(400,610,"Numero inventario: ");
		outtextxy(670,610,NI);
		H=escritura(970,270,1050,280);strcpy(A,H.S);flag=atoi(A);
		if(flag==1)
		{	 
			fy=Abrir_Archivo("C:\\Proyecto\\Basetemp","wb");
			do
			{
				fread(&Y,sizeof(struct libro),1,fs);
				//S.A;S.AP;S.C;S.E;S.ED;S.I;S.ISBN;S.NI;S.P;S.s;S.T;
				if(Y.NI!=S.NI&&!feof(fs))
					fwrite(&Y,sizeof(struct libro),1,fy);
				if(Y.NI==S.NI&&!feof(fs))//Todo este if modifica el libro buscado
				{
					outtextxy(950,400,"Guardar");			
					do{
						M=mousexy();
						if(M.x>670&&M.x<900&&M.y>310&&M.y<340)
							{bar(670,300,900,330);H=escritura(670,300,900,330); strcpy(Y.T,H.S);}//Título(670,310,900,340)
						if(M.x>670&&M.x<900&&M.y>340&&M.y<370)
							{bar(670,330,900,360);H=escritura(670,330,900,360); strcpy(Y.A,H.S);}//Autor
						if(M.x>670&&M.x<900&&M.y>370&&M.y<400)
							{bar(670,360,900,390);H=escritura(670,360,900,390); strcpy(Y.E,H.S);}//Editorial
						if(M.x>670&&M.x<900&&M.y>400&&M.y<430)
							{bar(670,390,900,420);H=escritura(670,390,900,420); strcpy(A,H.S);//Año
							Y.AP=atoi(A);}
						if(M.x>670&&M.x<900&&M.y>430&&M.y<460)
							{bar(670,420,900,450);H=escritura(670,420,900,450); strcpy(Y.ED,H.S);}//Edicion
						if(M.x>670&&M.x<900&&M.y>460&&M.y<490)
							{bar(670,450,900,480);H=escritura(670,450,900,480); strcpy(Y.ISBN,H.S);}//ISBN
						if(M.x>670&&M.x<900&&M.y>490&&M.y<520)
							{bar(670,480,900,510);H=escritura(670,480,900,510); strcpy(Y.P,H.S);}//Pais
						if(M.x>670&&M.x<900&&M.y>520&&M.y<550)
							{bar(670,510,900,540);H=escritura(670,510,900,540); strcpy(Y.I,H.S);}//Idioma
						if(M.x>670&&M.x<900&&M.y>550&&M.y<580)
							{bar(670,540,900,570);H=escritura(670,540,900,570); strcpy(A,H.S);//Precio
							Y.s=atof(A);}
						if(M.x>670&&M.x<900&&M.y>580&&M.y<620)
							{bar(670,570,900,610);H=escritura(670,570,900,610); strcpy(Y.C,H.S);}//Colección
					}while((M.x<950||M.x>1080)||(M.y<400||M.y>430));//En caso de que se presione el botón guardar se cierra el ciclo y se modifican los datos en la base
					fwrite(&Y,sizeof(struct libro),1,fy);
				}
			}while(!feof(fs));
			fclose(fy);
			fclose(fs);
			system("copy C:\\Proyecto\\Basetemp C:\\Proyecto\\Base");
			system("del C:\\Proyecto\\Basetemp");
			outtextxy(750,450,"---Datos modificados correctamente---");
			outtextxy(750,480,"¿Modificar otro? 1-> si 2-> no: ");
			H=escritura(1150,470,1200,490);strcpy(A,H.S);flag=atoi(A);
		}
		else
		{
			//do
			//{
				fclose(fs);
				outtextxy(750,450,"Buscar otro? 1-> Si 2-> no: ");
				H=escritura(1150,440,1200,460);strcpy(A,H.S);flag=atoi(A);
				setcolor(COLOR(255,255,255));
				setfillstyle(SOLID_FILL,COLOR(255,255,255));
				setcolor(15);
				bar(200,220,1300,650);//pinta una barra blanca para poder ingresar los nuevos datos del nuevo libro, pero no funciona como debe	
			//}while(band!=2);//no funciona el while
		}
	}while(flag!=2);
	/*B=mousexy();
	if(B.x>0&&B.x<32&&B.y>0&&B.y<24)//atras*/
		MenuModificarEliminar();
}
void imprimirbd(void)//imprime toda la base de datos, para revisar cosillas y hacer pruebas
{
	struct libro S;
	FILE*fs;
	fs=Abrir_Archivo("C:\\Proyecto\\Base","rb+");
	do
	{
		fread(&S,sizeof(struct libro),1,fs);
		if(!feof(fs))
		{
			printf("%s\n",S.T);
			printf("%s\n",S.A);
			printf("%i\n",S.AP);
			printf("%s\n",S.C);
			printf("%s\n",S.E);
			printf("%s\n",S.ED);
			printf("%s\n",S.I);
			printf("%s\n",S.ISBN);
			printf("%i\n",S.NI);
			printf("%s\n",S.P);
			printf("%f\n\n\n",S.s);
		}
	}while(!feof(fs));
	fclose(fs);
}
struct texto buscador(int x,int y,int x1,int y1)//Coloca una barra de búsqueda de esquinas (x,y) y (x1,y1) y devuelve el texto que se buscó
{
	char s;
	struct texto S,H;
	struct coordenadas M, B;
	int a, C[15];
	fflush(stdin);
	for(a=0;a<=100;a++)
		S.S[a]=0;
	clearmouseclick(WM_LBUTTONDOWN);//funcion borra lo que esta en el mouse
	a=0;
	setfillstyle(1,COLOR(241,241,241));
	bar(x,y,x1,y1);
	setcolor(COLOR(150,150,150));
	do
	{
		s=getch();//Enter:13, Borrar:8
		fflush(stdin);
		if(!ismouseclick(WM_LBUTTONDOWN))
		{
			if(s!=13&&s!=8)
			{
				S.S[a]=s;
				a++;
				S.S[a]='\0';
			}
			if(s==8&&a>0)
			{
				bar(x,y,x1,y1);
				S.S[a-1]=0;
				a--;
			}
		//	bar(x,y,x1,y1);
			setcolor(COLOR(0,0,0));
			setbkcolor(15);
			settextstyle(1,0,1);
			outtextxy(x+10,y+15,S.S);
			H=sugerencias_busqueda(S.S);
			bar(x,y+60,x+290,y+360);//cuadro donde salen los libros que coincidieron con el libro a buscar
			outtextxy(x+10,y+60,H.A);
			outtextxy(x+10,y+110,H.B);
			outtextxy(x+10,y+160,H.C);
			outtextxy(x+10,y+210,H.D);
			outtextxy(x+10,y+260,H.E);
			outtextxy(x+10,y+310,H.F);}
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,M.x,M.y);
			clearmouseclick(WM_LBUTTONDOWN);
			if(M.x>x&&M.x<x1&&M.y>y+60&&M.y<y+110&&H.A[0]!=0)//En caso de que se de click en alguna de las sugerencias de búsqueda la función devuelve esa sugerencia como el resultado de la búsqueda
				{strcpy(S.S,H.A);outtextxy(x+10,y+15,H.A);}
			if(M.x>x&&M.x<x1&&M.y>y+110&&M.y<y+160&&H.B[0]!=0)
				{strcpy(S.S,H.B);outtextxy(x+10,y+15,H.B);}
			if(M.x>x&&M.x<x1&&M.y>y+160&&M.y<y+210&&H.C[0]!=0)
				{strcpy(S.S,H.C);outtextxy(x+10,y+15,H.C);}
			if(M.x>x&&M.x<x1&&M.y>y+210&&M.y<y+260&&H.D[0]!=0)
				{strcpy(S.S,H.D);outtextxy(x+10,y+15,H.D);}
			if(M.x>x&&M.x<x1&&M.y>y+260&&M.y<y+310&&H.E[0]!=0)
				{strcpy(S.S,H.E);outtextxy(x+10,y+15,H.E);}
			if(M.x>x&&M.x<x1&&M.y>y+310&&M.y<y+360&&H.F[0]!=0)
				{strcpy(S.S,H.F);outtextxy(x+10,y+15,H.F);}
		}
	}while(s!=13);
	/*B=mousexy();
	if(B.x>0&&B.x<32&&B.y>0&&B.y<24)
		seleccionarlibros(C);*/
	return S;
}
struct texto sugerencias_busqueda(char S[100])//Recibe un texto y retorna 6 sugerencias de búsqueda de títulos o autores
{
	struct libro Y;
	FILE*fs;
	struct texto H;
	char T[100],A[100];
	int m,a,flag=0;
	fs=Abrir_Archivo("C:\\Proyecto\\Base","rb");
	m=strlen(S);
	for(a=0;a<=100;a++){T[a]=0;A[a]=0;}
	for(a=0;a<=50;a++){
	H.A[a]=0;H.B[a]=0;H.C[a]=0;H.D[a]=0;H.E[a]=0;H.F[a]=0;}
	if(m>0)
	{
		do
		{
			fread(&Y,sizeof(struct libro),1,fs);
			for(a=0;a<=m-1;a++){//Si S(lo que se escribió) tiene n caracteres, se buscarán coincidencias con los primeros n caracteres de algún autor o título
				T[a]=Y.T[a];
				A[a]=Y.A[a];}
			T[a]='\0';A[a]='\0';;
			if(strcmp(T,S)==0&&!feof(fs)&&strcmp(Y.T,H.A)!=0&&strcmp(Y.T,H.B)!=0&&strcmp(Y.T,H.C)!=0&&strcmp(Y.T,H.D)!=0&&strcmp(Y.T,H.E)!=0)//Coincidencia de título
			{
				if(flag==0)
					strcpy(H.A,Y.T);
				if(flag==1)
					strcpy(H.B,Y.T);
				if(flag==2)
					strcpy(H.C,Y.T);
				if(flag==3)
					strcpy(H.D,Y.T);
				if(flag==4)
					strcpy(H.E,Y.T);
				if(flag==5)
					strcpy(H.F,Y.T);
				flag++;
			}
			/*if(strcmp(A,S)==0&&!feof(fs)&&strcmp(Y.A,H.A)!=0&&strcmp(Y.A,H.B)!=0&&strcmp(Y.A,H.C)!=0&&strcmp(Y.A,H.D)!=0&&strcmp(Y.A,H.E)!=0)//Coincidencia de autor
			{
				if(flag==0)
					strcpy(H.A,Y.A);
				if(flag==1)
					strcpy(H.B,Y.A);
				if(flag==2)
					strcpy(H.C,Y.A);
				if(flag==3)
					strcpy(H.D,Y.A);
				if(flag==4)
					strcpy(H.E,Y.A);
				if(flag==5)
					strcpy(H.F,Y.A);
				flag++;
			}*/
			if(flag==6)//Si ya se obtuvieron 6 sugerencias se rompe el ciclo y deja de buscar
				break;
		}while(!feof(fs));
		fclose(fs);
	}
	return H;
}
FILE *Abrir_Archivo(char A1[100],char A2[4])
{
	FILE *fx;
	fx=fopen(A1,A2);
	if(fx==NULL){
		printf("\nError de apertura de archivo\nPulse una tecla");
		getch();
		exit(1);
	}
	return fx;
}	
void imprime_lista(struct book *head)//Imprime una lista de libros iniciada por head
{
	struct book *aux;
	aux=head;
	do{
		printf("%s\n",aux->T);
		printf("%s\n",aux->A);
		printf("%i\n",aux->AP);
		printf("%s\n",aux->C);
		printf("%s\n",aux->E);
		printf("%s\n",aux->ED);
		printf("%s\n",aux->I);
		printf("%s\n",aux->ISBN);
		printf("%i\n",aux->NI);
		printf("%s\n",aux->P);
		printf("%f\n\n\n",aux->s);
		aux=aux->sig;
	}while(aux!=NULL);
}
void libro_a_book(struct libro Y,struct book *S)//Convierte un tipo libro a un tipo book
{	
strcpy(S->T,Y.T);strcpy(S->A,Y.A);S->AP=Y.AP;strcpy(S->C,Y.C);strcpy(S->E,Y.E);strcpy(S->ED,Y.ED);strcpy(S->I,Y.I);strcpy(S->ISBN,Y.ISBN);S->NI=Y.NI;strcpy(S->P,Y.P);S->s=Y.s;
}
struct book* crear(void)//Crea un nodo para las listas
{
	struct book *nodo;
	nodo=(struct book*)malloc(sizeof(struct book));
	if(nodo==NULL)
	{
		printf("\nError de asignacion de memoria, pulse una tecla para continuar");
		getch();
		exit(1);
	}
	nodo->sig=NULL;
	nodo->ant=NULL;
	return nodo;
}
