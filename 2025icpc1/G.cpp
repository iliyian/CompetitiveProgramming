#include<bits/stdc++.h>
#define N 300005
using namespace std;
int n,m,hx[N];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if (x+1==y)hx[x]=1;
	}
	bool flag=1;
	for (int i=1;i<n;i++)
	{
		if (hx[i]==0)flag=0;
	}
	if (flag)puts("Yes");
	else puts("No");
	return 0;
}
