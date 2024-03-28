#include <iostream>
using namespace std;
struct mat{
	int m[6][6]={0};//matriz
	int t=6;//tamanio
};
void mostrar_mat(mat a);//eje1
void cant_arcos(mat a);//eje2
void nodos_adyacente(mat a,int id);//eje3
void conjunto_der(mat a,int id);//eje 4
void conjunto_izq(mat a,int id);//eje 5
void conjunto_maximal(mat a);//eje 7

int main(int argc, char *argv[]) {
	mat a;
	a.m[1][2]=1;
	a.m[1][3]=1;
	a.m[3][2]=1;
	a.m[3][0]=1;
	a.m[3][3]=1;
	a.m[3][4]=1;
	a.m[4][5]=1;
	mostrar_mat(a);	
	//cant_arcos(a);
	nodos_adyacente(a,3);
	conjunto_der(a,3);
	conjunto_izq(a,3);
	conjunto_maximal(a);
	return 0;
}
void mostrar_mat(mat a){
	for(int i=0;i<a.t;i++) { 
		for(int j=0;j<a.t;j++) { 
			cout<<a.m[i][j];
		}
		cout<<endl;
	}
}
void cant_arcos(mat a){
	int cont=0;
	for(int i=0;i<a.t;i++) { 
		for(int j=0;j<a.t;j++) { 
			if(a.m[i][j]==1){
				cont++;
			}
		}
		
	}
	cout<<"el grafo tiene "<<cont<<" arcos";
}
void nodos_adyacente(mat a,int id){
	for(int i=0;i<a.t;i++) { 
		if(a.m[id][i]==1){
			cout<<id<<" es adyacente con "<<i<<endl;
		}
	}
	for(int i=0;i<a.t;i++) { 
		if(a.m[i][id]==1 && id!=i){
			cout<<id<<" es adyacente con "<<i<<endl;
		}
	}
}
void conjunto_der(mat a,int id){
	for(int i=0;i<a.t;i++) { 
		if(a.m[id][i]==1){
			cout<<i<<" es parte del conjunto derecho de "<<id<<endl;
		}
		
	}
}
void conjunto_izq(mat a,int id){
	for(int i=0;i<a.t;i++) { 
		if(a.m[i][id]==1){
			cout<<i<<" es parte del conjunto izquierdo de "<<id<<endl;
		}
		
	}
}

void conjunto_maximal(mat a){
	int cont=0;
	for(int i=0;i<a.t;i++) { 
		for(int j=0;j<a.t;j++) { 
			if(a.m[i][j]==1){
				cont++;
			}
		}
		if(cont==0){
			cout<<i<<" pertenece al conjunto maxilmal"<<endl;
		}
		cont=0;
		
	}
}
