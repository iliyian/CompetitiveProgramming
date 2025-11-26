#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
int n,a[N],b[N],sz[N],son[N];
bool ans[N];
vector<int> adj[N];
void dfs(int x,int fa)
{
	sz[x]=1;
	for (auto y:adj[x])
	{
		if (y==fa)continue;
		dfs(y,x);
		sz[x]+=sz[y];
		if (son[x]==-1||sz[y]>sz[son[x]])son[x]=y;
	}
}
tuple<int,int,multiset<int>,multiset<int> >M(int x,int fa)
{
	if (son[x]==-1)
	{
//		cout<<"!"<<x<<endl;
		multiset<int> A,B;
		if (a[x]==0&&b[x]==0)
		{
			ans[x]=1;
			return {1,1,A,B};
		}
		else {
			int ca=0,cb=0;
			if (a[x]==0)ans[x]=1,ca=1,B.insert(b[x]);
			else if (b[x]==0)ans[x]=1,cb=1,A.insert(a[x]);
			else if (a[x]!=b[x])A.insert(a[x]),B.insert(b[x]),ans[x]=0;
			else if (a[x]==b[x])ans[x]=1;
			return {ca,cb,A,B};
		}
	}
	auto [ca,cb,A,B]=M(son[x],x);
	for (auto y:adj[x])
	{
		if (y==fa||y==son[x])continue;
		auto [ca1,cb1,A1,B1]=M(y,x);
		for (auto z:B1)
		{
			if (A.contains(z))A.erase(A.find(z));
			else B.insert(z);
		}
		for (auto z:A1)
		{
			if (B.contains(z))B.erase(B.find(z));
			else A.insert(z);
		}
		ca+=ca1;
		cb+=cb1;
	}
	if (a[x]==0)ca++;
	else {
		if (B.contains(a[x]))B.erase(B.find(a[x]));
		else A.insert(a[x]);
	}
	if (b[x]==0)cb++;
	else{
		if (A.contains(b[x]))A.erase(A.find(b[x]));
		else B.insert(b[x]);
	}
//	cout<<x<<' '<<ca<<' '<<cb<<' '<<A.size()<<' '<<B.size()<<endl;
	if (ca>=B.size()&&cb>=A.size())ans[x]=1;
	else ans[x]=0;
	return {ca,cb,A,B};
}
void solve()
{
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i],adj[i].clear(),sz[i]=0,son[i]=-1,ans[i]=0;
	for (int i=1;i<=n;i++)cin>>b[i];
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	M(1,0);
	for (int i=1;i<=n;i++)cout<<ans[i];
	cout<<endl;
}
int main()
{
	std::cin.tie(nullptr)->sync_with_stdio(false);
//	freopen("d.in", "r", stdin);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
