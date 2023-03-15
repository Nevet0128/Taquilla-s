#include<iostream>
#include<memory>

using namespace std;

void gtxy (int x,int y)
{
	HANDLE ii;
	ii=GetStdHandle(STD_OUTPUT_HANDLE);
	
	COORD jj;
	jj.X=x;
	jj.Y=y;
	
	SetConsoleCursorPosition(ii,jj);
}

void Portada() //Caratula
{
	system("color F4");
	
	gtxy(36,0);	cout<<"IPN";
	gtxy(27,2); cout<<"ESIME Unidad Culhuacan";
	gtxy(25,4);	cout<<"Ingenieria en Computacion";
	gtxy(22,6);	cout<<"Programacion Orientada a Objetos";
	gtxy(31,8);	cout<<"Grupo: 2CV45";
	gtxy(25,10); cout<<"Proyecto Tercer Parcial";
	gtxy(0,16); cout<<"Nombre del Profesor: Cruz Garcia Oscar";
	gtxy(0,18); cout<<"Nombre del Alumno: Medina Garcia Carlos Alejandro";
	Sleep(3000);
	system("cls");
}
