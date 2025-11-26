#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define ll long long
#define P 998244353

ll n,a[N],f[N],d[N];
bool cmp(ll x,ll y)
{
	return x>y;
}
void solve() {
  cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ll ans=0;
//	for (int i=1;i<=n;i++)cout<<f[n-i+1]<<' '<<d[i-1]<<endl;
	for (int i=1;i<=n;i++)
	{
//		cout<<a[i]<<' ';
		ans=(ans+d[i-1]*(f[n-i+1]+1)%P*a[i])%P;
	}
	cout<<ans<<endl;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
	f[1]=0;d[0]=1,d[1]=2;
	for (int i=2;i<=200000;i++)f[i]=(f[i-1]*3+1)%P,d[i]=(d[i-1]*2)%P;
	
  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}
