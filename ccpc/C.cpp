#include<bits/stdc++.h>
#define ll long long 
#define N 100005
using namespace std;
int n,k,a[N],ans=0;
void solve()
{
	ans=0;
	cin>>n>>k;
	for (int i=1;i<=n;i++)cin>>a[i],a[i]%=k;
	multiset<int> s;
	for (int i=2;i<=n;i++)s.insert(a[i]);
	priority_queue<pair<int,int> > q;
	q.push({0,a[1]});
	auto nxt = [&](int x) {
		auto p = s.lower_bound(x);
		if (p == s.end()) return -1;
		return *p;
	};
	auto prv = [&](int x) {
		int y = s.count(x);
		if (y > 1) {
			return x;
		}
		auto p = s.lower_bound(x);
		if (p == s.begin()) {
			return -1;
		}
		return *(--p);
	};
	auto find = [&](int x) {
		int u=prv(x),v=nxt(x);
		if (u==-1&&v==-1)
		{
			cout<<ans<<endl;
			return;
		}
		int z=INT_MAX,Z;
		if (u!=-1)
		{
			if ((x+u)%k<z)z=(x+u)%k,Z=u;
		}
		if (v!=-1)
		{
			if ((x+v)%k<z)z=(x+v)%k,Z=v;
		}
		return {z,Z};
	};
	while(!q.empty())
	{
//		cout<<'!'<<q.top().first<<' ';
		int x=q.top().second,X=q.top().first;
		q.pop();
		if (X!=0)
		{
			s.erase(x);
			ans+=X;
		}
		int y=k-x;
		cout<<x<<' '<<y<<endl;
		while(nxt(y)==y)
		{
//			cout<<"!"<<y<<endl;
			s.erase(y),q.push({0,y});
		}
		while(1)
		{
			int u=prv(y),v=nxt(y);
			if (u==-1&&v==-1)
			{
				cout<<ans<<endl;
				return;
			}
			int z=INT_MAX,Z;
			if (u!=-1)
			{
				if ((x+u)%k<z)z=(x+u)%k,Z=u;
			}
			if (v!=-1)
			{
				if ((x+v)%k<z)z=(x+v)%k,Z=v;
			}
//			cout<<z<<' '<<q.top().first<<endl;
			if (z< - q.top().first)
			{
//				cout<<"?"<<x<<' '<<Z<<' '<<z<<endl;
				ans+=z;	
				s.erase(Z);
				q.push({0,Z});
				break;
			}
			else {
				q.push({-z,x});
				break;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
