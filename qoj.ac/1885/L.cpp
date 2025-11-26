#include<bits/stdc++.h>
#define N 301
using namespace std;
int n,m,cnt;
string ans[1000];
bool a[N][N],b[N][N];
int find(int i,bool flag)
{
	if (i==n)return m;
	for (int j=m;j>=1;j--)
		if (b[i][j]==flag)return j;
	return 0;
}
bool check(bool flag)
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (b[i][j]==flag)return 0;
	return 1;
}
void print()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			cout<<b[i][j]<<' ';
		cout<<'\n';
	}
	cout<<'\n';
}
bool work(bool flag)
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			b[i][j]=a[i][j];
	cnt=0;
//	cout<<"!"<<flag<<'\n';
//	print();
//	cout<<check(flag)<<'\n';
	if (check(flag))return 1;
	for (cnt=1;cnt<=400;cnt++)
	{
		ans[cnt]="";
		int x=1,y=1;
		b[x][y]=!b[x][y];
		while(1)
		{
			if (x==n&&y==m)break;
			int c=find(x,flag);
			if (c<=y)x++,ans[cnt]+='D',b[x][y]=!b[x][y];
			else {
				while(y<c)
				{
					y++;
					ans[cnt]+='R';
					b[x][y]=!b[x][y];
				}
			}
		}
//		print();
		if (check(flag))return 1;
	}
	return 0;
}
void solve()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			char ch;
			cin>>ch;
			if (ch=='W')a[i][j]=1;
			else a[i][j]=0;
		}
	}
	if (a[1][1]!=a[n][m])cout<<"NO"<<'\n';
	else if (work(1))
	{
		cout<<"YES"<<'\n'<<cnt<<'\n';
		for (int i=1;i<=cnt;i++)cout<<ans[i]<<'\n';
	}
	else if (work(0))
	{
		cout<<"YES"<<'\n'<<cnt<<'\n';
		for (int i=1;i<=cnt;i++)cout<<ans[i]<<'\n';
	}
	else cout<<"NO"<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
}
