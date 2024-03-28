#include <iostream>
using namespace std;
struct arcoasig{
	string tiporuta;
	int id;
	int hayruta;
};
struct nodoasig{
	string nombre;
	int id;
};
struct grafo{
	arcoasig m[4][4][3];
	nodoasig vector[4];
	int t=4;
	int t2=3;
	
};
void borrar_ruta_c(grafo &m);

int main(int argc, char *argv[]) {
	grafo m;
	m.vector[0].nombre="parana";
	m.vector[1].nombre="santa fe";
	m.vector[2].nombre="cordoba";
	m.vector[3].nombre="jujy";
	m.m[0][1][0].hayruta=1;
	m.m[0][1][0].tiporuta="a";
	m.m[0][1][1].hayruta=1;
	m.m[0][1][1].tiporuta="b";
	m.m[0][1][2].hayruta=1;
	m.m[0][1][2].tiporuta="c";
	
	
	return 0;
}
void borrar_ruta_c(grafo &m){
	int cont;
	for(int i=0;i<m.t;i++) { 
		cont=0;
		for(int j=0;j<m.t;j++) { 
			for(int k=0;k<m.t2;k++) { 
				if(m.m[i][j][k].hayruta==1){
					cont++;
				}
			}
		}
		if(cont==0){
			cout<<m.vector[i].nombre<<" es terminal"<<endl;
			for(int l=0;l<m.t;l++) { 
				for(int n=0;n<m.t2;n++) { 
					if(m.m[i][l][n].hayruta!=0 && m.m[i][l][n].tiporuta=="c"){
						m.m[i][l][n].hayruta=0;
					}
				}
			}
			}
		}
	}
}





















