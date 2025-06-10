#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
}
int T,n,a[300005],pa[300005];
int nxt[300005],rr[300005];
bool cmp(int x,int y){
	if(a[x]!=a[y])
		return a[x]<a[y];
	while(a[x]==a[y] && x!=0 && y!=0){
		x=nxt[x];
		y=nxt[y];
	}
	return a[x]>a[y];
}
vector<int> g[300005];
int main(){
	freopen("gaokao.in","r",stdin);
	freopen("gaokao.out","wb",stdout);
	for(read(T);T;T--){
		read(n);
		for(int i=0;i<=n+3;i++){
			nxt[i]=0;
			rr[i]=i;
			g[i].clear();
		}
		a[0]=1<<30;
		for(int i=1;i<=n;i++){
			read(a[i]);
			pa[i]=i-1;
			while(a[i]>=a[pa[i]])
				pa[i]=pa[pa[i]];
			g[pa[i]].emplace_back(i);
		}
		for(int i=n;i>=0;i--){
			if(g[i].size()==0)
				continue;
			sort(g[i].begin(),g[i].end(),cmp);
			for(int j=0;j+1<g[i].size();j++)
				nxt[rr[g[i][j]]]=g[i][j+1];
			nxt[i]=g[i][0];
			rr[i]=rr[g[i].back()];
		}
		for(int i=nxt[0];i!=0;i=nxt[i])
			printf("%d ",a[i]);
		puts("");
	}
	return 0;
}
