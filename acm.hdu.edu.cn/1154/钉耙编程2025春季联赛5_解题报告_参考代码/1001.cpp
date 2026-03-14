#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mo=1e9+7;
int T,n,m,v,x,f[405][405],ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while (T--){
		cin>>n>>m>>v; 
		ans=0;
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for (int i=1;i<=n;i++)
		{
			cin>>x;
			for (int j=x;j<=v;j++)
			  for (int k=m;k>=1;k--) 
			    f[j][k]=(f[j][k]+f[j-x][k-1]) % mo;
		}
		for (int i=1;i<=v;i++)
		  ans=(ans+f[i][m]) % mo;
		cout<<ans<<'\n';
	}
    return 0;
}
