#include <iostream>
using namespace std;
struct nodo_pila
{ int dato;
nodo_pila* link;
};
void agregarpila(nodo_pila*&p,int arreglo[],int cantidad){
	for(int i=0;i<cantidad;i++){
	nodo_pila *nuevo_nodo=new nodo_pila();
	nuevo_nodo->dato=arreglo[i];
	nuevo_nodo->link=p;
	p=nuevo_nodo;
	}
}
	void pilavacia(nodo_pila *p){
		//return(p == NULL);
		string m[2]={"verdadero","falso"};
		cout<<"Vacia: ";
		if(p==NULL){
			cout<<m[0];
		}
		else{
			cout<<m[1];
		}
	}
	
	void sacarpila_completa(nodo_pila*&p){
		cout<<"retiramos: ";
		while(p!=NULL){
		nodo_pila *nodo_anterior;
		nodo_anterior=p;
		int aux=p->dato;
		p=p->link;
		delete nodo_anterior;
		cout<<aux;
		}
	}
	
	

int main(int argc, char *argv[]) {
	int v[3]={9,1,3};
	nodo_pila *p=NULL;
	agregarpila(p,v,3);
	sacarpila_completa(p);
	cout<<endl;
	pilavacia(p);
	return 0;
}

