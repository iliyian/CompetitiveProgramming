#include<bits/stdc++.h>
using namespace std;using ull=unsigned long long;
ull sd=6;
ull gen(ull L,ull R)
{
	sd=(sd<<6)+(sd>>4)+(sd<<10)+sd*sd+34834;
	return sd%(R-L+1)+L;
}
struct S
{
	int n;map<int,ull>mp;set<ull>xS;
	void solve()//std
	{
		cin>>n;
		for(int i=1,l,r;i<=n;i++)
		{
			cin>>l>>r;ull val=gen(1e5,1e17);
			mp[l]^=val,mp[r+1]^=val;
		}
		ull x=0;xS.insert(0);
		for(auto&k:mp)x^=k.second,xS.insert(x);		
		cout<<xS.size()<<'\n';
	}
};
int main(){ios::sync_with_stdio(0);cin.tie(0);S SS;SS.solve();}