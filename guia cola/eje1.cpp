#include <iostream>
using namespace std;
struct nodocola{
	int dato;
	nodocola *link;
};

void colaagregar(nodocola *&frente,nodocola *&fondo,int dato){
	nodocola *nnodo=new(nodocola);
	nnodo->dato=dato;
	nnodo->link=NULL;
	if(fondo!=NULL){
		fondo->link=nnodo;
	}
	else{
		frente=nnodo;
	}
	fondo=nnodo;
}

	int cola_obtener (nodocola* &frente, nodocola* &fondo){
		int ndato = frente->dato;
		nodocola* aux = frente;
		frente = frente->link;
		delete aux;
		if(frente==NULL){
			fondo=NULL;	
		}
		return ndato;
	}
	bool cola_vacia(nodocola *frente){
		if(frente==NULL){
			return true;
		}else{
			return false;
		}
	}
int main(int argc, char *argv[]) {
	nodocola *frente=NULL;
	nodocola *fondo=NULL;
	colaagregar(frente,fondo,5);
	colaagregar(frente,fondo,3);
	colaagregar(frente,fondo,4);
	int aux=cola_obtener(frente,fondo);
	cout<<aux;
	 aux=cola_obtener(frente,fondo);
	cout<<aux;
	 aux=cola_obtener(frente,fondo);
	cout<<aux;
	bool auxx=cola_vacia(frente);
	cout<<auxx;
	return 0;
}

