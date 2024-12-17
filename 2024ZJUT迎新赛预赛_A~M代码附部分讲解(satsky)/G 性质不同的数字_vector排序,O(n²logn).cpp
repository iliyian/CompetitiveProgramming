#include<bits/stdc++.h>
using namespace std;
struct S
{
	int n,res=1;map<int,vector<int>>mp;set<vector<int>>xS;vector<int>a;
	//本质上是O(n³)做法的优化版本
	void solve()
	{
		cin>>n;a.resize(n,0);xS.insert(a);
		for(int i=0,l,r;i<n;i++)cin>>l>>r,mp[l].push_back(i),mp[r+1].push_back(i);		
		for(auto&k:mp){for(auto&x:k.second)a[x]^=1;xS.insert(a);}
		cout<<xS.size()<<'\n';
	}
};
int main(){ios::sync_with_stdio(0);cin.tie(0);S SS;SS.solve();}