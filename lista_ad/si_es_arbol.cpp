#include <iostream>
using namespace std;
struct nodo_arco{
	int id_arco;
	struct nodo_grafo * destino;
	nodo_arco * link;
};


struct nodo_grafo{
	int id;
	nodo_arco*lista_arc=NULL;
	nodo_grafo *link;
};
void grafo_agregar_nodo(nodo_grafo*& listan,int id_nodo);
void grafo_agregar_arco(nodo_grafo*a,int id_arco,int id_nodo_origen,int id_nodo_destino);
void es_arbol(nodo_grafo*grafo);
void mostrar_grafo(nodo_grafo*grafo);

int main(int argc, char *argv[]) {
	
	nodo_grafo * a =NULL;
	grafo_agregar_nodo(a,4);
	grafo_agregar_nodo(a,3);
	grafo_agregar_nodo(a,2);
	grafo_agregar_nodo(a,1);
	
	grafo_agregar_arco(a,1,1,2);
	grafo_agregar_arco(a,12,1,3);
	grafo_agregar_arco(a,3,2,4);
	mostrar_grafo(a);
	es_arbol(a);
	
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
		
void es_arbol(nodo_grafo*grafo){
	nodo_grafo *aux=grafo; nodo_arco *auxarco=NULL; int cont=0; nodo_grafo *raiz=grafo; nodo_grafo *aux_id=NULL;
	nodo_grafo *aux2=grafo;
	while(aux!=NULL){
		auxarco=aux->lista_arc;
		while(auxarco!=NULL){
			if(auxarco->destino==aux){
				cout<<"no es arbol 1";
				return;
			}
			auxarco=auxarco->link;
		}
		aux=aux->link;
	}
	
	aux=grafo; auxarco=NULL;
	
	while(aux!=NULL){
		auxarco=aux->lista_arc;
		while(auxarco!=NULL){
			auxarco=auxarco->link;
			cont++;
		}
		if(cont>2){
			cout<<"no es arbol 2";
			return;
		}
		cont=0;
		aux=aux->link;
	}
	
	aux=grafo; auxarco=NULL;
	
	while(aux!=NULL){
		auxarco=aux->lista_arc;
		while(auxarco!=NULL){
			if(auxarco->destino==raiz){
				cout<<"no es arbol 3";
				return;
			}
			auxarco=auxarco->link;
			
		}
		
		aux=aux->link;
	}
	
	aux=grafo; auxarco=NULL;
	cont=0;
	aux2=aux;
	while(aux2!=NULL){
		while(aux!=NULL){
			auxarco=aux->lista_arc;
			while(auxarco!=NULL){
				if(auxarco->destino==aux2){
					cont++;
				}
				auxarco=auxarco->link;
			}
			if(cont>1){
				cout<<"no es arbol 4";
				return;
			}
			aux=aux->link;
		}
		cont=0;
		aux=grafo;
		aux2=aux2->link;
	}
	
	
	
	cout<<"es arbol";
	
	
	
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






















