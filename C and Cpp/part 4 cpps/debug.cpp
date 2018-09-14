#include <bits/stdc++.h>
using namespace std;
int facto(long long n){
   if(n==0)
      return 1;
   else
      return n*facto(n-1);
}
int nCr(long long int n,long long int r){
    unsigned long long int nr,dr,num,dra,drb;
	nr=facto(n);
	dra=facto(n-r);
	drb=facto(r);
	dr=dra*drb;
	num=nr/dr;
	return num;
}
int main() {
    long long int n,a,x,sum;
	cin>>n;
        int i=n;
	cin>>a;
	cin>>x;
	long long r=0,t,c,d;
	while(i+1)
	{
			t=pow(a,(n-r));
			c=pow(x,r);
			d=nCr(n,r);
			sum=d*t*c;
			cout<<sum<<" ";
			r++;
                        i--;
	}
	return 0;
}
