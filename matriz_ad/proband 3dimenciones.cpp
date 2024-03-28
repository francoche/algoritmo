#include <iostream>
using namespace std;
struct nodo{
	string nciudad;
};
struct arco{
	string tipo;
	int id_arco;
	
};
struct mat{
	int mat[6][6][3]={0};
	bool matb[6][6]={0};
	int t=6;
	arco vec[3];
	nodo v[6];
};
void min_mat(mat grafo);
int main(int argc, char *argv[]) {
	mat grafo;
	grafo.vec[0].tipo="a";
	grafo.vec[1].tipo="b";
	grafo.vec[2].tipo="c";
	grafo.v[0].nciudad="parana";
	grafo.v[1].nciudad="satafe";
	grafo.v[2].nciudad="cordoba";
	grafo.mat[0][1][0]=1;
	grafo.mat[0][2][1]=1;
	grafo.mat[0][2][2]=1;
	

	
	return 0;
}
void min_mat(mat grafo){
	int cont=0;
	for(int i=0;i<grafo.t;i++) { 
		for(int j=0;j<grafo.t;j++) { 
			if(grafo.matb[j][i]==true){
				cont++;
			}
		}
		if(cont==0){
		 cout<<grafo.v[j].nciudad<<" es minimo";
		}
	}
}
