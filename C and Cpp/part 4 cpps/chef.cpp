#include <iostream>
using namespace std;

int count(char *a,char *b,int N){
    
    int c=0;
    for(int i=0;i<N;i++){
        if(a[i]==b[i]){
            c++;
        }
    }
    return c;
} 

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;  //number of questions
	    int c[N+1];
	    char a[N],b[N];
	    
	    for(int i=0;i<N;i++){
	        cin>>a[i];
	    }
	    
	    for(int i=0;i<N;i++){
	        cin>>b[i];
	    }
	    
	    for(int i=0;i<N+1;i++){
	        cin>>c[i];
	    }
	    
	    int cnt=count(a,b,N);
	    
	    cout<<c[cnt]<<"\n";
	    
	return 0;
}
}
