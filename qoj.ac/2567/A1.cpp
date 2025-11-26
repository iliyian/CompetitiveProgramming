#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
ll n,a[N],s;
void solve()
{
	s=0;
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i],s+=a[i];
	if (100-0.5*n<1.0*s&&1.0*s<=100+0.5*n)
	{
		cout<<"YES"<<endl;
		if (s==100)
		{
			for (int i=1;i<=n;i++)cout<<a[i]<<' ';
			cout<<endl;
		}
		else if (s>100)
		{
			int x=(s-100)*2;
			for (int i=1;i<=n;i++)
			{
				a[i]=a[i]*10;
				if (i<=x)a[i]+=5;
			}
			for (int i=1;i<=n;i++)cout<<a[i]<<' ';
			cout<<endl;
		}
		else if (s<100)
		{
			int x=(100-s)*2;
			for (int i=1;i<=n;i++)
			{
				a[i]=a[i]*10000000;
				if (i<=x)a[i]+=4999999;
				if (i==x+1)a[i]+=1*x;
			}
			for (int i=1;i<=n;i++)cout<<a[i]<<' ';
			cout<<endl;
		}
	}
	else cout<<"NO"<<endl;
}
int main()
{
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
