#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
int n,m;
void print(vector<vector<int>> &a)
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
//	cout<<endl;
}
void solve()
{
	cin>>n>>m;
	if (__gcd(n,m)!=1)
	{
		printf("NO\n");
		return ;
	}
	printf("YES\n");
	int x=0,y=0,f=0,f1=1;
	vector<vector<int>>a(n+1,vector<int>(m + 1));
	for (int i=1;i<=n*m;i++)
	{
		a[x][y]=i;
//		print(a);
		if (i%m==0)
		{
			f=0;
			if (f1)
			{
				x=(x+i)%n;
			}
			else x=(x-i+n*m)%n;
			a[x][y]=i;
			a[x][y]=i;
			f1=f1^1;
		}
		else {
			if (f==0)
			{
				y=(y+i)%m;
				a[x][y]=i;
			}
			else {
				y=(y-i+n*m)%m;
				a[x][y]=i;
			}
			f=(f+1)%2;
		}
	}
	print(a);
	
}
int main()
{
	ios::sync_with_stdio(false);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
