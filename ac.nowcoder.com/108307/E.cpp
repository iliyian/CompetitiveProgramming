#include<bits/stdc++.h>
using namespace std;
int n,m,a[500],maxn;
int dp[500][2];
int work(int c,int c1)
{
	for (int i=1;i<=n;i++)dp[i][0]=dp[i][1]=INT_MAX;
	if (a[1]<=c)dp[1][0]=c-a[1],dp[1][1]=c1-a[1];
	else dp[1][0]=INT_MAX,dp[1][1]=c1-a[1];
	int x,y;
	for (int i=2;i<=n;i++)
	{
		if (a[i]<=c)
		{
			if (a[i-1]<=c)
			{
				x=c-a[i],y=c-a[i-1];
				dp[i][0]=min(dp[i][0],dp[i-1][0]+(x>y)*(x-y));
			}
			x=c-a[i],y=c1-a[i-1];
			dp[i][0]=min(dp[i][0],dp[i-1][1]+(x>y)*(x-y));
		}
		if (a[i-1]<=c)
		{
			x=c1-a[i],y=c-a[i-1];
			dp[i][1]=min(dp[i][1],dp[i-1][0]+(x>y)*(x-y));
		}
		x=c1-a[i],y=c1-a[i-1];
		dp[i][1]=min(dp[i][1],dp[i-1][1]+(x>y)*(x-y));
	}
	return min(dp[n][1],dp[n][0]);
}
void solve()
{
	maxn=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i],maxn=max(maxn,a[i]);
	if (m==1)
	{
		cout<<work(maxn,maxn)<<endl;
	}
	else {
		int ans=INT_MAX;
		for (int i=0;i<=maxn;i++)
			for (int j=maxn;j<=200;j++)
				ans=min(ans,work(i,j));
		cout<<ans<<endl;
	}
}
int main()
{
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
