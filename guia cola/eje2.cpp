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
	
	void cola_obtener (nodocola* &frente, nodocola* &fondo){
		int ndato = frente->dato;
		nodocola* aux = frente;
		frente = frente->link;
		delete aux;
		if(frente==NULL){
			fondo=NULL;	
		}
		cout<<ndato;
	}
		bool cola_vacia(nodocola *frente){
			if(frente==NULL){
				return true;
			}else{
				return false;
			}
		}
void colocar_vector(nodocola* &frente, nodocola* &fondo,int v[],int dimension){
	for(int i=0;i<dimension;i++) { 
		colaagregar(frente,fondo,v[i]);
	}
	for(int i=0;i<dimension;i++) { 
		cola_obtener(frente,fondo);
	}
	
}
int main(int argc, char *argv[]) {
	nodocola *frente=NULL;
	nodocola *fondo=NULL;
	int v[3]={9,1,3};
	colocar_vector(frente,fondo,v,3);
	if(cola_vacia(frente)){
		cout<<"cola vacia";
	}else{
		cout<<"cola no vacia";
	}
	return 0;
}

