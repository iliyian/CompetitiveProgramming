#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int T,q[N],to[N],head[N],s[2],val[N],n,x,y,z,cnt;
void add(int x,int y,int z){
	q[++cnt]=head[x];to[cnt]=y;val[cnt]=z;head[x]=cnt;
}
void dfs(int t,int fa,int opt){
	++s[opt];
	for (int i=head[t];i!=0;i=q[i])
	  if (to[i]!=fa)
	    dfs(to[i],t,opt^val[i]);
}
signed main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while (T--){
		s[1]=s[0]=0;cnt=0;
		cin>>n; 
		for (int i=1;i<=n;i++) head[i]=0;
		for (int i=1;i<n;i++){
			cin>>x>>y>>z;
			add(x,y,z%2);add(y,x,z%2);
		}
		dfs(1,0,0);
		cout<<s[0]*s[0]*s[0]+s[1]*s[1]*s[1]<<'\n';
	}
}
