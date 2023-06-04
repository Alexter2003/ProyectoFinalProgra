#include <windows.h>
#include <iostream>
#include <direct.h>
#include <stdlib.h>
#include <random>
#include <cstdlib> 
#include <ctime>

#define ANCHO 59
#define ALTO 25
using namespace std;

int altoCasilla = ALTO/5;
int anchoCasilla = (ANCHO*2)/5;
int mitadAltoCasilla = altoCasilla/2;
int mitadAnchoCasilla = anchoCasilla/2;
int movimientoHorizontal = 0;
int movimientoVertical = 0;
int salidaEnY = 0;
int vidas = 7;
bool llegoAlFinal = false;
bool respuestaCorrecta = true;

	void gotoxy(int x,int y)
	{
		HANDLE hCon;
		hCon=GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X=x;
		dwPos.Y=y;
		SetConsoleCursorPosition(hCon,dwPos);
	}
	void recuadro(){
		gotoxy((mitadAnchoCasilla + (anchoCasilla)*4)+5, mitadAltoCasilla + (altoCasilla)*salidaEnY);
		cout<<"SALIDA    ";
		
		for(int j = 0; j<ALTO ; j+=altoCasilla){
			for(int i=0; i<ANCHO*2; i++){
				gotoxy(i,j);
				cout<<char(196);
				gotoxy(i,ALTO);
				cout<<char(196);
			}
		}
		
		for(int j=0; j<(ANCHO*2) ; j+=anchoCasilla){
			
			for(int i=0; i<=ALTO; i++){
				gotoxy(j,i);
				cout<<char(124);
				gotoxy(ANCHO*2-3,i);
				cout<<char(124);
			}
			
		}
		cout<<"\nVidas: "<<vidas;
		
	}
	
	void insertarJugador(int altoCasilla, int anchoCasilla){
		gotoxy( anchoCasilla, altoCasilla);
		cout<<char(220);
	}
		
	void ubicarSalida(){
		srand(static_cast<unsigned int>(time(nullptr)));
		
		int numeroAleatorio = rand() % 5;
		
		salidaEnY = numeroAleatorio;
		
	}
	void ubicarInicio(){
		srand(static_cast<unsigned int>(time(nullptr)));
		
		int numeroAleatorio = rand() % 5;
		//nt numeroAleatorio = 0;
		gotoxy(0, mitadAltoCasilla + (altoCasilla)*numeroAleatorio);
		cout<<" INICIO    "<< char(220);
		movimientoVertical = numeroAleatorio;
	}
	
		
	void ubicarNumeros(){
		int respuesta = 0;
		if(movimientoHorizontal == 0 && movimientoVertical ==0){
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*1,mitadAltoCasilla);
			srand(static_cast<unsigned int>(time(nullptr)));
			int no1 = (rand() % 10) + 1;
			cout<<no1;
			
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*1,mitadAltoCasilla + (altoCasilla)*1);
			
			int no2 = (rand() % 10) + 1;
			cout<<no2;
			
			gotoxy(mitadAnchoCasilla ,mitadAltoCasilla + (altoCasilla)*1);
			
			int no3 = (rand() % 10) + 1;
			cout<<no3;
			
			respuesta = 0;
		}else if(movimientoHorizontal == 4 && movimientoVertical == 4){
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*4,mitadAltoCasilla + (altoCasilla)*3);
			srand(static_cast<unsigned int>(time(nullptr)));
			int no1 = (rand() % 10) + 1;
			cout<<no1;
			
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*3,mitadAltoCasilla + (altoCasilla)*3);
			
			int no2 = (rand() % 10) + 1;
			cout<<no2;
			
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*3,mitadAltoCasilla + (altoCasilla)*4);
			
			int no3 = (rand() % 10) + 1;
			cout<<no3;
			respuesta = 0;
		}else if(movimientoHorizontal == 0 && movimientoVertical == 4){
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*0,mitadAltoCasilla + (altoCasilla)*3);
			srand(static_cast<unsigned int>(time(nullptr)));
			int no1 = (rand() % 10) + 1;
			cout<<no1;
			
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*1,mitadAltoCasilla + (altoCasilla)*3);
			
			int no2 = (rand() % 10) + 1;
			cout<<no2;
			
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*1,mitadAltoCasilla + (altoCasilla)*4);
			
			int no3 = (rand() % 10) + 1;
			cout<<no3;
			respuesta = 0;
		}else if(movimientoHorizontal == 4 && movimientoVertical == 0){
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*3,mitadAltoCasilla + (altoCasilla)*0);
			srand(static_cast<unsigned int>(time(nullptr)));
			int no1 = (rand() % 10) + 1;
			cout<<no1;
			
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*3,mitadAltoCasilla + (altoCasilla)*1);
			
			int no2 = (rand() % 10) + 1;
			cout<<no2;
			
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*4,mitadAltoCasilla + (altoCasilla)*1);
			
			int no3 = (rand() % 10) + 1;
			cout<<no3;
			respuesta = 0;
		}else if(movimientoHorizontal == 0 && (movimientoVertical>0 && movimientoVertical<<4)){
			srand(static_cast<unsigned int>(time(nullptr)));
			gotoxy(mitadAnchoCasilla,mitadAltoCasilla + (altoCasilla)*(movimientoVertical-1));
			int no1 = (rand() % 10) + 1;
			cout<<no1;
			gotoxy(mitadAnchoCasilla,mitadAltoCasilla + (altoCasilla)*(movimientoVertical+1));
			int no2 = (rand() % 10) + 1;
			cout<<no2;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*1,mitadAltoCasilla + (altoCasilla)*(movimientoVertical+1));
			int no3 = (rand() % 10) + 1;
			cout<<no3;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*1,mitadAltoCasilla + (altoCasilla)*(movimientoVertical-1));
			int no4 = (rand() % 10) + 1;
			cout<<no4;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*1,mitadAltoCasilla + (altoCasilla)*movimientoVertical);
			int no5 = (rand() % 10) + 1;
			cout<<no5;
			
			respuesta = (((no1+no4)* no5) - 0);
		}else if(movimientoHorizontal == 4 && (movimientoVertical>0 && movimientoVertical<<4)){
			srand(static_cast<unsigned int>(time(nullptr)));
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*4,mitadAltoCasilla + (altoCasilla)*(movimientoVertical-1));
			int no1 = (rand() % 10) + 1;
			cout<<no1;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*4,mitadAltoCasilla + (altoCasilla)*(movimientoVertical+1));
			int no2 = (rand() % 10) + 1;
			cout<<no2;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*3,mitadAltoCasilla + (altoCasilla)*(movimientoVertical+1));
			int no3 = (rand() % 10) + 1;
			cout<<no3;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*3,mitadAltoCasilla + (altoCasilla)*(movimientoVertical-1));
			int no4 = (rand() % 10) + 1;
			cout<<no4;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*3,mitadAltoCasilla + (altoCasilla)*movimientoVertical);
			int no5 = (rand() % 10) + 1;
			cout<<no5;
			
			respuesta = (0 - ((no2+no3)* no5) );
		}else if(movimientoHorizontal == 4 && (movimientoVertical>0 && movimientoVertical<<4)){
			srand(static_cast<unsigned int>(time(nullptr)));
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*4,mitadAltoCasilla + (altoCasilla)*(movimientoVertical-1));
			int no1 = (rand() % 10) + 1;
			cout<<no1;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*4,mitadAltoCasilla + (altoCasilla)*(movimientoVertical+1));
			int no2 = (rand() % 10) + 1;
			cout<<no2;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*3,mitadAltoCasilla + (altoCasilla)*(movimientoVertical+1));
			int no3 = (rand() % 10) + 1;
			cout<<no3;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*3,mitadAltoCasilla + (altoCasilla)*(movimientoVertical-1));
			int no4 = (rand() % 10) + 1;
			cout<<no4;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*3,mitadAltoCasilla + (altoCasilla)*movimientoVertical);
			int no5 = (rand() % 10) + 1;
			cout<<no5;
			
			respuesta = (0 - ((no2+no3)* no5) );
		}else if((movimientoHorizontal>0 && movimientoHorizontal<4) && movimientoVertical == 0){
			srand(static_cast<unsigned int>(time(nullptr)));
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*(movimientoHorizontal-1),mitadAltoCasilla + (altoCasilla)*0);
			int no1 = (rand() % 10) + 1;
			cout<<no1;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*(movimientoHorizontal+1),mitadAltoCasilla + (altoCasilla)*0);			
			int no2 = (rand() % 10) + 1;
			cout<<no2;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*(movimientoHorizontal+1),mitadAltoCasilla + (altoCasilla)*1);
			int no3 = (rand() % 10) + 1;
			cout<<no3;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*(movimientoHorizontal),mitadAltoCasilla + (altoCasilla)*1);
			int no4 = (rand() % 10) + 1;
			cout<<no4;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*(movimientoHorizontal-1),mitadAltoCasilla + (altoCasilla)*1);
			int no5 = (rand() % 10) + 1;
			cout<<no5;
			respuesta = (0 - ((no4+no3+no5)* no1));
		}else if((movimientoHorizontal>0 && movimientoHorizontal<4) && movimientoVertical == 4){
			srand(static_cast<unsigned int>(time(nullptr)));
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*(movimientoHorizontal-1),mitadAltoCasilla + (altoCasilla)*4);
			int no1 = (rand() % 10) + 1;
			cout<<no1;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*(movimientoHorizontal+1),mitadAltoCasilla + (altoCasilla)*4);			
			int no2 = (rand() % 10) + 1;
			cout<<no2;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*(movimientoHorizontal+1),mitadAltoCasilla + (altoCasilla)*3);
			int no3 = (rand() % 10) + 1;
			cout<<no3;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*(movimientoHorizontal),mitadAltoCasilla + (altoCasilla)*3);
			int no4 = (rand() % 10) + 1;
			cout<<no4;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*(movimientoHorizontal-1),mitadAltoCasilla + (altoCasilla)*3);
			int no5 = (rand() % 10) + 1;
			cout<<no5;
			respuesta = (((no4+no3+no5)* no2)- 0);
		} else {
			srand(static_cast<unsigned int>(time(nullptr)));
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*(movimientoHorizontal-1),mitadAltoCasilla + (altoCasilla)*(movimientoVertical-1));
			int no1 = (rand() % 10) + 1;
			cout<<no1;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*(movimientoHorizontal),mitadAltoCasilla + (altoCasilla)*(movimientoVertical-1));
			int no2 = (rand() % 10) + 1;
			cout<<no2;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*(movimientoHorizontal+1),mitadAltoCasilla + (altoCasilla)*(movimientoVertical-1));
			int no3 = (rand() % 10) + 1;
			cout<<no3;
			gotoxy(mitadAnchoCasilla + (anchoCasilla)*(movimientoHorizontal+1),mitadAltoCasilla + (altoCasilla)*(movimientoVertical));
			int no4 = (rand() % 10) + 1;
			cout<<no4;
			gotoxy(mitadAnchoCasilla + (anchoCasilla+1)*(movimientoHorizontal+1),mitadAltoCasilla + (altoCasilla)*(movimientoVertical+1));
			int no5 = (rand() % 10) + 1;
			cout<<no5;
			gotoxy(mitadAnchoCasilla + (anchoCasilla+1)*(movimientoHorizontal),mitadAltoCasilla + (altoCasilla)*(movimientoVertical+1));
			int no6 = (rand() % 10) + 1;
			cout<<no6;
			gotoxy(mitadAnchoCasilla + (anchoCasilla+1)*(movimientoHorizontal-1),mitadAltoCasilla + (altoCasilla)*(movimientoVertical+1));
			int no7 = (rand() % 10) + 1;
			cout<<no7;
			gotoxy(mitadAnchoCasilla + (anchoCasilla-1)*(movimientoHorizontal-1),mitadAltoCasilla + (altoCasilla)*(movimientoVertical));
			int no8 = (rand() % 10) + 1;
			cout<<no8;
			
			respuesta = (((no1+no2+no3)*no4)-((no5+no6+no7)*no8));
		}
		
		recuadro();
		int resultado;
		cout<<"\nDigite el resultado: ";
		cin>>resultado;
		
		
		if(resultado == respuesta){
			cout<<"correcto";
			respuestaCorrecta = true;
		}else{
			cout<<"incorrecto";
			respuestaCorrecta = false;
			vidas--;
		}
	}
		
	int main()
	{
		
		system("cls");
		system("color 20");
		string direccion;
		
		
		bool esIgual;
		
		
		ubicarInicio();
		ubicarSalida();
		ubicarNumeros();
		recuadro();
		
		while(vidas>0 && !llegoAlFinal){
			
			if(respuestaCorrecta){
				cout<<"\nEscriba una direccion: ";
				cin>>direccion;
				
				if(direccion == "s"){
					movimientoVertical++;
					system("cls");
					insertarJugador(mitadAltoCasilla + (altoCasilla)*movimientoVertical,mitadAnchoCasilla + (anchoCasilla)*movimientoHorizontal);
					ubicarNumeros();
					
				} else if(direccion == "w"){
					movimientoVertical--;
					system("cls");
					insertarJugador(mitadAltoCasilla + (altoCasilla)*movimientoVertical,mitadAnchoCasilla + (anchoCasilla)*movimientoHorizontal);
					ubicarNumeros();
					
				} else if(direccion == "d"){
					movimientoHorizontal++;
					system("cls");
					insertarJugador(mitadAltoCasilla + (altoCasilla)*movimientoVertical,mitadAnchoCasilla + (anchoCasilla)*movimientoHorizontal);
					ubicarNumeros();
				}	else if(direccion == "a"){
					movimientoHorizontal--;
					system("cls");
					insertarJugador(mitadAltoCasilla + (altoCasilla)*movimientoVertical,mitadAnchoCasilla + (anchoCasilla)*movimientoHorizontal);
					ubicarNumeros();
				}
			}else {
				if(movimientoHorizontal>0 && movimientoHorizontal<4){
					movimientoHorizontal--;
				}else if(movimientoVertical>0 && movimientoVertical<4){
					movimientoVertical--;
				}
				respuestaCorrecta = true; 
				insertarJugador(mitadAltoCasilla + (altoCasilla)*movimientoVertical,mitadAnchoCasilla + (anchoCasilla)*movimientoHorizontal);
				system("cls");
				ubicarNumeros();
			}
			if (movimientoHorizontal == 4 && movimientoVertical == salidaEnY){
				llegoAlFinal = true;
				system("cls");
				cout<<"GANASTE!!!";
			}
			if(vidas<=0){
				system("cls");
				cout<<"PERDISTE!!!";
			}
			
		}
		
		
		return 0;
	}
