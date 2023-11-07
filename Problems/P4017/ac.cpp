#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int MAXN=1000005,mod=1000000007;
ll f[MAXN],inv[MAXN],d[MAXN];
int t;

ll qpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=a*ans%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}

void prework(){
    f[0]=1;
    for(int i=1;i<MAXN;i++){
        f[i]=f[i-1]*i%mod;
        inv[i]=qpow(f[i],mod-2);
    }
    d[1]=0,d[2]=1,d[3]=2;
    for(int i=4;i<MAXN;i++){
        d[i]=(i-1)*(d[i-1]+d[i-2])%mod;
    }
}

int main(){
  freopen("data.in", "r", stdin);
    cin>>t;
    prework();
    for(int i=1;i<=t;i++){
        ll n,m;
        scanf("%lld%lld",&n,&m);
        if (n - m == 1) printf("0\n");
        else if (m == n) printf("1\n");
        else if (m == 0) printf("%lld\n",d[n]);
        else {
            printf("%lld\n",f[n] * inv[m] % mod * inv[n-m] % mod * d[n-m] % mod);
        }
    }
    return 0;
}