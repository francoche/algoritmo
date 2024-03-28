#include <iostream>
using namespace std;

struct nodo_arco{
	int id_arco;
	string tipo_relacion;
	struct nodo_grafo * destino;
	nodo_arco * link;
};


struct nodo_grafo{
	int identificador;
	string nombre;
	string sexo;
	string correo;
	string estado_civil;
	nodo_arco*lista_arc=NULL;
	nodo_grafo *link;
};

void rel_amorosa_cant(nodo_grafo*grafo);
void emitanio(nodo_grafo&*grafo,int id);
int main(int argc, char *argv[]) {
	
	
	

	return 0;
}
void rel_amorosa_cant(nodo_grafo*grafo){
	nodo_grafo *aux=grafo; nodo_arco *auxarco=NULL; int cont=0; string nombrerels[1000];
	while(aux!=null){
		auxarco=aux->lista_arc;
		while(auxarco!=NULL){
		if(auxarco->tipo_relacion=="amorosa"){
			nombrerels[cont]=auxarco->destino->nombre;
			cont++;
			
		}
		auxarco=auxarco->link;
		}
		if(cont>1){
			cout<<aux->nombre<<"se relaciona de forma amorosa con: "<<endl;
			for(int i=0;i<cont;i++){
				cout<<nombrerels[i];
			}
		}
		cont=0;
		aux=aux->link;
		
	}
}
	void rigth_baja(nodo_grafo*&grafo){
		nodo_arco*actual=grafo->lista_arc;nodo_arco *anterior=NULL;
		while(grafo->lista_arc!=NULL){
			while(actual!=NULL){
				anterior=actual;
				actual=actual->link;
				delete anterior;
			}
			grafo->lista_arc=NULL;
			cout<<"borre un arco"<<endl;
			
		}
		
	}
	
	
	bool borrar_arco_primero(nodo_arco*&lista_arc,nodo_grafo*dir){
		nodo_arco *actual=lista_arc; nodo_arco *anterior=NULL;
		while(actual!=NULL){
			if(actual->destino==dir){
				if(anterior==NULL){
					lista_arc=actual->link;
					cout<<"borre el arco "<<actual->id_arco;
					delete actual;
					return true;
				}else{
					anterior->link=actual->link;
					cout<<"borre";
					delete actual;
					return true;
				}
			}
			anterior=actual;
			actual=actual->link;
		}
		return false;
		
		
	}
	
}
	void left_baja(nodo_grafo*grafo,nodo_grafo* dir_nodo){
		nodo_grafo *actual=grafo;
		while(actual!=NULL){
			while(borrar_arco_primero(actual->lista_arc,dir_nodo));
			actual=actual->link;
		}
	}

void emitanio(nodo_grafo&*grafo,int id){
	nodo_grafo *aux=grafo;
	while(aux!=NULL){
		if(aux->identificador==id){
			break;
		}else{
			aux=aux->link;
		}
	}
	if(aux!=NULL){
		rigth_baja(aux);
		left_baja(aux);
	}
	else{
		cout<<"no se encontro";
	}
}
