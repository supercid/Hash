import java.util.t

package memtest;

/**
 *
 * @author Cid
 */
public class MemTest {
    
    public static void main(String[] args) {
    struct timeval begin, end, mid;
    gettimeofday(&begin, NULL);

	int vet[500000];
	double vetTempo[25];
	int j, avalia=0;
	vector<int> dyn;

	
	
	for (int i=0;i<500000;i++){
		j=rand()%500000;
		vet[i]=j;
		dyn.push_back(j);
	
		if (i/25==2000){			
			gettimeofday(&mid, NULL);
			double diff_sec = difftime(mid.tv_sec, begin.tv_sec) * 1000000;
			double diff_milli = difftime(mid.tv_usec, begin.tv_usec);
		system.out.println("Avalia " + (avalia+1);
                       //<<"Avalia "<<avalia+1<<": "<<diff_sec + diff_milli<<"ms"<<endl;
			avalia++;
		}
	}
	
				gettimeofday(&end, NULL);
			    double diff_sec = difftime(end.tv_sec, begin.tv_sec) * 1000000;
			    double diff_milli = difftime(end.tv_usec, begin.tv_usec);
				cout<<"Tempo total de execução do programa: "<<diff_sec + diff_milli<<"ms"<<endl;
	cout <<"Avaliações: "<<avalia<<endl;
        
        
        
        
        
        
        
    }

}
