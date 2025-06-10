#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 998244353;

ll power(ll a,ll b)
{
	ll s=1;
	for (;b;b>>=1)
	{
		if (b&1)s=(s*a)%MOD;
		a=a*a%MOD;
	}
	return a;
}

int n,w,x,y;
int main()
{
	cin>>n>>w>>x>>y;
	
	ll a=(1LL*n%MOD)*(x%MOD)%MOD;
	
	cout<<y%MOD*power(a,MOD-2)%MOD << endl;
	
	return 0;
}
