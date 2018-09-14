#include <iostream>
using namespace std;

int small(int *G1,int N)  // 3,2,1  //1,2,3
{
    for(int i=0;i<N-1;i++)
    {
        if(G1[i]>=G1[i+1])
            continue;
        else
            G1[i+1]=G1[i];
    }
    return G1[N-1];
}

int big(int *L1,int N)  // 3,2,1  //1,2,3
{
    for(int i=0;i<N-1;i++)
    {
        if(L1[i]<=L1[i+1])
            continue;
        else
            L1[i+1]=L1[i];
    }
    return L1[N-1];
}

bool rev(int *L,int *G,int N)
{
    int L1[N];
    int G1[N];
     
    for(int i=0;i<N;i++){
        L1[i]=L[i];
        G1[i]=G[i];
    }
    for(int i=0;i<N;i++){
        if((L[i]==L[N-i-1])&&(L[i]==G[i]))
            return true; 
        else if(small(G1,N)>=big(L1,N))
            return true;
        else
            return false;
    }
}
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        int x=0;
        int y=0;
        cin>>N;
        int L[N];
        int G[N];
       
        for(int i=0;i<N;i++)
            cin>>L[i];
            
        for(int i=0;i<N;i++)
            cin>>G[i];
        
        if(rev(L,G,N)){
                cout<<"both"<<"\n";
                continue;
        }
           
        for(int i=0;i<N;i++)
        {
            if(L[i]<=G[i]){
                x++;
                if(x==N)
                   cout<<"front"<<"\n";
            }
        }
        for(int i=0;i<N;i++)
        {
            if(L[i]<=G[N-i-1]){
                y++;
                if(y==N)
                   cout<<"back"<<"\n";
            }
        }    
                
        if((x!=N)&&(y!=N)){
                cout<<"none"<<"\n";
                continue;
            }
                
            
    }
}
