#include<iostream>
#include<cstdio>
using namespace std;
const int mod=100003;
int n,k,a[1000000],ans=0;
int main()
{
	cin>>n>>k;
	a[0]=a[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(i<=k)
		{
			a[i]=(a[i-1]*2)%mod;
		}
		else 
		{
			a[i]=(a[i-1]*2-a[i-k-1])%mod;
		}
	}
	ans=(a[n]+mod)%mod;
    cout<<ans;
    return 0;
}