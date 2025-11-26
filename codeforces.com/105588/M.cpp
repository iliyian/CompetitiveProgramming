#include<bits/stdc++.h>
#define ll long long
#define N 2011
using namespace std;
int a[N][N];
int n,m;
bool check(int x,int y)
{
	if (x>0&&y>0&&x<=n&&y<=m)return 1;
	return 0;
}
void solve()
{
	cin>>n>>m;
	cout<<"Yes"<<endl;
	int x=1,y=1,cnt=1;
	for (int i=1;i<=n*m;i++)
	{
		while(check(x,y)==0)x++,y--;
		a[x][y]=i;
		x++,y--;
		if (x>n||y<=0)x=1,y=++cnt;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			cout<<a[i][j]<<' ';
		cout<<"\n";
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
