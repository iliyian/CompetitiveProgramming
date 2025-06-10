#include<bits/stdc++.h>
using namespace std;
void readu(int &x){
	x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
}
int T,n,m,ind[900005];
vector<int> g[900005];
int main(){
	for(readu(T);T;T--){
		readu(n);readu(m);
		memset(ind,0,4*(3*n+3));
		for(int i=0;i<3*n+3;i++)
			g[i].clear();
		bool valid=true;
		for(int i=1;i<=m;i++){
			int I,J,col;
			readu(I);readu(J);readu(col);
			int x=(J+1)/2,y=n+ n-I+1,z=n+n+ I-J/2;
			if(col==y)swap(x,y);
			else if(col==z)swap(x,z);
			else if(col!=x)
				valid=false;
			g[x].emplace_back(y);
			g[x].emplace_back(z);
			ind[y]++;
			ind[z]++;
		}
		vector<int> q;
		for(int i=1;i<=3*n;i++)
			if(ind[i]==0)
				q.emplace_back(i);
		for(int hd=0;hd<q.size();hd++){
			for(int i:g[q[hd]]){
				ind[i]--;
				if(ind[i]==0)
					q.emplace_back(i);
			}
		}
		if(valid && q.size()==3*n)
			puts("Yes");
		else puts("No");
	}
	return 0;
}
