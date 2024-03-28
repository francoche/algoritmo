#include <iostream>
using namespace std;

struct nodo_arco{
	int id_arco;
	struct nodo_grafo * destino;
	nodo_arco * link;
};
typedef struct nodo_arco NArco;


struct nodo_grafo{
	int id;
	nodo_arco*lista_arc=NULL;
	nodo_grafo *link;
};
typedef struct nodo_grafo NGrafo;
void grafo_agregar_nodo(nodo_grafo*& listan,int id_nodo); //agrga un nodo
void grafo_agregar_arco(nodo_grafo*a,int id_arco,int id_nodo_origen,int id_nodo_destino);// agreega un arco
void mostrar_nodos(nodo_grafo*a);
void mostrar_arcos(nodo_grafo *a,int id_nodo);
void borrar_arco(int id_origen,int id_destino,nodo_grafo*&grafo);
void mostrar_grafo(nodo_grafo*grafo);//muestra el gragfo
void rigth_baja(nodo_grafo*&grafo);//borra el conjunto derecho de un nodo
bool borrar_arco_primero(nodo_arco*&lista_arc,nodo_grafo*dir);//borra el primer arco con la dir pasada como paramtro;
void left_baja(nodo_grafo*grafo,int id_grafo);//borra el conjunto izquierdo de un nodo;
void borrar_nodo(nodo_grafo*&grafo,int id_nodo);//borra un nodo;

int main(int argc, char *argv[]) {
	nodo_grafo * a =NULL;
	grafo_agregar_nodo(a,121);
	grafo_agregar_nodo(a,8);
	grafo_agregar_nodo(a,4);
	grafo_agregar_nodo(a,32);
	grafo_agregar_nodo(a,87);
	grafo_agregar_arco(a,73,121,8);
	grafo_agregar_arco(a,85,121,87);
	grafo_agregar_arco(a,27,121,32);
	grafo_agregar_arco(a,7,4,121);
	grafo_agregar_arco(a,10,4,121);
	grafo_agregar_arco(a,5,8,4);
	grafo_agregar_arco(a,81,87,4);
	//mostrar_nodos(a);
	//mostrar_arcos(a,87);
	mostrar_grafo(a);
	cout<<"////////////////////////////////////////////////////////"<<endl;
	borrar_nodo(a,121);
	cout<<"////////////////////////////////////////////////////////"<<endl;
	mostrar_grafo(a);
	
	
	return 0;
}
void grafo_agregar_nodo(nodo_grafo*& listan,int id_nodo){
	nodo_grafo *aux=listan;
	while(aux!=NULL){
		if(aux->id==id_nodo){
			cout<<"error";
			return;
		}
		aux=aux->link;
	}
	aux=new(nodo_grafo);
	aux->id=id_nodo;
	aux->link=listan;
	listan=aux;
		
	}

void grafo_agregar_arco(nodo_grafo*listan,int id_arco,int id_nodo_origen,int id_nodo_destino){
	nodo_grafo*nodo_origen=listan;
	nodo_grafo*nodo_destino=listan;
	while(nodo_origen!=NULL&&nodo_origen->id!=id_nodo_origen){
		nodo_origen=nodo_origen->link;
	}
	while(nodo_destino!=NULL&&nodo_destino->id!=id_nodo_destino){
		nodo_destino=nodo_destino->link;
	}
	if(nodo_origen==NULL || nodo_destino==NULL){
		cout<<"error";
		return;
	}
	nodo_arco *aux=new(nodo_arco);
	aux->id_arco=id_arco;
	aux->destino=nodo_destino;
	aux->link=nodo_origen->lista_arc;
	nodo_origen->lista_arc=aux;
}
	void mostrar_nodos(nodo_grafo*a){
		nodo_grafo*aux=a;
		while(aux!=NULL){
			cout<<aux->id<<endl;
			aux=aux->link;
		}
	}

		
		
		
void mostrar_arcos(nodo_grafo *a,int id_nodo){
	nodo_grafo*aux=a;
	while(aux!=NULL){
		if(aux->id==id_nodo){
			cout<<"existe el nodo";
			nodo_arco *auxarco=aux->lista_arc;
			while(auxarco!=NULL){
				cout<<auxarco->id_arco<<" ";
				auxarco=auxarco->link;
			}
			return;
		}
		aux=aux->link;
	}
	if(aux==NULL){
		cout<<"no se encontro el nodo";
	}
}
void borrar_arco(int id_origen,int id_destino,nodo_grafo*&grafo){
	nodo_grafo *aux=grafo;
	while(aux!=NULL){
		if(aux->id==id_origen){
			nodo_arco *auxarco=aux->lista_arc; nodo_arco*auxarcoanterior=NULL;
			while(auxarco!=NULL){
				if(auxarco->destino->id==id_destino){
					if(auxarcoanterior==NULL){
						grafo->lista_arc=auxarco->link;
						delete auxarco;
					}else{
						auxarcoanterior->link=auxarco->link;
						delete auxarco;
					}
				}
				auxarcoanterior=auxarco;
				auxarco=auxarco->link;
			}
		}
		aux=aux->link;
	}
}
void mostrar_grafo(nodo_grafo*grafo){
nodo_grafo *auxgrafo=grafo;nodo_arco *auxarco=NULL;
while(auxgrafo!=NULL){
	cout<<"Nodo "<<auxgrafo->id<<endl;
	auxarco=auxgrafo->lista_arc;
	while(auxarco!=NULL){
		cout<<" "<<"Arco "<<auxarco->id_arco<<" -> Nodo "<<auxarco->destino->id<<endl;
		auxarco=auxarco->link;
	}
	auxgrafo=auxgrafo->link;
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
	
	
		void left_baja(nodo_grafo*grafo,nodo_grafo* dir_nodo){
			nodo_grafo *actual=grafo;
			while(actual!=NULL){
				while(borrar_arco_primero(actual->lista_arc,dir_nodo));
				actual=actual->link;
			}
		}

	void borrar_nodo(nodo_grafo*&grafo,int id_nodo){
		nodo_grafo *actual=grafo; nodo_grafo*anterior=NULL;
		while(actual!=NULL){
			if(actual->id==id_nodo){
				break;
			}else{
				anterior=actual;
				actual=anterior->link;
			}
		}
		if(actual!=NULL && anterior==NULL){
			grafo=actual->link;
		}
		else if(actual!=NULL){
			anterior->link=actual->link;
		}
		rigth_baja(actual);
		left_baja(grafo,actual);
		delete actual;
	}
			
			
			
			
			
			
