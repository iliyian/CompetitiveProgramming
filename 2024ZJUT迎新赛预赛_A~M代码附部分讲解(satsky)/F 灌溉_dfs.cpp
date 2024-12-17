#include<bits/stdc++.h>
using namespace std;const int M=998244353;
struct S
{
	int n,k,res=0;vector<vector<int>>es;vector<int>lit;
	int spr(int x,int lst)//以点1(任取一点)为树根/起点dfs
	{
		int c=0,sum=lit[x];
		for(auto&k:es[x])if(k^lst){int v=spr(k,x);c+=bool(v),sum+=v;}
		res+=(lit[x]||c+(sum!=k)>1);
		//是k个特殊点之一,或被特殊点所夹,都需要计入答案;c+(sum!=k)即有特殊点的方向的个数
		return sum;
	}
	void ini()
	{
		cin>>n>>k;es.resize(n+1);lit.resize(n+1,0);
		for(int i=1,u,v;i<n;i++)cin>>u>>v,es[u].push_back(v),es[v].push_back(u);//建树
		for(int i=1,x;i<=k;i++)cin>>x,lit[x]=1;spr(1,0);cout<<res<<'\n';
	}
	void solve()
	{

	}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	S SS;SS.ini();SS.solve();
}