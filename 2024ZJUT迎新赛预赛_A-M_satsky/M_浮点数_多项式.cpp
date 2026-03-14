//什么原理问出题人,我看不懂...
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
const int G=3;
const int P=998244353;
typedef long long ll;

ll qpow(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%P;
        b>>=1;
        a=a*a%P;
    }
    return ans;
}

namespace Poly
{
    int rev[N],lim,d;
    ll wn[N+1],inv[N];

    void init(int n)
    {
        inv[1]=1;
        for(int i=2; i<=n; i++)inv[i]=ll(P-P/i)*inv[P%i]%P;
    }

    struct __Autoinit
    {
        __Autoinit() { init(N-1); }
    } __autoinit;

    void FFTinit(int n)
    {
        int lst=lim;
        wn[0]=lim=1;
        d=0;
        while(lim<n)lim<<=1,++d;
        if(lim==lst)return;
        for(int i=0; i<lim; i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(d-1));
        int g=qpow(G,(P-1)/lim);
        for(int i=1; i<=lim; i++)wn[i]=wn[i-1]*g%P;
    }

    using Poly=vector<ll>;

    void FFT(Poly &a,int fl)
    {
        a.resize(lim);
        for(int i=0; i<lim; i++)
        {
            if(i<rev[i])swap(a[i],a[rev[i]]);
        }
        for(int s=1; s<lim; s<<=1)
        {
            int wnp=lim/s/2;
            for(int i=0; i<lim; i+=s*2)
            {
                for(int j=0; j<s; j++)
                {
                    int x=a[i+j],y=a[i+j+s]*wn[fl==1?wnp*j:lim-wnp*j]%P;
                    a[i+j]=(x+y)%P;
                    a[i+j+s]=(x+P-y)%P;
                }
            }
        }
        if(fl==-1)for(int i=0; i<lim; i++)a[i]=a[i]*inv[lim]%P;
    }

    Poly operator*(Poly a,Poly b)
    {
        if(a.empty()||b.empty())return {};
        int n=a.size(),m=b.size();
        FFTinit(n+m-1);
        FFT(a,1);
        FFT(b,1);
        for(int i=0; i<lim; i++)a[i]=a[i]*b[i]%P;
        FFT(a,-1);
        a.resize(n+m-1);
        return a;
    }
}

using Poly::operator*;
ll fact[N],ifact[N];

void init(int n)
{
    fact[0]=1;
    for(int i=1; i<=n; i++)fact[i]=fact[i-1]*i%P;
    ifact[n]=qpow(fact[n],P-2);
    for(int i=n; i>0; i--)ifact[i-1]=ifact[i]*i%P;
}

ll cal(int a,int b)
{
    if(a<0||b<0||a<b)return 0;
    return fact[a]*ifact[b]%P*ifact[a-b]%P;
}

int n,m,p,q;

vector<int> brtue()
{
    vector<int> f(n+1,0);
    for(int i=1,mul=1; i<=n; i++,mul=1ll*mul*p%P)f[0]=(f[0]+mul)%P;
    f[0]=1ll*f[0]*qpow(qpow(p,n),P-2)%P;
    for(int i=n-1; i>=1; i--) f[i]=(1ll*f[i+1]*p+1ll*q*f[0]+1)%P;
    vector<int> ans(m+1,0);
    ans[0]=f[0];
    for(int i=0; i<m; i++)ans[i+1]=cal(n+i-1,i)*qpow(q,i)%P*qpow(p,n)%P*(n+i)%P;
    for(int i=2; i<=m; i++)ans[i]=(ans[i]+ans[i-1])%P;
    for(int i=1; i<=m; i++)
    {
        for(int j=0; j<=n-1; j++)
        {
            ans[i]=(ans[i]+1ll*cal(i+j-1,j)*qpow(p,j)%P*qpow(q,i)%P*(f[j]+i+j))%P;
        }
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>p;
    init(N-1);
    vector<int> f(n+1,0);
    q=(1-p+P)%P;
    for(int i=1,mul=1; i<=n; i++,mul=1ll*mul*p%P)f[0]=(f[0]+mul)%P;
    f[0]=1ll*f[0]*qpow(qpow(p,n),P-2)%P;
    for(int i=n-1; i>=1; i--) f[i]=(1ll*f[i+1]*p+1ll*q*f[0]+1)%P;
    vector<int> ans(m+1,0);
    ans[0]=f[0];
    for(int i=0; i<m; i++)ans[i+1]=cal(n+i-1,i)*qpow(q,i)%P*qpow(p,n)%P*(n+i)%P;
    for(int i=2; i<=m; i++)ans[i]=(ans[i]+ans[i-1])%P;
    vector<ll> A(n,0),B(n+m,0);
    for(int i=0; i<n+m; i++)B[i]=fact[i];
    for(int i=0; i<n; i++)A[i]=qpow(p,i)*ifact[i]%P;
    reverse(A.begin(),A.end());
    B=A*B;
    for(int i=n-1; i<=n+m-2; i++)
    {
        int m=i-(n-1)+1;
        ans[m]=(ans[m]+1ll*B[i]*qpow(q,m)%P*m%P*ifact[m-1])%P;
    }
    for(int i=0; i<n; i++) A[i]=1ll*qpow(p,i)*ifact[i]%P*(f[i]+i)%P;
    reverse(A.begin(),A.end());
    B.resize(n+m);
    for(int i=0; i<n+m; i++)B[i]=fact[i];
    B=A*B;
    for(int i=n-1; i<=n+m-2; i++)
    {
        int m=i-(n-1)+1;
        ans[m]=(ans[m]+1ll*B[i]*qpow(q,m)%P*ifact[m-1])%P;
    }
    for(int i=0; i<=m; i++)cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}
