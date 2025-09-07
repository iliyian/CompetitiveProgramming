#include<bits/stdc++.h>
#define ll long long
#define N 100005 
using namespace std;
ll n,a[N],ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i];
    
    for (int k=0;k<=30;k++)
    {
        ll mask=(1<<(k+1))-1;
        ll c00=0,c01=0,c10=0,c11=0;
        for (int i=1;i<=n;i++)
        {
            ll x=a[i]&mask;
            int pc=__builtin_popcount(static_cast<unsigned int>(x));
            if ((x>>k)&1)
            {
                if (pc&1)c11++;
                else c10++;
            }
            else {
                if (pc&1)c01++;
                else c00++;
            }
        }
        ans+=(c00*c11+c01*c10)*(1<<k);
    }
    cout<<ans<<endl;
    return 0;
}