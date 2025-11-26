#include<bits/stdc++.h>
#define ll long long
#define N 300005								
using namespace std;
vector<int> adj[N];
vector<pair<int,int> > ans;
int n,m,hx[N],a[N],cnt;
bool cmp(int x,int y)
{
	return hx[x]<hx[y];
}
void dfs(int x)
{
//	cout<<x<<endl;
	for (auto y:adj[x])
	{
		if (hx[y]<=cnt)continue;
		while(hx[y]>cnt+1)
		{
			cnt++;
			ans.push_back({x,a[cnt]});
			dfs(a[cnt]);
		}
		if (hx[y]==cnt+1)
		{
			cnt++;
			dfs(y);
		}
	}
}
void solve()
{
	ans.clear();
	cnt=0;
	cin>>n>>m;
	for (int i=0;i<=n;i++)adj[i].clear();
	for (int i=1,x,y;i<=m;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i=1;i<=n;i++)cin>>a[i],hx[a[i]]=i,adj[0].push_back(a[i]);
	for (int i=1;i<=n;i++)sort(adj[i].begin(),adj[i].end(),cmp);
	dfs(0);
	cout<<ans.size()<<endl;
	for (auto [x,y]:ans)
	{
		cout<<x<<' '<<y<<endl;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
