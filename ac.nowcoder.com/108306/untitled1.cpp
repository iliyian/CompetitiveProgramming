#include<bits/stdc++.h>
#define ll long long
#define N 1000005
#define t 31
#define P 998244353
#define mod 998244353
using namespace std;
ll n,a[N],hx[N],ans;
ll lg[N];
ll f[N][31];
ll fac[N * 2], invfac[N * 2], inv[N * 2];
ll qpow(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}
ll C(ll n, ll m) {
	return fac[n] * invfac[n - m] % mod * invfac[m] % mod;
}
void ST_pre()
{
	for (int i=1;i<=n;i++)f[i][0]=a[i];
	for (int j=1;j<=30;j++)
		for (int i=1;i<=n-(1<<j)+1;i++)
		f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int query(int l,int r)
{
	if (l==r)return f[l][0];
	int k=lg[r-l+1];
//	cout<<"!"<<r-l+1<<' '<<k<<endl;
	return min(f[l][k],f[r-(1<<k)+1][k]);
}

void dfs(int dep,int l,int r,int s)
{

//	cout<<s-1<<' '<<s-1+dep<<' '<<C(s-1+dep,s-1)<<endl;.
	ans=(ans+C(s-1+dep,s-1))%P;
	if (l>=r)return ;
	int m=query(l,r);
//	cout<<dep<<' '<<l<<' '<<r<<' '<<s<<' '<<m<<endl;
//	if (dep>=3)return ;
	dfs(dep+1,hx[m]+1,r,s-(hx[m]-l+1));
	dfs(dep+1,l,hx[m]-1,s-(r-hx[m]+1));
}
void solve()
{
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i],hx[a[i]]=i;
	ST_pre();
	ans=1;
	dfs(1,1,n,n);
	cout<<ans<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	fac[0] = inv[1] = fac[1] = invfac[1] = invfac[0] = 1;
	for (int i = 2; i <= N * 2 - 1; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = (P - P / i) * inv[P % i] % mod;
		invfac[i] = invfac[i - 1] * inv[i] % mod;
	}
	lg[1]=0;
	lg[2]=1;
	for (int i=3;i<=1000000;i++)lg[i]=lg[i>>1]+1;
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
