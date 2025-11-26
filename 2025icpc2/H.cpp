#include<bits/stdc++.h>
#define ll long long
#define P 998244353
#define N 3005
using namespace std;
ll n,root,dp[N],ans;
vector<int> adj[N],leaves;
bool hx[N][N],g[N];
void find(int x,int fa)
{
	bool flag=0;
	for (auto y:adj[x])
	{
//		cout<<'!'<<x<<' '<<y<<' ';
		if (y==fa)continue;
		flag=1;
		find(y,x);
	}
//	cout<<'!'<<flag<<' '<<x<<endl;
	if (!flag)leaves.push_back(x);
}
void dfs(int x,int fa,int len,int last)
{
	int flag=0;
	for (auto y:adj[x])
	{
		if (y==fa)continue;
		flag++;
	}
	if (flag==0)
	{
		if (hx[root][x])return ;
		if (last==len)ans+=dp[len]-1;
		else ans+=dp[len]-dp[len-last]-1;
		ans%=P;
		cout<<root<<' '<<x<<' '<<len<<' '<<last<<endl;
		hx[root][x]=hx[x][root]=1;
	}
	else if(flag==1){
		for (auto y:adj[x])
		{
			if (y==fa)continue;
			dfs(y,x,len+1,last+1);
		}
	}
	else {
		for (auto y:adj[x])
		{	
			if (y==fa)continue;
			if (g[x]==0)dfs(y,x,len+1,last+1),g[x]=1;
			else dfs(y,x,len+1,1);
		}
	}
}
void solve()
{
	ans=1;
	cin>>n;
	leaves.clear();
	for (int i=1;i<=n;i++)
	{
		adj[i].clear();
		g[i]=0;
		for (int j=1;j<=n;j++)hx[i][j]=0;
	}
	for (int i=1,x,y;i<n;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	find(1,0);
	for (auto x:leaves)
	{
//		cout<<x<<endl;
		root=x;
		dfs(x,0,1,1);
	}
	cout<<ans<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	dp[1]=1;
	for (int i=2;i<=3000;i++)dp[i]=dp[i-1]*i%P;
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
