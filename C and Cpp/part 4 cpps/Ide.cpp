#include <iostream>
using namespace std;

int main(){	
    
    int N;
    int M;
    int Q;
    int Ans;
    cin>>N>>M;
    while(M--)
    {
        cin>>Q;
        if(Q>=(N+2)&&(Q<((2*N)+1))){
            Ans=(N-((2*N)+1)-Q);
            cout<<Ans<<"\n";
        }
        else if((Q<=(3*N))&&(Q>=(2*N)+1)){
            Ans=(N-(Q-((2*N)+1)));
            cout<<Ans<<"\n";
        }
        
    }
    return 0;
}

