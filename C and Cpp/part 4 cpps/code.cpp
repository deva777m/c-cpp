#include <iostream>
using namespace std;

int main(){	
    
    int N;
    int M;
    int Q;
    int Ans;
    cin>>N>>M;
    int center=N*2+1;
    int max=N*3;
    int min=N+2;
    while(M--)
    {
        cin>>Q;
        if((Q>=min)&&(Q<center)){
            Ans=(N-(center-Q));
            cout<<Ans<<"\n";
        }
        else if((Q<=max)&&(Q>=center)){
            Ans=(N-(Q-center));
            cout<<Ans<<"\n";
        }
        else{
            cout<<0<<"\n";
        }
        
    }
    return 0;
}



