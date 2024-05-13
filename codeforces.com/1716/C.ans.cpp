#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
const int N=2e5+5;
int T,n,a[2][N],f[2][N];
int G(int x){ return x>0?x:0ll; }
void solve()
{
	scanf("%lld",&n);
	for(int i=0;i<=1;i++)
		for(int j=1;j<=n;j++)  scanf("%lld",&a[i][j]);
	a[0][1]=-1;
	f[0][n]=a[0][n],f[1][n]=a[1][n];
	for(int i=0;i<=1;i++)
		for(int j=n-1;j>=1;j--)
			f[i][j]=max(f[i][j+1]-1,a[i][j]);
	f[0][n]=max(a[1][n]-1,a[0][n]);
	f[1][n]=max(a[0][n]-1,a[1][n]);
	for(int i=0;i<=1;i++)
		for(int j=n-1;j>=1;j--)
			f[i][j]=max(f[i][j+1]-1,max(a[i^1][j]-2*(n-j)-1,a[i][j]));
	int ans=f[0][1]+2*n,rec=a[1][1]+1;
	for(int i=2,p=1;i<=n;i++,p^=1)
	{
		ans=min(ans,rec+G(f[p][i]-rec)+2*(n-i+1));
		rec=max(rec+1,a[p][i]+1);
		rec=max(rec+1,a[p^1][i]+1);
	}
	ans=min(ans,rec);
	printf("%lld\n",ans);
}
signed main()
{
  freopen("C.in", "r", stdin);
  freopen("C.ans", "w", stdout);
	scanf("%lld",&T);
	while(T--)  solve();
return 0;
}