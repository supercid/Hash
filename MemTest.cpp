#include <iostream>
#include <ctime>
#include <time.h>
#include <stack>
#include <sys/time.h>
using namespace std;


class MedeTempo {
private:
	string funcao;
	clock_t inicio;
public:
	MedeTempo(const string &f) { 
		inicio = clock();
		funcao = f;	
	}
	~MedeTempo() {
		clock_t total = clock() - inicio;
		cout << "Tempo para a funcao " << funcao << " " << double(total)/CLOCKS_PER_SEC<< " segundos "<<endl;
	}
};

//################################################################################################################
int main(){
	MedeTempo mt("main");
	int vet[500000];
	int j, avalia=0;

	
	
	for (int i=0;i<500000;i++){
		j=rand()%500000;
		vet[i]=j;	
	
		if (i/25==2000){
			avalia++;
		}
	}
	

	//exibe o vetor
	// for (int i=0;i<500000;i++){
	// 	cout <<" |"<< vet[i]<<"|";
	// }

	cout <<endl;
	cout<<avalia<<endl;
	return 0;
}

