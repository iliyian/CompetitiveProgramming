#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

long long mod_pow(long long a,long long e=MOD-2){
    long long r=1;
    while(e){
        if(e&1) r=r*a%MOD;
        a=a*a%MOD;
        e>>=1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;

    vector<long long> fac(n+1), ifac(n+1);
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
    ifac[n]=mod_pow(fac[n]);
    for(int i=n;i>0;i--) ifac[i-1]=ifac[i]*i%MOD;

    auto C = [&](int a,int b)->long long{
        if(b<0 || b>a) return 0LL;
        return fac[a]*ifac[b]%MOD*ifac[a-b]%MOD;
    };

    long long inv3 = mod_pow(3);
    long long inv12 = mod_pow(12);

    // 计算 S_d
    vector<long long> Sd(n,0);
    for(int d=0; d<=n-1; ++d){
        long long x = n - d;                     // N
        long long term = x % MOD * ((x+1)%MOD) % MOD;
        long long inner = ( ( (x%MOD) * (x%MOD) %MOD + x ) %MOD - 2 + MOD ) %MOD;
        term = term * inner % MOD;
        term = term * inv12 % MOD;
        Sd[d]=term;
    }

    long long ans = 0;

    // k = 1
    if(n>=1){
        long long tmp = 1LL * n %MOD * (n+1) %MOD * (n-1) %MOD;
        tmp = tmp * inv3 % MOD;
        long long C1 = fac[n-1] * tmp % MOD;
        ans = (ans + C1) % MOD;
    }

    // k = 2
    if(n>=2){
        long long T2 = Sd[0];                     // S_0
        long long C2 = 2LL * fac[n-2] % MOD;      // (k-1)! = 1!
        C2 = C2 * T2 % MOD;
        ans = (ans + C2) % MOD;
    }

    // k >= 3
    for(int k=3; k<=n; ++k){
        long long sum = 0;
        for(int d=k-2; d<=n-1; ++d){
            long long add = C(d-1, k-3) * Sd[d] % MOD;
            sum += add;
            if(sum>=MOD) sum-=MOD;
        }
        long long Ck = 1LL * k %MOD * fac[n-k] %MOD * fac[k-1] %MOD;
        Ck = Ck * sum % MOD;
        ans = (ans + Ck) % MOD;
    }

    // mex = n+1
    long long last = 1LL * (n+1) % MOD * fac[n] % MOD;
    ans = (ans + last) % MOD;

    cout << ans << '\n';
    return 0;
}