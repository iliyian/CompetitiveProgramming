#include<bits/stdc++.h>
#define ll long long
#define double long double
#define N 300005
#define eps 1e-18l
using namespace std;
ll n,k,a[N];
double check(double x)
{
	double s=0;
	for (int i=1;i<=n;i++)s+=(x*a[i])/(x*a[i]+1);
	return s;
}

int main()
{
//	freopen("M.in","r",stdin);
//	freopen("m.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for (int i=1;i<=n;i++)cin>>a[i];
	double l=0,r=1e18;
	for (int i=1;i<=5000;i++)
	{
		double mid=(l+r)/2;
//		cout<<mid<<' '<<check(mid)<<endl;
		if (check(mid)<=k)l=mid;
		else r=mid;
	}
//	cout<<check(l)<<endl;
//	cout<<l<<' '<<r<<endl;
	for (int i=1;i<=n;i++)
	{
		double res=(l*a[i])/(l*a[i]+1);
		cout<<fixed<<setprecision(12)<<res<<'\n';
	}
	return 0;
}
//0.999936757445936780637729
//0.000000000999936780637729
