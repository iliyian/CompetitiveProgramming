#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
int n,a[N],b[N],c[N],cnt,ans,siz[N],d[N],w[N];
int dfn[N],low[N],num,st[N],top,f[N];
bool ins[N],flag[N];
vector<int> adj[N],g[N];
void tarjan(int x)
{
	dfn[x]=low[x]=++num;
	ins[x]=1,st[++top]=x;
	for (auto y:adj[x])
	{
		if (!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if (ins[y])low[x]=min(low[x],dfn[y]);
	}
	if (low[x]==dfn[x])
	{
		int y;cnt++;
		do{
			y=st[top--],ins[y]=0;
			c[y]=cnt;siz[cnt]++;
			f[cnt]+=w[y];
			if (a[y]!=0)flag[cnt]=1;
		}while(x!=y);
	}
}
void dfs(int x)
{
	ans+=siz[x];
	d[x]=1;
	for (auto y:g[x])
	{
		if (d[y])continue;
		dfs(y);
	}
}
void solve()
{
	ans=cnt=num=top=0;
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i],adj[i].clear(),g[i].clear(),siz[i]=d[i]=ins[i]=dfn[i]=low[i]=st[i]=f[i]=0,w[i]=1;
	for (int i=1;i<=n;i++)cin>>b[i];
	for (int x=1;x<=n;x++)
	{
		flag[x]=0;
		for (int i=1,y;i<=b[x];i++)
		{
			cin>>y;
			if (x==y)w[x]++;
			adj[x].push_back(y);
		}    
	}
	for (int i=1;i<=n;i++)if (!dfn[i])tarjan(i);
	for (int x=1;x<=n;x++)
		for (auto y:adj[x])
		{
			if (c[x]!=c[y])g[c[x]].push_back(c[y]);
		}
	for (int i=1;i<=cnt;i++)if (d[i]==0&&flag[i]&&f[i]>1)dfs(i);
	cout<<ans<<endl;
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}