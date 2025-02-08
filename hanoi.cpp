#include <iostream>
#include <limits>//para validar
#include <cmath>//para sacar potencias
#include <vector>//para vectores dinamicos
#include <vector>
#include <cstdlib> // contiene la funcion system("pause")
#include <locale.h> // Libreria que contiene la funcion setlocale
#include "colores.cpp"
using namespace std;

/*
[ANGEL EDUARDO MU?OZ PEREZ]
[ACTIVIDAD 16_ TORRES DE HAN?I]
[CUALTOS_ Ing. en computaci?n]
[Programaci?n Estructurada]
[Prof. Sergio Casillas]
[12.04.2023]
*/
//variables
int numDiscos;

vector<vector<int> > torres(3);
int Torigen, Tdestino;

//FUNCIONES 
//Para modo automatico
void movimientos(int numDiscos, char torreA, char torreC, char torreB);
//para modo manual
void manual();
void EscribeTorres(vector<vector<int> >& torres);
void victoria();


void movimientos(int numDiscos, char torreA, char torreC, char torreB) {
    // Caso base: cuando solo quede un disco
    if (numDiscos == 1) {
        cout << "Mover disco " << numDiscos << " de " << torreA << " a " << torreC << endl;
    }
    else {//sino, mover n-1 discos de la primera a la ultima torre
        movimientos(numDiscos - 1, torreA, torreB, torreC);
        
        //mover el disco restante de la torre A a la C
        cout << "Mover disco " << numDiscos << " de " << torreA << " a " << torreC << endl;
        
        //mover los n-1 discos restantes de la torre B a la torre C
        movimientos(numDiscos - 1, torreB, torreC, torreA);
    }
}//FIN DE FUNCION MOVIMIENTOS//////////////////////////////////////////////

int main() {
	system("cls");
    int opcion;
    int movimientostotales;
    
    color(10);
    cout<<"  BIENVENIDO A MI PROGRAMA\n   LAS TORRES DE HAN?I"<<endl;
    cout<<"_______|_____|_____|_______"<<endl; color (15);
    
    // Pedimos la cantidad de discos y validamos
    cout << "Ingresa la cantidad de discos: ";
    if (cin >> numDiscos && numDiscos >2 && numDiscos <8){
    //dibujamos las torres
    	cout<<"_____________________________________"<<endl; color(1);
    	cout<<"  TORRE A	 TORRE B    TORRE C"<<endl; color(3);
    	cout<<"	 |	   |        |"<<endl;
    	cout<<"	 |	   |        |"<<endl;
    	cout<<"	 |	   |        |"<<endl;
    	cout<<"	---       ---      ---"<<endl; color(15);
	// Ivocamos la funcion recursiva
	    movimientos(numDiscos, 'A', 'C', 'B');
	//escribios el numero de movimientos
	    movimientostotales = pow(2, numDiscos); 
	    color(8); cout<<"se necesitaron "<<movimientostotales-1<<" para resolverlo"<<endl; color(15);
	}else{//si no lee la opcion
		cout<<"Pon un numero estimado (del 3 al 7)"<<endl;
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');	
		system("pause");
		main();
	}
	//PAra hacerlo de nuevo
	color(14);
	cout<<"gustas hacerlo con otra cantidad?"<<endl; color (10);
	cout<<"[1] SI "; color (12); cout<<"  NO [2]"; color(6); cout<<"  Hacerlo yo [3]"<<endl; color(15);
	//validamos la opcion
	if(cin >>opcion){
		switch (opcion){
			case 1:
				main();
				break;
			case 2:
				abort();
				break;
			case 3:
				manual();	
				
			default:
				cout<<"Pon 1 o 2 mi rey"<<endl;
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');	
				system("pause");
				main();		
		}//fin del switch
	}else{
		cout<<"Pon un numero estimado"<<endl;
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');	
				system("pause");
				main();	
	}//fin de la validacion
    return 0;
}//FIN DEL MAIN///////////////////////////////////////////////////


void manual(){
	system("cls");
	// Inicializar torre 1 con n discos
	for(int i = numDiscos; i >= 1; i--) {
	    torres[0].push_back(i);
	}
	//Invocamos lo que escribe las torres
	EscribeTorres(torres);
	
	while(true) {
		
		color (8);
	    cout << "Escribe de que torre a que torre quieres mover disco "; color(15);
	    cin >> Torigen >> Tdestino;
	
	    // Restar 1 para ajustar a ?ndices de vector
	    Torigen--;
	    Tdestino--;
	    
		//Checa si el lugar de donde agarramos esta vacio
	    if(torres[Torigen].empty()) {
			color (12);	
	        cout << "Aqui no hay nada men" << endl; color(15);
	        break;
	    }
		//quitamos el valor de la cola del arreglo y tronamos el espacio que ocupaba
	    int disco = torres[Torigen].back();
	    torres[Torigen].pop_back();
		//pujamos el alemento a la torre donde lo quisimo mover	
	    if(!torres[Tdestino].empty() && disco > torres[Tdestino].back()) {
	    	color (12);
	        cout << "Ahi no se puede estimado" << endl; color (15);
	        torres[Torigen].push_back(disco); // Regresar disco a torre de origen
	        break;
	    }
	
	    torres[Tdestino].push_back(disco);
	    EscribeTorres(torres);
	    
	    // Checar si el usuario ha ganado
	    if(torres[2].size() == numDiscos) {
	        victoria();
	        
	        break;
	    }
	}//fin del while    
}//FIN DE LA FUNCION MANUAL/////////////////////////////////////


void EscribeTorres(vector<vector<int> >& torres) {
    for(int i = 0; i < 3; i++) {
        color(1); cout << "Torre " << i+1 << ": ";
        for(int j = 0; j < torres[i].size(); j++) {
        color (3);  cout << torres[i][j] << " ";
        }
        cout <<"\n"; color(15);
    }
}//FIN DE LA FUNCION IMPRIME TORRES///////////////////////////////


void victoria(){
	int opc;
	
	color (2);
	cout<<"FELICIDADES; HAS GANADO"<<endl;
	color (10);
	cout<<"Quieres volverlo a intentar?"<<endl;
	cout<<"SI [1]             NO[2]"<<endl;
	
	if (cin>>opc){
		switch (opc){
			case 1:
				main();
				break;
			case 2:
				abort();
				break;
			default:
				cout<<"Bueno, lo tomare como un no"<<endl;
				system("pause");
				abort();
				break;		
		}//fin del switch
	}
}