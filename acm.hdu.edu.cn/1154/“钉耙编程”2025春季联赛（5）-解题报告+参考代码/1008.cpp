#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],n,sum,T,m;
bool flag,f[5000005];
void dfs(int x,int y)
{
	if(flag) return;
	if (!y){
		if (f[sum]){
			flag=true;
		}
		f[sum]=1;
		return;
	}
	if (n-x<y) return;
	dfs(x+1,y);
	sum+=a[x];
	dfs(x+1,y-1);
	sum-=a[x];
}
signed main()
{
	freopen("mvp.in","r",stdin);
	freopen("mvp.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while (T--){
		cin>>n>>m;sum=0;
		for (int i=0;i<n;i++) cin>>a[i];
		if (n>=24)
			cout<<"YES\n";
		else{
			
			memset(f,false,sizeof(f));
			flag=false;
			dfs(0,n/2);
			if (flag) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}
