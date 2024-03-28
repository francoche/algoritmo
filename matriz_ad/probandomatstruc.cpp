#include <iostream>
using namespace std;
struct nodoasig{
	string nombre;
	int tamanio;
};
struct mat{
	int mat[6][6][3]={0};
	int t=6;
	int t2=3;
	string vec_arco[3];
	struct nodoasig vec_nodo[6];
};
void mostrar_rel(mat a);
int main(int argc, char *argv[]) {
	mat a;
	a.vec_arco[0]="aerea";
	a.vec_arco[1]="terrestre";
	a.vec_arco[2]="acuatica";
	a.vec_nodo[1].nombre="cordoba";
	a.vec_nodo[2].nombre="santa fe";
	a.mat[1][2][0]=1;
	a.mat[1][2][1]=1;
	a.mat[1][2][2]=1;
	mostrar_rel(a);
	//cout<<a.vec_nodo[1].nombre;
	
	return 0;
}
void mostrar_rel(mat a){
	for(int i=1;i<a.t;i++) { 
		for(int j=1;j<a.t;j++) { 
			for(int k=0;k<a.t2;k++) { 
				if(a.mat[i][j][k]==1){
					cout<<a.vec_nodo[i].nombre;//<<"tiene una ruta con"<<a.vec_nodo[j].nombre<<" de tipo"<<a.vec_arco[k]<endl;
				}
			}	
		}
	}
}

