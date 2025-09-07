#include<bits/stdc++.h>
#define ll long long
#define N 4000
#define P 998244353
using namespace std;
ll n,a[N],dp[N],f[N][N],L[N],R[N];
//ll find(int l,int r)
//{
//    ll minn=INT_MAX,c=-1;
//    for (int i=l;i<=r;i++)
//        if (a[i]<=minn)minn=a[i],c=i;
//    return c;
//}
//ll dfs(int l,int r)
//{
//    if (l>r)return 1;
//    if (l==r)return 1;
//    if (dp[l][r]!=-1)return dp[l][r];
//    ll m=find(l,r);
//    if (m==l)dp[l][r]=dfs(l,m-1)*dfs(m+1,r)*(r-m);
//    else if (m==r)dp[l][r]=dfs(l,m-1)*dfs(m+1,r)*(m-l);
//    else dp[l][r]=dfs(l,m-1)*dfs(m+1,r)*(m-l)*(r-m);
//    cout<<l<<' '<<r<<' '<<dp[l][r]<<endl;
//    return dp[l][r];
//}
ll t[N];
void clear()
{
	for (int i=0;i<=n+1;i++)t[i]=0;
}
void add(ll x,ll s)
{
	x++;
	for (;x<=n+1;x+=x &-x)t[x]=(t[x]+s)%P;
}
ll ask(ll x)
{
	ll s=0;
	x++;
	for (;x;x-=x&-x)s=(s+t[x])%P;
	return s;
}
void solve()
{
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i],dp[i]=0,R[i]=n+1,L[i]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=i-1;j>0;j--)
			if (a[j]<a[i])
			{
				L[i]=j;
				break;
			}
		for (int j=i+1;j<=n;j++)
			if (a[j]<a[i])
			{
				R[i]=j;
				break;
			}
	}
	clear();
	add(0,1);
	for (int i=1;i<=n;i++)
	{
		vector<ll> now(n+1,0);
		for (int k=1;k<=i;k++)
		if (L[k]<k&&i<R[k])
		{
			ll v=a[k],s=ask(v);
			now[v]=(now[v]+s)%P;
		}
		clear();
		for (int v=1;v<=n;v++)if (now[v])add(v,now[v]);
	}
	cout<<ask(n)<<endl;
}
int main()
{
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
