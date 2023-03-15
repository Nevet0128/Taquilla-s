#include<iostream>
#include<windows.h>
#include<memory>
#include<string>
#include "portada.cpp"
#include "Introduccion.cpp"

using namespace std;

class Taquilla
{
	private:
		
		int dia,promo,contador2;//Variables que solo se usan en esta clase
		string dias[7];
		
		int can,sust,dinero;	//variable que asimila el pago del cliente y se mete a condicional
		
	public:
		
		Taquilla()
		{
			
		}
		
		int i,diafk,hora,mes,desc,dineroP;
		int dineroDia[365],personaDia[365],contadorDia,dineroTotal;
		
		~Taquilla()
		{
			
		}
		
		void calendario();	//control de los meses, dias y horas
		void ordenmeses();	//control de acabar los dias de los meses, las promociones y descansos
		void Reloj();		//Muestra el reloj
		void Estatus();		//Muestra el estatus de la taquilla
		void relleno();		//Ordenamiento de
		
		void menu();		//Interface cuando este abierto la taquilla
		int pago();			//Metodos de pago, control de ingresos y de personas
		void mostrarH();	//Opcion para mostrar diariamente el historial de personas que han entrado y el dinero acumulado cada dia
		void mostrarF();	//Al final del programa muestra todos los ingresos durante los dias asi como las personas que entraron y el monto acumulado durante todo el año
};

void Taquilla::relleno()
{
	for(int AbcD=0;AbcD<=364;AbcD++)
	{
		dineroDia[AbcD]=0;
		personaDia[AbcD]=0;
	}
}

void Taquilla::ordenmeses()
{	
	cout<<"\t\t\t\t"<<dias[i]<<" "<<diafk<<" de ";
	switch (mes)
	{
		case 1 :
		{
			cout<<"Enero";
			
			if(dia == 1)
			{
				desc=1; //descanso
			}
		
			if(dia == 6)
			{
				promo=1; // 2x1 promociones (variable que de el tipo de descuento)
			}
		
			break;
		}
		
		case 2 :
		{
			cout<<"Febrero";
			
			if(dia == 5)
			{
				desc=1; //descanso	
			}
		
			if(dia == 14 || dia == 24)
			{
				promo=1; // 2x1
			}
			
			if(dia==28)
			{
				dia=31;
			}
			
			break;
		}
		
		case 3 :
		{
			cout<<"Marzo";
			
			if(dia == 19)
			{
				desc=1; //descanso
			}
		
			if(dia == 29 || dia == 30)
			{
				promo=1; // 2x1
			}
			
			break;
		}
		
		case 4 :
		{
			cout<<"Abril";
			
			if(dia == 30)
			{
				promo=1; // 2x1
			}
			
			if(dia==30)
			{
				dia=31;
			}
			
			break;
		}
		
		case 5 :
		{
			cout<<"Mayo";
			
			if(dia == 1)
			{
				desc=1; //descanso
			}
		
			if(dia == 5 || dia == 10)
			{
				promo=1; // 2x1
			}
			
			break;
		}
		
		case 6 :
		{
			cout<<"Junio";
			
			if(dia==30)
			{
				dia=31;
			}
			
			break;
		}
		
		case 7 :
		{
			cout<<"Julio";
			break;
		}
		
		case 8 :
		{
			cout<<"Agosto";
			break;
		}
		
		case 9 :
		{
			cout<<"Septiembre";
			
			if(dia==30)
			{
				dia=31;
			}
			
			break;
		}
		
		case 10 :
		{
			cout<<"Octubre";
			break;
		}
		
		case 11 :
		{
			cout<<"Noviembre";
			
			if(dia == 2)
			{
				promo=1; // 2x1
			}
		
			if(dia == 19)
			{
				desc=1; // descanso
			}
			
			if(dia==30)
			{
				dia=31;
			}
			
			break;
		}
		
		case 12 :
		{
			cout<<"Diciembre";
			
			if(dia == 1 || dia == 25)
			{
				desc=1; // descanso
			}
			
			if(dia == 12 || dia == 24)
			{
				promo=1; // 2x1
			}
			
			break;
		}
		
		default :
		{
			cout<<"ERROR";
		}
	}
	
	cout<<" del 2018\tCOSTO DEL BOLETO: "<<dineroP<<"$";
}

void Taquilla::Reloj()
{
	cout<<"\n\nReloj: "<<hora<<":00 ";
	hora++;
	if(hora <= 1 || hora <= 12)
		{
			cout<<"am"<<endl;
		}
				
	else
		{
			cout<<"pm"<<endl;
		}
}

void Taquilla::Estatus()
{
	cout<<"Estatus: ";
			
	if (hora > 8 && hora <= 22)
		{
			if(i == 6 || desc == 1)
			{
				cout<<"Dia libre obligatorio / Domingo"<<endl;
			}
			
			else
			{
				cout<<"Abierto"<<endl;
				menu();
			}
		}
	
	else
		{
			cout<<"Cerrado"<<endl;
		}
}

void Taquilla::calendario()
{
	promo=0,contadorDia=0,dineroTotal=0,desc=0,i=0,diafk=1,hora=1,dia=1,mes=1,contador2=0;
	int XD;
	dias[0]="Lunes", dias[1]="Martes", dias[2]="Miercoles",dias[3]="Jueves",dias[4]="Viernes",dias[5]="Sabado",dias[6]="Domingo";
	
	relleno(); //llenado de arrays con 0 por si no hay personas o dinero que entraron algun dia
	
	system("color F0");
	
	do
	{
		cout<<"Ingrese el precio del boleto: ";
		cin>>dineroP;
		
		if(dineroP < 0)
		{
			cout<<"\nPrecio incorrecto, debe ser igual o mayor a cero"<<endl;
		}
		
	}while(dineroP<0);
	
	system("cls");
	
	do	//Meses 
	{
		do //Dias 
		{
			do //Horas
			{				
				ordenmeses(); // con calendario para descuentos y dias libres
				Reloj();

				Estatus();
				
				Sleep (1000);
				system("cls");
				
			}while(hora <= 24);
			
			cout<<"Quieres Ver el historial de personas y dinero se han juntado a travez de los dias?\n\nSi presione 1\nNo presione 0\t";
			cin>>XD;
			if(XD==1)
			{
				mostrarH();
			}
			
			i++;
			if(i==7)	//condicional para que se sigan repitiendo los nombres de los dias
			{
				i=0;
			}
			
			contador2++;
			hora=1;
			dia++;		//variable que se altera para concluir meses que no acaben en 31
			diafk++;	//variable que se muestra
			desc=0;		//variable que indica si hay descanzo ese dia o no ese dia
			
			contadorDia++; //variable que se mueve de lugar a medida que los dias avanzan
			
		}while(dia <= 31); //30 dias: abril, junio, septiembre, noviembre 
						   // 28 dias: febrero
		dia=1;
		diafk=1;
		
		mes+=1; //operacion que cambia el mes		
	}while(mes <= 12);
	
	mostrarF();
}

void Taquilla::menu()
{
	cout<<"\n\nIngrese la cantidad de personas que van a pagar: ";
	cin>>can;
	
	if(can!=0)
	{
		for(int ay=0;ay<can;ay++)		//bucle para evaluar a cada persona si tiene promocion o no
		{
			//Puede entrar ORDEN MESES POR SI HAY DESCUENTO 2X1, PUEDEN SER 2 LLAMADOS A ORDENMESES, EN LA CLASE PRINCIPAL Y AQUI
			do
			{	
				if(promo == 1)
				{
					cout<<"\nEs dia 2x1, la persona desea aplicar la promocion?\nSi 1\nNo 0\t";
					cin>>promo;
				}
	
				else	//por si no quizo aplicar el descuento y va solo
				{
					cout<<"\nIngrese el descuento que tiene la persona:\n\nNinguno 0\n2x1 Presione 1\nCupon (30% de descuento) Presione 2\nMiembro (50% de descuento) Presione 3\t";
					cin>>promo;
				}
				
				if(promo <0 || promo >3)
				{
					cout<<"\n\tAccion invalida, ingrese de nuevo el tipo de descuento que tiene la persona: "<<endl;
				}
				
			}while(promo < 0 || promo > 3);
				
			do
			{
				sust=pago();		//pasa hacia el metodo
				
				if (sust < 0)
				{
					cout<<"\n\tPago incorrecto, repitalo de nuevo"<<endl;
				}
					
				else
				{
					cout<<"Cambio: "<<sust<<"$"<<endl;
				}
				
				system("pause");
				
			}while(sust < 0);
			
			promo=0;					
		}
	}
}

int Taquilla::pago()
{
	int afk;
	cout<<"\nIngrese el pago de la persona: ";
	cin>>dinero;
	
	switch (promo)
	{
		case 0: //NO TIENE DESCUENTO
			{
				afk=(dinero-dineroP);
				
				if(afk >= 0)
				{
					personaDia[contadorDia]+=1;
					dineroDia[contadorDia]+=dineroP;
					dineroTotal+=dineroP;
				}	
											//VARIABLES EN CLASS PADRE
				return afk;
				break;
			}
			
		case 1: //2X1
			{
				afk=(dinero-(dineroP/2));
				
				if(afk >= 0)
				{
					personaDia[contadorDia]+=2;
					dineroDia[contadorDia]+=dineroP;
					dineroTotal+=dineroP;
				}
					
				return afk;
				break;
			}
			
		case 2: //CUPON DE 30% DE DESCUENTO
			{
				afk=(dinero - ((dineroP*70)/100));
				
				if(afk >=0 )
				{
					personaDia[contadorDia] += 1;
					dineroDia[contadorDia] += dineroP;
					dineroTotal += dineroP;
				}
					
				return afk; //490 es el 70% del valor original
				break;
			}
			
		case 3: //MIEMBROS
			{
				afk=(dinero - ((dineroP*50)/100));
				
				if(afk >= 0)
				{
					personaDia[contadorDia] += 1;
					dineroDia[contadorDia] += dineroP;
					dineroTotal += dineroP;
				}
				
				return afk; //descuento del 50% a los miembros
				break;
			}
			
		default :
			{
				cout<<"ERROR";
				break;	
			}	
	}
}

void Taquilla::mostrarH()
{
	int contador1;
	
	for(contador1=0;contador1<=contador2;contador1++)		//Dinero que se ha acumulado durante todos los dias
	{
		cout<<"\nDia "<<(contador1+1)<<":"<<endl;
		cout<<"Personas que ingresaron: "<<personaDia[contador1]<<endl;
		cout<<"Dinero acumulado: "<<dineroDia[contador1]<<endl;
	}
	
	system("pause");
}

void Taquilla::mostrarF()	//Este metodo solo imprime lo que se guardo durante todo el relleno del array
{
	int contador;
	
	for(contador=0;contador<=364;contador++)		//Dinero que se ha acumulado durante todos los dias
	{
		cout<<"Dia "<<(contador+1)<<":"<<endl;
		cout<<"Personas que ingresaron: "<<personaDia[contador]<<endl;
		cout<<"Dinero acumulado: "<<dineroDia[contador]<<endl;
	}
	
	cout<<"Total acumulado: "<<dineroTotal<<endl;		//dinero total del año 2018
}

main()
{
	Portada(); //Funcion
	Introduccion();
	
	Taquilla *ob1;
	
	ob1 = new Taquilla(); //constructor
	
	ob1->calendario(); //objeto
	
	delete ob1; //destructor
}  	
