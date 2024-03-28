#include <iostream>
using namespace std;
struct nodocola{
	int dni;
	int llegada;
	int salida;
	char cliente;
	nodocola *link;
};
bool cola_vacia(nodocola *frente){
	if(frente==NULL){
		return true;
	}else{
		return false;
	}
}
	void estado_cola(nodocola *frenteO,nodocola *frenteP,nodocola *frenteE){
		/*if(!cola_vacia(frenteO)){
			cout<<"cola  o NO vacia"<<endl;
		}else{cout<<"cola  o  vacia"<<endl;};
		if(!cola_vacia(frenteE)){
			cout<<"cola  e NO vacia"<<endl;
		}else{cout<<"cola  e  vacia"<<endl;};
		if(!cola_vacia(frenteP)){
			cout<<"cola  p NO vacia"<<endl;
		}else{cout<<"cola  p  vacia"<<endl;};*/ //es lo mismo q lo q esta despues.
		if(cola_vacia(frenteO)){
			cout<<"cola  o  vacia"<<endl;
		}else{cout<<"cola  o NO vacia"<<endl;};
		if(cola_vacia(frenteE)){
			cout<<"cola  e  vacia"<<endl;
		}else{cout<<"cola  e NO vacia"<<endl;};
		if(cola_vacia(frenteP)){
			cout<<"cola  p  vacia"<<endl;
		}else{cout<<"cola  p NO vacia"<<endl;};
	}
void farmacia2_agregar(nodocola *&frenteO,nodocola *&fondoO,nodocola *&frenteP,nodocola *&fondoP,nodocola *&frenteE,nodocola *&fondoE,int dni,int llegada,int salida,char cliente){
	if(cliente=='o'){
		nodocola *nnodo=new(nodocola);
		nnodo->dni=dni;
		nnodo->cliente=cliente;
		nnodo->llegada=llegada;
		nnodo->salida=salida;
		nnodo->link=NULL;
		if(fondoO!=NULL){
			fondoO->link=nnodo;
		}
		else{
			frenteO=nnodo;
		}
		fondoO=nnodo;	
	}
	if(cliente=='p'){
		nodocola *nnodo=new(nodocola);
		nnodo->dni=dni;
		nnodo->cliente=cliente;
		nnodo->llegada=llegada;
		nnodo->salida=salida;
		nnodo->link=NULL;
		if(fondoP!=NULL){
			fondoP->link=nnodo;
		}
		else{
			frenteP=nnodo;
		}
		fondoP=nnodo;	
	}
	if(cliente=='e'){
		nodocola *nnodo=new(nodocola);
		nnodo->dni=dni;
		nnodo->cliente=cliente;
		nnodo->llegada=llegada;
		nnodo->salida=salida;
		nnodo->link=NULL;
		if(fondoE!=NULL){
			fondoE->link=nnodo;
		}
		else{
			frenteE=nnodo;
		}
		fondoE=nnodo;	
	}
}
void farmacia2_mostrar(nodocola *&frenteO,nodocola *&fondoO,nodocola *&frenteP,nodocola *&fondoP,nodocola *&frenteE,nodocola *&fondoE,char cliente){
	if(cliente=='o'&& !cola_vacia(frenteO)){
		nodocola* aux = frenteO;
		frenteO = frenteO->link;
		cout<<"-->[vaciado minuto: "<<aux->llegada<<"] "<<"(dni"<<aux->dni<<",duracion "<<aux->salida<<",tipo "<<aux->cliente<<")"<<endl;
		delete aux;
		if(frenteO==NULL){
			fondoO=NULL;	
		}
		//estado_cola(frenteO,frenteP,frenteE);
	}
	if(cliente=='p'&& !cola_vacia(frenteP)){
		nodocola* aux = frenteP;
		frenteP = frenteP->link;
		cout<<"-->[vaciado minuto: "<<aux->llegada<<"] "<<"(dni"<<aux->dni<<",duracion "<<aux->salida<<",tipo "<<aux->cliente<<")"<<endl;
		delete aux;
		if(frenteP==NULL){
			fondoP=NULL;	
		}
		//estado_cola(frenteO,frenteP,frenteE);
	}
	if(cliente=='e'&& !cola_vacia(frenteE)){
		nodocola* aux = frenteE;
		frenteE = frenteE->link;
		cout<<"-->[vaciado minuto: "<<aux->llegada<<"] "<<"(dni"<<aux->dni<<",duracion "<<aux->salida<<",tipo "<<aux->cliente<<")"<<endl;
		delete aux;
		if(frenteE==NULL){
			fondoE=NULL;	
		}
		//estado_cola(frenteO,frenteP,frenteE);
	}
	estado_cola(frenteO,frenteP,frenteE);
}


int main(int argc, char *argv[]) {
	nodocola *frenteO=NULL;
	nodocola *fondoO=NULL;
	nodocola *frenteP=NULL;
	nodocola *fondoP=NULL;
	nodocola *frenteE=NULL;
	nodocola *fondoE=NULL;
	farmacia2_agregar(frenteO,fondoO,frenteP,fondoP,frenteE,fondoE,12,7,8,'e');
	farmacia2_agregar(frenteO,fondoO,frenteP,fondoP,frenteE,fondoE,11,7,8,'p');
	farmacia2_agregar(frenteO,fondoO,frenteP,fondoP,frenteE,fondoE,15,7,8,'o');
	farmacia2_agregar(frenteO,fondoO,frenteP,fondoP,frenteE,fondoE,10,7,8,'o');
	farmacia2_agregar(frenteO,fondoO,frenteP,fondoP,frenteE,fondoE,10,7,8,'p');
	farmacia2_agregar(frenteO,fondoO,frenteP,fondoP,frenteE,fondoE,10,7,8,'e');
	farmacia2_mostrar(frenteO,fondoO,frenteP,fondoP,frenteE,fondoE,'o');
	farmacia2_mostrar(frenteO,fondoO,frenteP,fondoP,frenteE,fondoE,'o');
	farmacia2_mostrar(frenteO,fondoO,frenteP,fondoP,frenteE,fondoE,'p');
	farmacia2_mostrar(frenteO,fondoO,frenteP,fondoP,frenteE,fondoE,'p');
	return 0;
}

