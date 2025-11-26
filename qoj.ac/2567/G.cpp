#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
void solve()
{
	cin>>n>>k>>m;
	ll num=n/k-1;
	ll p=num/2;
	ll rest=n-1-p*2;
	if (n==m)cout<<n<<endl;
	else if (rest>=m)cout<<m+1+p<<endl;
	else {
		cout<<m+1+(n-m-1)/2<<endl;	
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
