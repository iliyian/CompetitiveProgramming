#include<bits/stdc++.h>
#define ll long long
#define double long double
#define N 300005
#define eps 1e-18l
using namespace std;
ll n,k,a[N];
double check(double x)
{
	double s=0;
	for (int i=1;i<=n;i++)s+=(x*a[i])/(x*a[i]+1);
	return s;
}

int main()
{
	freopen("M.in","w",stdout);
	ios::sync_with_stdio(false);
	n=100000;
	cout<<n<<' '<<99999<<endl;
	for (int i=1;i<n;i++)cout<<1<<' ';
	cout<<1000000000<<endl;
	return 0;
}

