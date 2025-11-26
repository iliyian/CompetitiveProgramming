#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
ll n,a[N],s,s1;
bool cmp(int x,int y)
{
  return x>y;
}
void solve()
{
	s=s1=0;
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i],s+=a[i],s1+=(a[i]!=0);
	if (100-0.5*n<1.0*s&&1.0*s<=100+0.5*s1)
	{
		cout<<"YES"<<endl;
		if (s==100)
		{
			for (int i=1;i<=n;i++)cout<<a[i]<<' ';
			cout<<endl;
		}
		else if (s>100)
		{
			int x=(s-100)*2,y=0;
			for (int i=1;i<=n;i++)
			{
				a[i]=a[i]*10;
				if (y<=x&&a[i]>0)
				{
					y++,a[i]-=5;
				}
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
    s=0;
    for (int i=1;i<=n;i++)s+=a[i];
    for (int i = 1; i <= n; i++) {
      std::cerr << (int)round(a[i] * 100.0 / s) << ' ';
    }
    cerr<<endl;
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
