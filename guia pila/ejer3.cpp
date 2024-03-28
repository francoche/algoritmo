#include <iostream>
#include <string>
using namespace std;
struct nodo_pila
{ string dato;
nodo_pila* link;
};

void agregarpila(nodo_pila*&p,string c){
	int cantletras=c.size();
	for(int i=0;i<cantletras;i++){
		nodo_pila *nuevo_nodo=new nodo_pila();
		nuevo_nodo->dato=c.substr(i,1);
		nuevo_nodo->link=p;
		p=nuevo_nodo;
	}
}

	void sacarpila(nodo_pila*&p){
		while(p!=NULL){
		nodo_pila *nodo_anterior;
		nodo_anterior=p;
		string aux=p->dato;
		p=p->link;
		delete nodo_anterior;
		cout<< aux;
		}
	}	
int main(int argc, char *argv[]) {
	string a="acamah";
	nodo_pila *p=NULL;
	agregarpila(p,a);
	sacarpila(p);
	return 0;
}

