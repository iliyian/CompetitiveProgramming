#include<bits/stdc++.h>
#define ll long long
#define N 300005
using namespace std;
ll n,m,X,Y,ans1,ans2,ans;
deque<pair<int,int> >a,b; 
ll check(ll x,ll R,deque<pair<int,int> > &c)
{
	ll L=0,s=0;
	while(1)
	{
		if ((L+R)%2!=0)return -1;
		s++;
		c.push_back({L,R});
		ll mid=(L+R)/2;
		if (mid==x)return s;
		else if (mid<x)L=mid;
		else R=mid;
	}
}
int main()
{
	cin>>n>>m>>X>>Y;
	if (X==0||X==n)ans1=0,a.push_back({X,X});
	else ans1=check(X,n,a);
	if (Y==0||Y==m)ans2=0,b.push_back({Y,Y});
	else ans2=check(Y,m,b);
	
	if (ans1==-1||ans2==-1){
		cout<<-1<<endl;
	}
	else {
//		cout<<ans1<<' '<<ans2<<endl;
		if (ans1>ans2)
		{
			for (int i=ans2;i<ans1;i++)
				b.push_front({0,0});
		}
		else {
			for (int i=ans1;i<ans2;i++)
				a.push_front({0,0});
		}
		ans=max(ans1,ans2);
		cout<<ans<<endl;
		for (int i=0;i<ans;i++)
		{
			cout<<a[i].first<<' '<<b[i].first<<' '<<a[i].second<<' '<<b[i].second<<endl;
		}
	}
	return 0;
}
