#include<bits/stdc++.h>
#define N 6005
#define M 100005
#define ll long long
#define int ll
using namespace std;
ll n,m;
ll tot,head[M],Next[M],edge[M],ver[M];
ll dist[N][N];
bool vis[N][N];
struct Tree{
	ll a[N + 3] {};
	void build() {
		for (int i = 0; i <= N+2; i++) {
			a[i] = LLONG_MAX;
		}
	}
	void change(int x, ll c) {
		x++;
		for (int i = x; i <= N+2; i += i & -i) a[i] = std::min(a[i], c);
	}
	ll query(int x) {
		x++;
		ll ans = LLONG_MAX;
		for (int i = x; i > 0; i -= i & -i) ans = std::min(ans, a[i]);
		return ans;
	}
}tr[N];
void add(ll x,ll y,ll z)
{
	ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
}
void dij()
{
	for (int i=1;i<=n;i++)
	{
		tr[i].build();
		for (int j=0;j<=n;j++)
			dist[i][j]=LLONG_MAX;
	}
	priority_queue<pair<ll,ll> > q;
	dist[1][0]=0;
	tr[1].change(0,0);
	q.push({0,1});
	for (;!q.empty();)
	{
		ll x=q.top().second,k=(x-1)/n;
		q.pop();
		if (x%n==0)x=n;
		else x=x%n;
		if (vis[x][k])continue;
		vis[x][k]=1;  
		for (int i=head[x];i;i=Next[i])
		{
			int y=ver[i],z=edge[i];
//			if (z==-1)
//			{
//				if (dist[x][k]<tr[y].query(k+1))
//				{
//					dist[y][k+1]=dist[x][k];
//					tr[y].change(k+1,dist[y][k+1]);
//					q.push({-dist[y][k+1],y+(k+1)*n});
//				}
//			}
//			else {
//				if (dist[x][k]+z<tr[y].query(k))
//				{
//					dist[y][k]=dist[x][k]+z;
//					tr[y].change(k,dist[y][k]);
//					q.push({-dist[y][k],y+k*n});
//				}
//			}
			if (z==-1)
			{
				if (dist[x][k]<dist[y][k+1])
				{
					dist[y][k+1]=dist[x][k];
//					tr[y].change(k+1,dist[y][k+1]);
					q.push({-dist[y][k+1],y+(k+1)*n});
				}
			}
			else {
				if (dist[x][k]+z<dist[y][k])
				{
					dist[y][k]=dist[x][k]+z;
//					tr[y].change(k,dist[y][k]);
					q.push({-dist[y][k],y+k*n});
				}
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<n;i++)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	for (int i=1;i<=m;i++)
	{
		ll x,y;
		cin>>x>>y;
		add(x,y,-1);
		add(y,x,-1);
	}
	
	dij();

	for (int i=1;i<=n;i++)
	{
		ll minn=LLONG_MAX;
		for (int j=0;j<=n;j++)
		{
			minn=min(minn,dist[i][j]);
			dist[i][j]=minn;
		}
	}
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=0;j<=n;j++)
//			cout<<dist[i][j]<<' ';
//		cout<<endl;
//	}
	for (int j=0;j<=n;j++)
	{
		ll ans=0;
		for (int i=1;i<=n;i++)ans+=dist[i][j];
		cout<<ans<<endl;
	}
	return 0;
}
