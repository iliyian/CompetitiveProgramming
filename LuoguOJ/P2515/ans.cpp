#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=1e2+7;
int n,m,w[N],v[N],d[N];
int num,hed[N],to[N],net[N],fl[N];
inline void add(int x,int y){
	num++;
	to[num]=y;
	net[num]=hed[x];
	hed[x]=num;
}
int dfn[N],low[N],cnt,co[N],col,st[N],top;
inline void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	top++;
	st[top]=u;
	for(int i=hed[u];i;i=net[i]){
		int v1=to[i];
		if(!dfn[v1]){
			tarjan(v1);
			low[u]=min(low[u],low[v1]);
		}else if(!co[v1])
		       low[u]=min(low[u],dfn[v1]);
	}
	if(dfn[u]==low[u]){
		col++;
		co[u]=col;
		while(st[top]!=u){
			co[st[top]]=col;
			top--;
		}
		top--;
	}
}
int num1,hed1[N],to1[N],net1[N];
inline void add1(int x,int y){
	num1++;
	to1[num1]=y;
	net1[num1]=hed1[x];
	hed1[x]=num1;
}
int sv[N],sw[N],dp[N][510],size[N];
inline void dfs(int x){
   for(int i=sw[x];i<=m;i++) dp[x][i]=sv[x];
   for(int i=hed1[x];i;i=net1[i]){
   	  int v1=to1[i];
   	  dfs(v1);
   	  for(int j=m-sw[x];j>=0;j--)
   	   for(int k=0;k<=j;k++)
   	    dp[x][j+sw[x]]=max(dp[x][j+sw[x]],dp[x][j+sw[x]-k]+dp[v1][k]);
   }	
}
int main(){
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) w[i]=read();
	for(int i=1;i<=n;i++) v[i]=read();
	for(int i=1;i<=n;i++) d[i]=read(),
	add(d[i],i);
	for(int i=0;i<=n;i++)
	 if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++)
	 if(co[d[i]]!=co[i]){
	 	add1(co[d[i]],co[i]);
	 	fl[co[i]]=1;
	 } 
	for(int i=1;i<=col;i++)
		if(fl[i]==0) add1(0,i);
	for(int i=1;i<=n;i++)
		sv[co[i]]+=v[i],sw[co[i]]+=w[i];
	dfs(0);
	printf("%d",dp[0][m]);
	return 0;
}