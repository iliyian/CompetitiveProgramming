#include<bits/stdc++.h>
using namespace std;using ll=long long;const int N=1e6+10;const ll inf=1e17;
template<typename T>struct Fenwick
{
	int n,B;vector<T>a;//for sum
	void init(int n_) { n=n_+1;for(B=1;B*2<=n;B<<=1);a.assign(n+1,T{}); }Fenwick(int n_=0) { init(n_); }
	void add(int x,const T&v) { for(int i=x;i<=n;i+=i&-i)a[i]+=v; }
	T sum(int x) { T ans{};for(int i=x;i;i-=i&-i)ans+=a[i];return ans; }
	T rS(int l,int r) { return sum(r)-sum(l-1); }
	int kth(int k) { int res=0;for(int b=B;b;b>>=1)if(res+b<=n&&a[res+b]<k)k-=a[res+=b];return res+1; }
};
struct S
{
	int n,E=0;ll sum=0,ans=0;vector<int>a,c,cnt,val,pre,lst;vector<ll>dp;
	void ini()
	{
		cin>>n;a.resize(n+1,0),c=cnt=val=pre=lst=a;dp.resize(n+2,-inf);dp[0]=0;
		for(int i=1;i<=n;i++)cin>>a[i],c[i]=i-a[i],sum+=abs(c[i]);
		Fenwick<int>A(n+1);
		for(int i=n,cc=0;i;i--)if(c[i]>0)
		{
			A.add(c[i],1);cc++;
			val[i]=(cc-A.sum(c[i]-1))*2-(n-i+1);
		}
		for(int i=1;i<=n;i++)if(c[i]>0)
		{
			int x=c[i];ll v=dp[x-1]+val[i];
			if(dp[x]>v)continue;dp[x]=v;pre[i]=lst[x-1];lst[x]=i;
			if(ans>dp[x])continue;ans=dp[x],E=i;
		}
		cout<<sum-ans<<'\n';
		vector<int>b(n+1,1);while(E)b[E]=0,E=pre[E];b[0]=0;
		for(int i=1;i<=n;i++)cout<<(b[i]+=b[i-1])<<" \n"[i==n];
	}
	void solve()
	{

	}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t=1;cin>>t;
	while(t--) { S SS;SS.ini();SS.solve(); }
}