#include<bits/stdc++.h>
#define N 300005
using namespace std;
int n,d[N],flag;
vector<int> adj[N];
vector<pair<int,int> > ans;
void dfs(int x,int fa)
{
	d[x]=d[fa]+1;
	for (auto y:adj[x])
	{
		if (y==fa)continue;
		dfs(y,x);
	}
}
bool cmp(int x,int y)
{
	return d[x]>d[y];
}
int dp(int x,int fa)
{
//	cout<<'M'<<x<<' '<<fa<<'\n';
	int g=adj[x].size();
	if (x!=1)g--;
	if (g==0)return x;
	else if (g==1)
	{
		for (auto y:adj[x])
		{
			if (y==fa)continue;
			return dp(y,x);
		}
	}
	else {
		vector<int> son;
		for (auto y:adj[x])
		{
			if (y==fa)continue;
			int s=dp(y,x);
			son.push_back(s);
		}
		sort(son.begin(),son.end(),cmp);
//		cout<<x<<endl;
//		for (auto z:son)cout<<z<<' ';
//		cout<<endl;
		if (son.size()%2==0)
		{
			int cnt=0;
			for (int i=0;i<son.size();i++)if (d[son[i]]-d[x]!=1)cnt++;
			if (x==1)
			{
				for (int i=0;i<son.size();i+=2)if (i+1<son.size())ans.push_back({son[i],son[i+1]});
				return x;
			}
			else if (cnt)
			{
				ans.push_back({x,son[0]});
				for (int i=1;i<son.size();i+=2)if (i+1<son.size())ans.push_back({son[i],son[i+1]});
//				cout<<"!"<<son[son.size()-1]<<endl;
				return son[son.size()-1];
			}
			else 
			{
				for (int i=0;i<son.size();i+=2)if (i+1<son.size())ans.push_back({son[i],son[i+1]});
				return x;
			}
		}
		else{
			
			for (int i=1;i<son.size();i+=2)if (i+1<son.size())ans.push_back({son[i],son[i+1]});
			return son[0];	
		}
	}
}
void solve()
{
	flag=1;
	cin>>n;
	ans.clear();
	for (int i=1;i<=n;i++)adj[i].clear();
	for (int i=1,x,y;i<n;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	d[0]=0;
	dfs(1,0);
	int son=dp(1,0);
	if (son!=1&&adj[1].size()%2==1)
	{
		if (d[son]==2)flag=0;
		else ans.push_back({1,son});
	}
	if (flag)
	{
		cout<<ans.size()<<'\n';
		for (auto[x,y]:ans)cout<<x<<' '<<y<<'\n';
	}
	else cout<<-1<<'\n';
}
int main()
{
	// freopen("d.in", "r", stdin);
	// freopen("d.out", "w", stdout);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
