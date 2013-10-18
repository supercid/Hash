//============================================================================
// Name        : MemTestEstatica.cpp
// Author      : Alcidemar Lopes
// Version     :
// Copyright   : Your copyright notice
// Description : 
//============================================================================

#include <iostream>
#include <sys/time.h>
#include <fstream>

using namespace std;

//============================================================================
int main(){
ofstream fout("Tempos/StaticTimeMacintosh.dat");

/*Medição do tempo */
	struct timeval begin, end, mid;
	gettimeofday(&begin, NULL);
/*Medição do tempo */

	int vet[500000];
	double vetTempo[25];
	int avalia=0;
	
	for (int i=0;i<500000;i++){
		//vet[i]=rand()%500000;
		vet[i]=0;
		
		if ((i%2000)==0){
			gettimeofday(&mid, NULL);
			double diff_sec = difftime(mid.tv_sec, begin.tv_sec) * 1000000;
			double diff_milli = difftime(mid.tv_usec, begin.tv_usec);

			cout<< i <<"   "<<"Avalia "<<avalia+1<<": "<<diff_sec + diff_milli<<"ms"<<endl; //Terminal
			fout << i <<"   " <<diff_sec + diff_milli<< endl;	//Arquivo
			avalia++;
		}
	}

	gettimeofday(&end, NULL);
    double diff_sec = difftime(end.tv_sec, begin.tv_sec) * 1000000;
    double diff_milli = difftime(end.tv_usec, begin.tv_usec);
	cout<<"Tempo total de execução do programa: "<<diff_sec + diff_milli<<"ms"<<endl;

	cout <<"Avaliações: "<<avalia<<endl;
 
 fout.close();
 return 0;
}
