//============================================================================
// Name        : MemTestDinamica.cpp
// Author      : Alcidemar Lopes
// Version     :
// Copyright   : Your copyright notice
// Description : 
//============================================================================

#include <iostream>
#include <sys/time.h>
#include <vector>

using namespace std;

//============================================================================
int main(){
/*Medição do tempo */
	struct timeval begin, end, mid;
	gettimeofday(&begin, NULL);
/*Medição do tempo */

	vector<int> vetor;
	double vetTempo[25];
	int j, avalia=0;

	
	
	for (int i=0;i<500000;i++){
		j=rand()%500000;
		vetor.push_back(j);
		
		if (i/25==2000){			
				gettimeofday(&mid, NULL);
			    double diff_sec = difftime(mid.tv_sec, begin.tv_sec) * 1000000;
			    double diff_milli = difftime(mid.tv_usec, begin.tv_usec);
				cout<<"Avalia "<<avalia+1<<": "<<diff_sec + diff_milli<<"ms"<<endl;
							/*ATENÇÃO^^^ */
			avalia++;
		}
	}
	
	//exibe o vetor
	// for (int i=0;i<500000;i++){
	// 	cout <<" |"<< vet[i]<<"|";
	// }
	// cout<<endl;
	//========================================================================

/*Fim medição do tempo */
	gettimeofday(&end, NULL);
    double diff_sec = difftime(end.tv_sec, begin.tv_sec) * 1000000;
    double diff_milli = difftime(end.tv_usec, begin.tv_usec);
	cout<<"Tempo total de execução do programa: "<<diff_sec + diff_milli<<"ms"<<endl;
/*Fim medição do tempo */
	cout <<"Avaliações: "<<avalia<<endl;
 
 return 0;
}
