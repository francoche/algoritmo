#include <iostream>
using namespace std;
struct nodocola{
	int dni;
	int tiempo_llegada;
	char tipo_paciente;
	int tiempo_secion;
	nodocola *link;
};
/*void colaagregar(nodocola *&frente,nodocola *&fondo,int dato){
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
	}*/
		bool cola_vacia(nodocola *frente){
			if(frente==NULL){
				return true;
			}else{
				return false;
			}
		}

	void farmacia_meter(nodocola *&frente,nodocola *&fondo,int dni,char cliente,int tiempo_secion,int tiempo_llegada){
		nodocola *nnodo=new(nodocola);
		nnodo->dni=dni;
		nnodo->tipo_paciente=cliente;
		nnodo->tiempo_llegada=tiempo_llegada;
		nnodo->tiempo_secion=tiempo_secion;
		nnodo->link=NULL;
		if(fondo!=NULL){
			fondo->link=nnodo;
		}
		else{
			frente=nnodo;
		}
		fondo=nnodo;
	}
	void farmacia_mostrar(nodocola *&frente,nodocola *&fondo){
		int cont=1;
		while(!cola_vacia(frente)){
			int dni =frente->dni;
			int tiempo_llegada =frente->tiempo_llegada;
			int tiempo_secion =frente->tiempo_secion;
			char cliente =frente->tipo_paciente;
			nodocola* aux = frente;
			frente = frente->link;
			delete aux;
			cout<<"-->[vaciado minuto: "<<tiempo_llegada<<"] "<<"(dni"<<dni<<",duracion "<<tiempo_secion<<",tipo "<<cliente<<")"<<endl; 
			if(frente==NULL){
				fondo=NULL;	
			}
			cont++;
		}
		cout<<"cola vacia";
	}
	
int main(int argc, char *argv[]) {
	nodocola *frente=NULL;
	nodocola *fondo=NULL;
	farmacia_meter(frente,fondo,12,'c',8,22);
	farmacia_meter(frente,fondo,13,'a',82,21);
	farmacia_meter(frente,fondo,11,'e',8123,25);
	farmacia_meter(frente,fondo,1,'i',8123,2123);
	farmacia_meter(frente,fondo,124,'p',8123,21);
	farmacia_meter(frente,fondo,122,'a',83,221);
	farmacia_mostrar(frente,fondo);
	return 0;
}

