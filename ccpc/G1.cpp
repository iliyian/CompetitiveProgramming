#include<bits/stdc++.h>
#define ll long long 
#define N 100005
#define M 320
using namespace std;
int n,m,q,a[N],b[N],cnt=1,len[M],g[M][N],l[M],r[M],d[N],flag[N];
ll ans[N];
pair<int,int> Q[N];
unordered_map<int,int> F[N];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-b-1;
	for (int i=1;i<=q;i++)
	{
		int x,y,X,Y;
		cin>>x>>y;
		X=lower_bound(b+1,b+m+1,x)-b;
		Y=lower_bound(b+1,b+m+1,y)-b;
		if (x!=b[X])X=m+1;
		if (y!=b[Y])Y=m+1;
		Q[i].first=X,Q[i].second=Y;
		if (F[X][Y])flag[i]=F[X][Y];
		else F[X][Y]=i;
	}
	for (int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+m+1,a[i])-b;
//	for (int i=1;i<=n;i++)cout<<a[i]<<' ';
//	cout<<endl;
	int t=sqrt(n);
	l[1]=1;
	for (int i=1;i<=n;i++)
	{
		len[cnt]++;
		g[cnt][a[i]]++;
		if (len[cnt]==t)
		{
			r[cnt]=i;
			cnt++;
			l[cnt]=i+1;
		}
	}
	if (r[cnt]==0)r[cnt]=n;
	for (int i=cnt;i>0;i--)
	{
		for (int j=1;j<=q;j++)
			ans[j]+=g[i][Q[j].first]*d[Q[j].second];
		for (int j=l[i];j<r[i];j++)
		{
			for (int k=j+1;k<=r[i];k++)
			{
				int x=F[a[j]].count(a[k]);
				if (x)x=F[a[j]][a[k]],ans[x]++;
			}
		}
		for (int j=1;j<=m;j++)d[j]+=g[i][j];
	}
	for (int i=1;i<=q;i++)
	{
		if (flag[i])cout<<ans[flag[i]]<<'\n';
		else cout<<ans[i]<<'\n';
	}
	return 0;
}
