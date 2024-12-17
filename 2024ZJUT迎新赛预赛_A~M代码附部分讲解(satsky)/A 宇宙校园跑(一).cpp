#include<bits/stdc++.h>
using namespace std;using ll=long long;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;cin>>n>>m;vector<int>a(m);for(auto&k:a)cin>>k;
	ll res=0;int lst=a.back();for(auto&k:a){int d=abs(k-lst);res+=min(d,n-d);lst=k;}cout<<res<<'\n';
	//注意共走m段,以及答案可能超出int的数据范围
}