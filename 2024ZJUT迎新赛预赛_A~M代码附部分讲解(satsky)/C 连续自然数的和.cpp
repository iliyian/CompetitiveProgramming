#include<bits/stdc++.h>
using namespace std;using ll=long long;using pii=pair<int,int>;
const int M=998244353,Lim=5e4;const ll inf=1e17;
struct S
{
	int n;
	void ini()
	{
		cin>>n;vector<vector<int>>res;
		//取[l,r],则有(l+r)*(r-l+1)=n*2
		//设(r-l+1)=x,y=l+r=n*2/x,有b=(y+x-1)/2,a=(y-x+1)/2
		//枚举x,判断是否:(y=n*2/x为正整数 & x<y & x,y奇偶性一致)即可
		//x<y,因此x只需枚举到sqrt(n);显然l随x递增而递减
		for(int x=2;x<=Lim;x++)if(n*2%x==0)
		{
			int y=n*2/x;if((y-x+1)%2)continue;
			int b=(y+x-1)/2,a=(y-x+1)/2;if(a<1)continue;
			vector<int>v;for(int i=a;i<=b;i++)v.push_back(i);res.push_back(v);
		}
		cout<<res.size()<<'\n';
		for(auto&k:res) { for(auto&kk:k)cout<<kk<<' ';cout<<'\n'; }
	}
	void solve()
	{

	}
};
void precal() {}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);precal();
	int t=1;//cin>>t;
	while(t--) { S SS;SS.ini();SS.solve(); }
}