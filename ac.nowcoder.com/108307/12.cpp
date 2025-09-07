#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
int n,m,hx[N],a[N],b[N],c[N],tot,ans=0;
bool cmp(int x,int y)
{
	if (hx[x]==hx[y])return x<y;
	return hx[x]>hx[y];
}
void solve()
{
	tot=ans=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)hx[i]=0;
	for (int i=1;i<=m;i++)
	{
		cin>>a[i],hx[a[i]]++,b[i]=a[i];
		if (hx[a[i]]==1)c[++tot]=a[i];
	}
	sort(b+1,b+m+1);
	int cnt=unique(b+1,b+m+1)-b-1;
	sort(b+1,b+cnt+1,cmp);
	for (int i=1;i<=cnt;i++)
	{
		if (b[i]!=c[i])ans++;
	}
	cout<<ans<<'\n';
}
int main()
{
	cin.tie(0)->ios::sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
