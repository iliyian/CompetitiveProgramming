#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
ll n,a[N],s[N],ans[N];
struct node{
	int id,len;
}b[N];
int cnt;
bool cmp(node x,node y)
{
	if (x.len==y.len)return x.id<y.id;
	return x.len<y.len;
}
void solve()
{
	cnt=0;
	cin>>n;
	s[0]=0;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for (int i=3;i<=n;i++)
	{
		int l=3,r=i,c=-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if (a[i]<s[i-1]-s[i-mid])
			{
				c=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
//		cout<<a[3]<<'!'<<s[2]<<' '<<s[0]<<endl;
		if (c!=-1)b[++cnt]={i,c};
	}
	sort(b+1,b+cnt+1,cmp);
	for (int i=1,j=1,maxn=-1;i<=n;i++)
	{
		while(j<=cnt&&b[j].len<=i)maxn=max(maxn,b[j].id),j++;
		if (maxn==-1||maxn<i)ans[i]=0;
		else ans[i]=s[maxn]-s[maxn-i];
	}
	for (int i=1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<endl;
}
int main()
{
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
