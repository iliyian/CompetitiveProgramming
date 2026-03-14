#include<bits/stdc++.h>
using namespace std;
long long T,r,b,m;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","wb",stdout);
	for(scanf("%lld",&T);T;T--){
		scanf("%lld%lld%lld",&r,&b,&m);
		if((b*2+r)%4)
			puts("Alice");
		else
			puts("Bob");
	}
}
