#include<bits/stdc++.h>
#define N 500005
#define ll long long
using namespace std;
ll n,t[N],a[N];
ll ans[N];
vector<ll> adj[N],adj1[N];
bool v[N];
priority_queue<pair<ll,ll> > q;
void spread(int x)
{
	for (auto y:adj[x])
	{
//		cout<<x<<' '<<y<<endl;
		ll T=ans[x]+abs(a[y]-a[x])*2;
		if (ans[y]==0||T<ans[y])
			ans[y]=T;
		
		if (v[y]==0)v[y]=1,q.push({-T,y}); 
		spread(y);
	}
}
int main()
{
//	freopen("d.in", "r", stdin);
//	freopen("d.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>t[i];
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		if ((a[t[i]]<a[i]&&a[t[i]]<a[t[t[i]]])||(a[t[t[i]]]<a[t[i]]&&a[i]<a[t[i]]))
		{
//			cout<<abs(a[t[i]]-a[i])<<' '<<i<<endl;
			q.push({(-abs(a[t[i]]-a[i])),i});
			ans[i]=abs(a[t[i]]-a[i]);
			v[i]=1;
			adj1[t[i]].push_back(i);
		} 
		else adj[t[i]].push_back(i);
	}
	while(!q.empty())
	{
		auto [T,x]=q.top();
		q.pop();
		v[x]=0;
		spread(x);
		for (auto y:adj1[x])
		{
			ll T1=(abs(a[x]-a[y])-T)*2+T;
			if (T1>ans[y])
			{
				ans[y]=T1;
				if (v[y]==0)v[y]=1,q.push({-T1,y});
			}
		}
	}
	for (int i=1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}
