#include<bits/stdc++.h>
using namespace std;
const int N=6e3+5;
int T,cnt,q[N*2],to[N*2],val[N*2],head[N],x,y,z,n,a[N],b[N],dis[N][N],dp[N][N],f[N];
inline void add(int x,int y,int z){
	q[++cnt]=head[x];to[cnt]=y;val[cnt]=z;head[x]=cnt;
}
void Make_d(int pre,int t,int s,int dist){
	dis[pre][t]=dist;
	for (int i=head[t];i!=0;i=q[i])
	  if (to[i]!=s)
	    Make_d(pre,to[i],t,dist+val[i]);
}
inline void Init(){
	memset(head,0,sizeof(head));cnt=0;
    memset(dp,101,sizeof(dp));
    memset(f,101,sizeof(f));
}
void dfs(int t,int s){
	for (int i=head[t];i!=0;i=q[i])
	  if (to[i]!=s)
	    dfs(to[i],t);
	for (int i=1;i<=n;i++)
	  if (dis[t][i]<=b[t]){
	  	dp[t][i]=a[i];
	  	for (int j=head[t];j!=0;j=q[j])
	  	  if (to[j]!=s)
	  	    dp[t][i]+=min(dp[to[j]][i]-a[i],f[to[j]]);
	  	f[t]=min(f[t],dp[t][i]);
	  }
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		Init();
		cin>>n; 
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=n;i++) cin>>b[i];
	    for (int i=1;i<n;i++){
	    	cin>>x>>y>>z;
	    	add(x,y,z);add(y,x,z);
		}
		for (int i=1;i<=n;i++)
		  Make_d(i,i,0,0);
		dfs(1,0);
		cout<<f[1]<<'\n';
	} 
    return 0;
}
