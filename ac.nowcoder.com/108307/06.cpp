#include<bits/stdc++.h>
#define ll long long
#define N 600005
using namespace std;
struct node{
	ll x,y;
}a[N];
struct point{
	ll x,y;
	bool flag;
};
vector<point> ans;
bool cmp(point x,point y)
{
	if (x.x==y.x)return x.y<y.y;
	return x.x<y.x;
}
ll n,s,pre[N],nex[N];
bool hx[N];
ll check(node x,node y,node z)
{
	ll X1=y.x-x.x;
	ll Y1=y.y-x.y;
	ll X2=z.x-y.x;
	ll Y2=z.y-y.y;
	return X1*Y2-X2*Y1;
}
void solve()
{
	ans.clear();
	s=0;
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i].x>>a[i].y,hx[i]=0;
	a[n+1]=a[1];
	for (int i=1;i<=n;i++)s+=a[i].x*a[i+1].y-a[i+1].x*a[i].y;
	for (int i=1;i<=n;i++)
	{
		if (i==1)pre[i]=n;
		else pre[i]=i-1;
		if (i==n)nex[i]=1;
		else nex[i]=i+1;
	}
	for (int j=1;j<=n;j++)
	{
		int i=pre[j],k=nex[j];
		if (check(a[i],a[j],a[k])==0)
		{
			hx[j]=1;
			nex[i]=k;
			pre[k]=i;
		}
	}
	for (int j=1;j<=n;j++)
	{
		if (hx[j])continue;
		int i=pre[j],k=nex[j];
		point x;
		x.x=a[j].x,x.y=a[j].y;
		x.flag=0;
		if (s>0)
		{
			if (check(a[i],a[j],a[k])>0)x.flag=1;
		}
		else {
			if (check(a[i],a[j],a[k])<0)x.flag=1;
		}
		ans.push_back(x);
	}
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans.size()<<'\n';
	for (auto[x,y,z]:ans)
	{
		cout<<x<<' '<<y<<' ';
		if (z==1)cout<<"YES\n";
		else cout<<"NO\n";
	}
}
int main()
{
	cin.tie(0)->ios::sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
