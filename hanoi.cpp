#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <locale.h>
#include "colores.cpp"
using namespace std;
/*
    ANGEL EDUARDO MUÑOZ PEREZ - LUIS JAVIER GARNICA ESCAMILLA - FABIAN CANDIA VILLA
    ANALISIS DE ALGORITMOS_ CUALTOS (Prof. Hector)
    Febrero 2025
    Ejercicio: Programacion Dinamica: TORRES DE HANOI
*/

// FUNCIONES
void movimientos(int numDiscos, char torreA, char torreC, char torreB);
void manual(int numDiscos);
void EscribeTorres(const vector<vector<int> >& torres);
void victoria();

// Main
int main() {

    int opcion;
    int numDiscos = 0;

    while (true) {
        numDiscos =0;
        system("cls");
        color(10);
        cout << "  BIENVENIDO A MI PROGRAMA\n   LAS TORRES DE HANOI" << endl;
        cout << "_______|_____|_____|_______" << endl; color(15);

        cout << "Ingresa la cantidad de discos (3-7): ";
        //If para validar la entrada de numero de discos
        if (cin >> numDiscos && numDiscos >= 3 && numDiscos <= 7) {
        // Imprimir los medios triángulos
	    for (int i = 1; i <= numDiscos; i++) {
	        color(7);cout << "|";  // Inicio del primer medio triángulo
	        // Primer medio triángulo (imprime 'o')
	        for (int j = 1; j <= i; j++) {
	            color(i);cout << "o";
	        }
	        // Espacios para separar la segunda barra
	        for (int j = 0; j < numDiscos - i; j++) {
	            cout << " ";
	        }
	        color(7);cout << "|";  // Segunda barra central
	        // Espacios entre la segunda barra y la última
	        for (int j = 0; j < numDiscos; j++) {
	            cout << " ";
	        }
	        color(7);cout << "|" << endl;  // Última barra alineada

	    }//fin del for dibuja triangulos
			cout<<"========================================="<<endl;
			cout<<" A     B     C"<<endl;color(15);
            movimientos(numDiscos, 'A', 'C', 'B');
            int movimientostotales = pow(2, numDiscos) - 1; // Formula de los intentos minimos para resolver las torres
            color(8); cout << "Se necesitaron " << movimientostotales << " movimientos para resolverlo" << endl; color(15);
	   // Imprimir la estructura con los "o" en la tercera columna
	    for (int i = 1; i <= numDiscos; i++) {
	        color(7); cout << "|";  // Primera barra	
	        // Espacios en la primera columna
	        for (int j = 0; j < numDiscos; j++) {
	            cout << " ";
	        }	
	        color(7); cout << "|";  // Segunda barra	
	        // Espacios en la segunda columna
	        for (int j = 0; j < numDiscos; j++) {
	            cout << " ";
	        }	
	        color(7); cout << "|";  // Tercera barra donde se escribirán los "o"	
	        // Espacios antes de imprimir los "o" para alinearlos bien
	        for (int j = 0; j < (numDiscos - i); j++) {
	            cout << " ";
	        }	
	        // Imprimir los "o" alineados correctamente en la tercera columna
	        for (int j = i; j >= 1; j--) {
	            color(i); cout << "o";
	        }	
	        cout << endl;color(7);
	    }//fin del for para imprimir las torres del final
	    cout << "=========================================" << endl;
	    cout << " A     B     C" << endl;
	    color(15);
		} else {
            cout << "Por favor, ingresa un número válido (del 3 al 7)" << endl;
            cin.clear();                                            //borramos el dato de memeroia e ignoramos
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue;
        }//fin del if de validacion
        //Pequeño menu para reintentar o haerlo manual
        color(14);
        cout << "¿Quieres hacerlo con otra cantidad?" << endl; color(10);
        cout << "[1] SI "; color(12); cout << "  NO [2]"; color(6); cout << "  Hacerlo yo [3]" << endl; color(15);

        if (cin >> opcion) {
            switch (opcion) {
                case 1:
                    continue;
                case 2:
                    return 0;
                case 3:
                    manual(numDiscos);
                    break;
                default:
                    cout << "Pon un numero del 1 al 3 estimado" << endl;
                    main();
            }
        } else {
            cout << "Pero pon un numero estimado nomam"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            main();
        }
    }
    return 0;
}

/* FUNCION DE LOS MOVIMIENTOS AUTOMATICOS:
     funcion recursiva donde el caso base es cuando solo queda un disco chico en la torre A y lo demas este en torre C
     de intermedio usamos una repeticon de intercalar entre lo que se ocupa para poder poner el resto de discos en la torre
     de apoyo (torre b) y poder mover el disco mas grande en la torre C. la función recursiva divide el problema en 
     subproblemas más pequeños, resuelve cada uno de ellos y combina las soluciones para resolver el problema completo.
*/
void movimientos(int numDiscos, char torreA, char torreC, char torreB) {
    //caso base: si solo queda un disco (disco final) ponlo en la torre final
    if (numDiscos == 1) {
        cout << "Mover disco " << numDiscos << " de " << torreA << " a " << torreC << endl;
        
    } else {
        //mover disco (final-1) hacia la torre intermedia que la usamod como torre de apoyo 
        movimientos(numDiscos - 1, torreA, torreB, torreC);
        cout << "Mover disco " << numDiscos << " de " << torreA << " a " << torreC << endl;
        //mover discos de torre de apoyo a torre final
        movimientos(numDiscos - 1, torreB, torreC, torreA);
    }
}

/* FUNCION DEL MODO MANUAL:
    Escribimos e implementamos las torres como vectores de numeros para manejar los discos y su tamaño por valor numerico
    hay validacion para asegurar que las otrres que escogemos esten en el rango de 1-3 y tambien para asegurar que de la torre que agarremos exista un disco
    DEspues de validar hacemos los movimientos en las torres con back y pop como si estas se tratasen de una pila
    y al final chechamos que el disco que introducimos no sea mas grande que el disco que se encuentre en esa torre, si es asi, regresamos con un push.back
    Al final comfirmamos que el juego se completo cuando la torre[2] (3ra torre) tenga el mismo tamaño que la 1era
*/
void manual(int numDiscos) {
    system("cls");
    vector<vector<int> > torres(3);
    for (int i = numDiscos; i >= 1; i--) {
        torres[0].push_back(i);
    }
    EscribeTorres(torres);

    while (true) {
        int Torigen, Tdestino;
        color(8);
        cout << "Escribe de qué torre quieres mover el disco (1-3): ";
        cin >> Torigen;
        cout << "Escribe a qué torre quieres mover el disco (1-3): "; 
        cin >> Tdestino; color(15);

        Torigen--;
        Tdestino--;
        
        //validacion de que las torres esten en el rango de 1 a 3
        if (Torigen < 0 || Torigen > 2 || Tdestino < 0 || Tdestino > 2) {
            color(12);
            cout << "Torre no válida. Intenta de nuevo." << endl; color(15);
            continue;
        }
        //validacion de que la torre de donde agarro tenga algo
        if (torres[Torigen].empty()) {
            color(12);
            cout << "No hay discos en esta torre." << endl; color(15);
            continue;
        }
        //tomamos y quitamos de la torre origen
        int disco = torres[Torigen].back();
        torres[Torigen].pop_back();
        //checamos que no haya disco menor en esa torre
        if (!torres[Tdestino].empty() && disco > torres[Tdestino].back()) {
            color(12);
            cout << "Movimiento no válido. No puedes colocar un disco más grande sobre uno más pequeño." << endl; color(15);
            torres[Torigen].push_back(disco);
            continue;
        }

        torres[Tdestino].push_back(disco);
        EscribeTorres(torres);
        //verificamos que se haya logrado el objetivo
        if (torres[2].size() == numDiscos) {
            victoria();
            break;
        }
    }
}

/* FUNCION PARA ESCRIBIR LAS TORRES
    usamos un ciclo para dibujar los discos con un numero que simboliza el tamaño, como toma de referencia el arreglo que 
    implementamos como si fuera una pila, al hacerle llamadas repetidas en el juego, este se actualiza con cada moviemiento
*/   
void EscribeTorres(const vector<vector<int> >& torres) {
    for (int i = 0; i < 3; i++) {
        color(1); cout << "Torre " << i + 1 << ": ";
        for (int j = 0; j < torres[i].size(); j++) {
            color(3); cout << torres[i][j] << " ";
        }
        cout << "\n"; color(15);
    }
}

// PANTALLA DE VICTORIA
void victoria() {
    int opc;
    color(2);
    cout << "¡FELICIDADES! HAS GANADO" << endl;
    color(10);
    cout << "¿Quieres volver a intentarlo?" << endl;
    cout << "SI [1]             NO [2]" << endl;

    if (cin >> opc) {
        switch (opc) {
            case 1:
                main();
                break;
            case 2:
                exit(0);
            default:
            	color(4);
                cout << "NO SABES LEER O QUE!?" << endl;
                color(15);
                exit(0);
        }
    } else {
        cout << "ya mejor nada, ADIOS" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        exit(0);
    }
}
