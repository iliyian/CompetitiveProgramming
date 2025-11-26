#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[40];
ll l,r;
void solve()
{
	cin>>l>>r;
	l++,r++;
	bool flag=0;
	while(1)
	{
		for (int i=2;i<=32;i++)
		if (f[i]>=r)
		{
			ll a=(l-1)/f[i-1],b=(r-1)/f[i-1];
			if (a==b)
			{
//				cout<<"?"<<endl;
				l-=f[i-1]*a;
				r-=f[i-1]*b;
				break;
			}
			else if (a==2&&b==3)
			{
				l-=f[i-1]*2;
				r-=f[i-1]*2;
				break;
			}
			else {
				flag=1;
				break;
			}
		}
//		cout<<'!'<<l<<' '<<r<<endl;
		if (flag)break;
	}
	cout<<l-1<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	f[1]=1;
	for (int i=2;i<=32;i++)f[i]=f[i-1]*4;
//	cout<<f[i]<<' ';
//	cout<<endl;
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
/*
4611686018427387904
998244353998244353
1152921504606846976
288230376151711744
*/
