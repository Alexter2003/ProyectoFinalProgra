#include <windows.h>
#include <iostream>
#include <direct.h>
#include <stdlib.h>
#define ANCHO 59
#define ALTO 25
using namespace std;

int altoCasilla = ALTO/5;
int anchoCasilla = (ANCHO*2)/5;
int mitadAltoCasilla = altoCasilla/2;
int mitadAnchoCasilla = anchoCasilla/2;

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
}
	
	void insertarJugador(int altoCasilla, int anchoCasilla){
		gotoxy( anchoCasilla, altoCasilla);
		cout<<char(220);
	}
		
		int main()
		{
			system("cls");
			system("color 20");
			insertarJugador(mitadAltoCasilla + (altoCasilla)*0,mitadAnchoCasilla);
			recuadro();
			
			return 0;
		}
