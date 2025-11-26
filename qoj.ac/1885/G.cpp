#include<bits/stdc++.h>
#define ll long long
#define M 1000005
#define N 500005
using namespace std;
int n,t[M][26],cnt,a[M];
string st[N];
ll ans,f[N];
vector<int> fac[M];
void insert(string s)
{
	int p=0;
	for (int i=0;i<s.size();i++)
	{
		if (!t[p][s[i]-'a'])
		{
			t[p][s[i]-'a']=++cnt;
			a[cnt]=0;
			memset(t[cnt],0,sizeof(t[cnt]));
		}
		p=t[p][s[i]-'a'];
		a[p]++;
		for (auto j:fac[a[p]])
		{
			ans^=f[j]*j;
			f[j]++;
			ans^=f[j]*j;
		}
	}
}
void solve()
{
	memset(t[0],0,sizeof(t[0]));
	cin>>n;
	for (int i=1;i<=n;i++)cin>>st[i],f[i]=0;
	ans=cnt=0;
	for (int i=1;i<=n;i++)
	{
		insert(st[i]);
		if (i==n)cout<<ans<<'\n';
		else cout<<ans<<' ';
	}
}
int main()
{
	for (int i=1;i<=M-5;i++)
	{
		for (int j=i;j<=M-5;j+=i)
			fac[j].push_back(i);
	}
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
