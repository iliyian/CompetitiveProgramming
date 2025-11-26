#include<bits/stdc++.h>
#define N 300005
using namespace std;
int n,m;
struct node{
	int l,r;
}a[N];
bool cmp(node x,node y)
{
	if (x.l==y.l)return x.r<y.r;
	return x.l<y.l;
}
void solve()
{
	cin>>m>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].l>>a[i].r;
//		b[++cnt]=a[i].l,b[++cnt]=a[i].r;
	}
	sort(a+1,a+n+1,cmp);
	
}
int main()
{
	ios::sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
