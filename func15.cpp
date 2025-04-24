void dibujagato(char gato[3][3]);
bool checa3linea(char gato[3][3], char X);
void puntos();


void dibujagato(char gato[3][3]){

	cout <<gato[1][1]; color(8); cout<<"\t |"; color(15); cout<<gato[2][1]; color(8); cout<<"\t |"; color (15); cout<<gato[3][1]<<endl;
	color(8); cout<<"________________________"<<endl; color(15);
	cout <<gato[1][2]; color(8); cout<<"\t |"; color(15); cout<<gato[2][2]; color(8); cout<<"\t |"; color (15); cout<<gato[3][2]<<endl;
	color(8); cout<<"________________________"<<endl; color(15);
	cout <<gato[1][3]; color(8); cout<<"\t |"; color(15); cout<<gato[2][3]; color(8); cout<<"\t |"; color (15); cout<<gato[3][3]<<endl;
	cout<<endl;
}//FIN DE LA FNCION DIBUJA GATOS


bool checa3linea(char gato[3][3], char jugada){
	
//para checar las filas	
	for(int c=1; c<4; c++){
		if (gato[c][1] == jugada && gato [c][2] == jugada and gato[c][3] == jugada){
			return true;
		}//fin del if	
	}//fin del primer for
//para checar las columnas
	for(int f=1; f<4; f++){
		if (gato[1][f] == jugada && gato [2][f] == jugada and gato[3][f] == jugada){
			return true;
		}//fin del if	
	}//fin del primer for
//para checar las diagonales
	if (gato[1][1] == jugada && gato[2][2] == jugada && gato[3][3] == jugada){
		return true;       
	}
	if (gato[1][3] == jugada && gato[2][2] == jugada && gato[3][1] == jugada){
		return true;
	}
	if (gato[3][1] == jugada && gato[2][2] == jugada && gato[1][3] == jugada){
		return true;
	}
	if (gato[3][3] == jugada && gato[2][2] == jugada && gato[1][1] == jugada){
		return true;
	}else{
		return false;
	}
}//FIN DE LA FUNCION PARA CHECAR SI ALGUIEN HA GANADO/////////////////

void puntos(){
	color(9);
	cout<<"___NOMBRE_____PUNTAJE_____"<<endl;
	
	for(int i=0; i<9; i++){
	cout<<"|"; color(15); cout<<puntaje[i].nombre<<"   "<<puntaje[i].punto<<endl;
	}//fin del for
	system("pause");
	main();
}
