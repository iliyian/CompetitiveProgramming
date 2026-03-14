#include<bits/stdc++.h>
using namespace std;
long long keq2(long long n){return (n/2)*((n+1)/2);}
long long T,n,K;
int main(){
	freopen("geometry.in","r",stdin);
	freopen("geometry.out","wb",stdout);
	for(scanf("%lld",&T);T;T--){
		scanf("%lld%lld",&n,&K);
		if(K%2){
			puts("0");
			continue;
		}
		int k=K/2;
		printf("%lld\n",(n%k)*keq2(n/k+1)+(k-n%k)*keq2(n/k));
	}
	return 0;
}
