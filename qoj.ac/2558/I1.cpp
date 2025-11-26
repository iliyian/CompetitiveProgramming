#include<bits/stdc++.h>
#define N 2005
#define ll long long
using namespace std;
int n,a[N][N],m=0;
vector<int> adj[N];
bool d[N][N];
vector<pair<int,int>> b;
int main()
{
	cin>>n;
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=1;j<=n;j++)
//			cout<<d[i][j]<<' ';
//		cout<<endl;
//	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			cin>>a[i][j];
			if (i!=j&&a[i][j]==(i^j))d[i][j]=1,d[j][i]=1,m++;
			if (i!=j&&a[i][j]==i)b.push_back({i,j});
			if (i!=j&&a[i][j]==j)b.push_back({j,i});
		}
	}
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=1;j<=n;j++)
//			cout<<d[i][j]<<' ';
//		cout<<endl;
//	}
	for (auto [x,y]:b)
	{
		for (int i=1;i<=n;i++)
		{
			if (d[x][i]&&d[y][i])
			{
				d[x][i]=d[i][x]=0;
				m--;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		if (d[i][j])cout<<i<<' '<<j<<endl;
	}
	return 0;
}
