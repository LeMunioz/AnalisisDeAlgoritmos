#include <iostream>
#include <limits>
#include "colores.cpp"
#include <string>
#include <ctime>
using namespace std;
/*
[ANGEL EDUARDO MUÑOZ PEREZ]
[ACTIVIDAD 15]
[Centro Universtitario de los altos]
[Ingenieria en coputacion_ 2do semestre]
[Prof. Sergio Sergio]
*/
//funciones
int main();
void juegop();//juego conta otro jugador
void avanzaturnosp();
void juegoc();//juego contra la computadora
void avanzaturnosc();
void victoria();
void fracaso();


struct puntos{
	char nombre[6];
	int punto;
}puntaje[8];

//variables
int turno;
int turnoreal;
int turnoganador;
char gato[3][3];
#include "func15.cpp"

int  main(){
	system("cls");
	int opcion;
	
	int numero=1;
	
	color(10);
	cout<<"BIENVENIDO AL JUEGO DEL GATO :3"<<endl;
	cout<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-"<<endl;
	color(5);
	cout<<"\t--------------------"<<endl;
	cout<<"\t| [1] contra cpu   |"<<endl;
	cout<<"\t| [2] contra otro  |"<<endl;
	cout<<"\t| [3] SALIR        |"<<endl;
	cout<<"\t| [4] ver puntajes |"<<endl;
	cout<<"\t--------------------"<<endl;
	
	//vaciamos la matriz
	for (int f=1; f<4; f++){
		for (int c=1; c<4; c++){
			gato[f][c]='.';
		}//fin del primer for
	}//fin del primer for
	
	while(true){
		if(cin>>opcion){
			switch(opcion){
				case 1:
					turno=0;
					turnoreal=0;
					avanzaturnosc();
					break;
				case 2:
					turno=0;
					turnoreal=0;
					avanzaturnosp();
					break;
				case 3:
					abort();//SALE DEL PROGRAMA                              ***
					break;
				case 4:
					puntos();
					break;	
				default:
					color(12);
					cout<<"Esa no es una opcion querido"<<endl;
					system("pause");
					main();
					break;			
			}//fin del switch
		}else{
			cout<<"pon un numero mi rey porfas"<<endl;
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			system("pause");
			main();	
		}//fin del if validacion	
	}//fin del while validacion	
}//FIN DEL MAIN ////////////////////////////////////////////////////////

void avanzaturnosp(){
	turno++;
	juegop();
}
void juegop(){//juego contra otra persona
	system("cls");
	
	int columna;
	int fila;
	char jugada;
	
	
	//para avanzar un turno cada que empieze nueva jugada 
	if(turno == 1 or turno == 3 or turno == 5 or turno == 7 or turno ==9){
		turnoreal=1;
	}else if(turno == 2 or turno == 4 or turno == 6 or turno == 8){
		turnoreal=2;
	}else if(turno > 9){
		turnoreal=3;
	}
	
	
	//Escribimos el gato
	cout<<turno<<endl;
	color(3);
	cout<<"|- :3 -|- :3 -|- :3 -|- :3 -|- :3 -|- :3 -|- :3 -|\n"<<endl;
	color(15);
	dibujagato(gato);
	
	//checa si hay algun ganador
	if (checa3linea(gato, 'X')){
	victoria();
	}else if(checa3linea(gato, 'O')){
	victoria();
	}else{//SI NO, HACE EL PROCESO
		switch(turnoreal){
			case 1:
				color(3);
				cout<<"turno de jugador no. 1"<<endl;
				cout<<"\nEscoge un lugar"<<endl;
				cout<<"COLUMNA -->";
				jugada= 'O';
		//JUGADA DE JUGADOR !	
					color(15);
						//VALIDACION
						while (true){
							if(cin >> columna and columna >0 and columna <4){
								break;
							}else{
								cout<<"ponlo bien porfas"<<endl;
								cin.clear();
								cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
								system("pause");
								juegop();		
							}//fin del if validacion
						}//fin del while validacion
						color(3);
						cout<<"FILA -->";	
						while (true){
							if(cin >> fila and fila >0 and fila <4){
								break;
							}else{
								cout<<"ponlo bien porfas"<<endl;
								cin.clear();
								cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
								system("pause");
								juegop();		
							}//fin del if validacion
						}//fin del while validacion
		//PARA CHECAR QUE EL ESPACIO ESTA VACIO				
					if(gato[columna][fila] == '.'){
					gato[columna][fila] = jugada;
					turnoganador=turnoreal; //por si gana, guardar cual fue ese turno
					avanzaturnosp();
					}else{
						color(12);
						cout<<"Ese color esta ocupado"<<endl;
						cout<<"intenta de nuevo"<<endl;
						system("pause");
						juegop();
					}//fin del if de CHEQUEO SI ESTA LLENO
				break;	
					
		//JUGADA DE JUGADOR 2	
			case 2:
				color(3);
				cout<<"turno de jugador no. 2"<<endl;
				cout<<"\nEscoge un lugar"<<endl;
				cout<<"COLUMNA -->";
				jugada='X';
					
					color(15);
					//VALIDACION
					while (true){
						if(cin >> columna and columna >0 and columna <4){
							break;
						}else{
							cout<<"ponlo bien porfas"<<endl;
							cin.clear();
							cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
							system("pause");
							juegop();		
						}//fin del if validacion
					}//fin del while validacion
					color(3);
					cout<<"FILA -->";	
					while (true){
						if(cin >> fila and fila >0 and fila <4){
							break;
						}else{
							cout<<"ponlo bien porfas"<<endl;
							cin.clear();
							cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
							system("pause");
							juegop();		
						}//fin del if validacion
					}//fin del while validacion
		//PARA CHECAR QUE EL ESPACIO ESTA VACIO			
					if(gato[columna][fila] == '.'){
					gato[columna][fila] = jugada;
					turnoganador=turnoreal; //por si gana, guardar cual fue ese turno
					avanzaturnosp();
					}else{
						color(12);
						cout<<"Ese color esta ocupado"<<endl;
						cout<<"intenta de nuevo"<<endl;
						system("pause");
						juegop();
					}//fin del if de CHEQUEO SI ESTA LLENO
					break;
		case 3:
				color(12);			
				cout<<"NAdie gano xd"<<endl;
				system("pause");
				main();		
			break;
			default:
			cout<<"hubo un problemita, no deberia ser posible esto xd"<<endl;
			cout<<"ERROR (SWITCH DE LOS TURNOS REALES)"<<endl;
			system("pause");
			main();	
			break;
		}//fin del switch
	}//fin del if de chequeo si hay victoria
}//FIN DE FUNCION JUEGOP/////////////////////////////////////////////////



void avanzaturnosc(){
	turno++;
	juegoc();
}
void juegoc(){//JUEGO CONTRA LA COMPUTADORA
	system("cls");
	
	int columna;
	int fila;
	char jugada;
	
	
	//para avanzar un turno cada que empieze nueva jugada 
	if(turno == 1 or turno == 3 or turno == 5 or turno == 7 or turno ==9){
		turnoreal=1;
	}else if(turno == 2 or turno == 4 or turno == 6 or turno == 8){
		turnoreal=2;
	}else if(turno >9){
		turnoreal=3;
	}
	
	//Escribimos el gato
	cout<<turno<<endl;
	color(3);
	cout<<"|- :3 -|- :3 -|- :3 -|- :3 -|- :3 -|- :3 -|- :3 -|\n"<<endl;
	color(15);
	dibujagato(gato);
	
		//checa si hay algun ganador
	if (checa3linea(gato, 'X')){
	fracaso();
	}else if(checa3linea(gato, 'O')){
	victoria();
	}else{//SI NO, HACE EL PROCESO
		switch(turnoreal){
			case 1://JUGADOR
				color(3);
				cout<<"turno de jugador no. 1"<<endl;
				cout<<"\nEscoge un lugar"<<endl;
				cout<<"COLUMNA -->";
				jugada= 'O';
		//JUGADA DE JUGADOR !	
					color(15);
						//VALIDACION
						while (true){
							if(cin >> columna and columna >0 and columna <4){
								break;
							}else{
								cout<<"ponlo bien porfas"<<endl;
								cin.clear();
								cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
								system("pause");
								juegoc();		
							}//fin del if validacion
						}//fin del while validacion
						color(3);
						cout<<"FILA -->";	
						while (true){
							if(cin >> fila and fila >0 and fila <4){
								break;
							}else{
								cout<<"ponlo bien porfas"<<endl;
								cin.clear();
								cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
								system("pause");
								juegoc();		
							}//fin del if validacion
						}//fin del while validacion
		//PARA CHECAR QUE EL ESPACIO ESTA VACIO				
					if(gato[columna][fila] == '.'){
					gato[columna][fila] = jugada;
					turnoganador=turnoreal; //por si gana, guardar cual fue ese turno
					avanzaturnosc();
					}else{
						color(12);
						cout<<"Ese color esta ocupado"<<endl;
						cout<<"intenta de nuevo"<<endl;
						system("pause");
						juegoc();
					}//fin del if de CHEQUEO SI ESTA LLENO
				break;	
		//JUGADA DE COMPUTADORA	
			case 2: 
				cout<<"PIENSA RAPIDO"<<endl;	
				jugada='X';	
						
				srand((unsigned)time(NULL));//para que me cree numeros aleatorios
				columna= 1 + rand()% 3;//genero un aleatorio del 1 al 3
				
			
				fila= 1 + rand()% 3;//genero un aleatorio del 1 al 3	
			//PARA CHECAR QUE EL ESPACIO ESTA VACIO				
					if(gato[columna][fila] == '.'){
					gato[columna][fila] = jugada;
					turnoganador=turnoreal; //por si gana, guardar cual fue ese turno
					avanzaturnosc();
					}else{
						cout<<columna<<" y  "<<fila<<"esta ocupada"<<endl;
						juegoc();
					}//fin del if de CHEQUEO SI ESTA LLENO	
				break;
			case 3:
				cout<<"nadie gano xd"<<endl;
				system("pause");
				main();
				break;	
			default:
			cout<<"hubo un problemita, no deberia ser posible esto xd"<<endl;
			cout<<"ERROR (SWITCH DE LOS TURNOS REALES.cpu)"<<endl;
			system("pause");
			main();	
			break;
		}//fin del switch	
	}//fin del if CHEQUEO SI GANO ALGUIEN
}//FIN DE FUNCION JUEGOCPU///////////////////////////////////////////////




void victoria(){
	system("cls");
	color(10);
	int lugar;//para guardar la imformacion en su archivero
	
	cout<<"*_*_*_*_*_*_*_*_*_*_*"<<endl;
	cout<<"\t VICTORIA"<<endl;
	cout<<"*_*_*_*_*_*_*_*_*_*_*"<<endl;
	cout<<"GANO EL JUGADOR "<<turnoganador<<endl;
	
	//GUARDAMOS EL GANADOR
	color(9);
	cout<<"donde lo guardamos?  "<<endl;
	if (cin>> lugar && lugar >0 && lugar <9){
		cout<<"good"<<endl;
	}else{
		cout<<"pon un numero bien compa, tengo espacios entre el 1 y el 8"<<endl;
		cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			system("pause");
			victoria();	
	}
	cout<<"Pon tu nombre campeon"<<endl;
	fflush(stdin);//para que quite si hay algo escrto y me deje leer un string
	cin.getline(puntaje[lugar].nombre, '6', '\n');
	puntaje[lugar].punto+=10;
	cout<<"+10 puntos"<<endl;
	
	
	int opc;
	color(2);
	cout<<"Quieres jugar otravez?"<<endl;
	cout<<"[1] SI         [2] NO"<<endl;
	
	while (true){
		if(cin >> opc){
			switch(opc){
				case 1:
					main();
					break;
				case 2:
					abort();//SALE DEL PROGRAMA                              ***
					break;
				default:
					cout<<"Pon uno de los numeros de arriba mi rey"<<endl;
					system("pause");
					victoria();		
			}//fin del switch
		}else{
			color(12);
			cout<<"Bro por gente como tu es que me la paso validando entradas >:c"<<endl;
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			system("pause");
			victoria();	
		}//fin del if validacion
	}//fin del while para validar
}//FIN DE LA FUNCION DE VICTORIA////////////////////////////////////////////////////////////////////////


void fracaso(){
	color(14);
	
	cout<<"\n		*	,MMM8&&&.	   *"<<endl;
	cout<<" .      MMMM88&&&&    . "<<endl;
	cout<<"   \°  .MMMM88&&&&&|      ."<<endl;
	cout<<"       MMMM88&&&&&}     * "<<endl;
	cout<<" .     MMMM88&&&&&|       . "<<endl;
	cout<<"        MMMM88&&&&'   .    "<<endl;
	cout<<"  *      'MM8&&&&'     . "<<endl; 	color(15);
	cout<<"       /\\/|_        .    "<<endl;
	cout<<"      /    -\\         "<<endl;
	cout<<"      \\   ==Y    *"<<endl;
	cout<<"       )==*('  ";color (14); cout<<" *  ."<<endl; color(15);
	cout<<"      /     \\ "<<color (14); cout<<"     °"<<endl; color(15);
	cout<<"      |  n   |"<<color (14); cout<<"         ."<<endl; color(15);
	cout<<"     /  ( (  \ "<<endl;
	cout<<"     \\   ) ) /"<<color (14); cout<<" *     ."<<endl; color(15);
	cout<<"      \\  ( (/ "<<endl; color(2);
	cout<<"//\\/|/\\\\|\\\\|\/|\\\\///\\|\\\\//|\\||/"<<endl;

	color(12);
    cout<<"    PERDISTE ESTIMADO :("<<endl;
	
	int opc;
	color(2);
	cout<<"\nQuieres jugar otravez?"<<endl;
	cout<<"[1] SI         [2] NO"<<endl;
	
	while (true){
		if(cin >> opc){
			switch(opc){
				case 1:
					main();
					break;
				case 2:
					abort();//SALE DEL PROGRAMA                              ***
					break;
				default:
					cout<<"Pon uno de los numeros de arriba mi rey"<<endl;
					system("pause");
					fracaso();		
			}//fin del switch
		}else{
			color(12);
			cout<<"Bro por gente como tu es que me la paso validando entradas >:c"<<endl;
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			system("pause");
			fracaso();	
		}//fin del if validacion
	}//fin del while para validar
	  
}//FIN DE LA UNCION FRACASO/////////////////////////////////////////////////////////////////////////////
