#include<bits/stdc++.h>
using namespace std;using ll=long long;
struct S
{
	int n;
	void solve()
	{
		cin>>n;vector<ll>v{0};ll res=0;
		for(int i=1;i<=n;i++)
		{
			ll x,y,c=0;cin>>x;y=x;
			while(1)
			{
				int p=upper_bound(v.begin(),v.end(),y)-v.begin()-1;
				//在单调栈上二分最后一个单价≤剩余钱数的店铺,即查找下一个买糖的店铺
				if(!p)break;c+=y/v[p],y%=v[p];
			}
			res=max(res,c);
			while(v.back()>=x)v.pop_back();v.push_back(x);
			//从每点开始只需要关注往前的单调栈,不在单调栈上的店铺无法买糖
		}
		cout<<res<<'\n';
	}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t=1;//cin>>t;
	while(t--){S SS;SS.solve();}
}