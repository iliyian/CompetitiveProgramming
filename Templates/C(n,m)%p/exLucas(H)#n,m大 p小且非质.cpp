#include<bits/stdc++.h>//exLucas#n,m大 p小且非质
//test:https://www.luogu.com.cn/record/129064672
using namespace std;using ll=long long;
struct disolve1e18{
    ll delt;vector<int>pris={2,3,5,7,11,13};
    ll mul(ll a,ll b,ll m){ll res=0;for(;b;(a<<=1)%=m,b>>=1)if(b&1)(res+=a)%=m;return res;}
    ll f(ll x,ll n){return (mul(x,x,n)+delt)%n;}//随机性能优异
    ll _gcd(ll a,ll b){if(a<b)swap(a,b);while(b)a%=b,swap(a,b);return a;}
    ll powm(ll bs,ll x,ll m){ll res=1;for(;x;x>>=1,bs=mul(bs,bs,m))if(x&1)res=mul(res,bs,m);return res;}   
    bool miller_rabbin(ll n){//is pri->true
        for(auto k:pris)if(n%k==0)return (n==k);ll b=n-1;int cnt=0;while(!(b&1))cnt++,b>>=1;
        for(auto k:pris){ll val=powm(k,b,n);for(int j=0;j<cnt;j++)
            {ll v2=mul(val,val,n);if(v2==1&&val!=1&&val!=n-1)return 0;val=v2;}if(val!=1)return 0;}return 1;}
    int find_factorplus(ll n){//“floyd判圈”算法 
        for(ll a=2,b=f(a,n);a!=b;a=f(a,n),b=f(f(b,n),n)){ll p=_gcd(abs(b-a),n);if(p>1)return p;}return 0;}
    vector<ll> disolve(ll _n){
        ll n,n2;n=_n;n2=n;vector<ll>facs;if(n==1)return facs;queue<ll>fds;fds.push(n);
        for(ll x;!fds.empty();fds.pop()){ x=fds.front();if(x==1)continue; while(!miller_rabbin(x))for(delt=2;;delt++)
            {ll fac=find_factorplus(x);if(fac){fds.push(fac);x/=fac;break;}}if(x>1)facs.push_back(x);}
        sort(facs.begin(),facs.end());return facs;}
}mil;
struct Excrt{
    ll _gcd(ll a,ll b){if(a<b)swap(a,b);while(b)a%=b,swap(a,b);return a;}
    ll _lcm(ll a,ll b){return a/_gcd(a,b)*b;}
    ll slowmul(ll a,ll b,ll mod){ 
        ll res=0;a=(a%mod+mod)%mod,b=(b%mod+mod)%mod;
        for(;b;b>>=1,(a<<=1)%=mod)if(b&1)(res+=a)%=mod;return res;}
    void exgcd(ll& a,ll x,ll& b,ll y)//Lemma:abs(a)<=y,abs(b)<=x
    {
        if(y==1){a=0;b=1;return;}//a*(x%y)+a*(x/y)*y+b*y=c*y+d*(x%y)->a*(x/y)+b=c,a=d   
        ll c,d;exgcd(c,y,d,x%y);a=d;b=c-a*(x/y);
    }//abs(c)<=x%y,abs(d)<=y->abs(a)<=y,abs(b)<=x   
    bool exgcdp(ll& a,ll x, ll& b,ll y,ll c)//version which b doesn't matter
    {//ax+by=c if ok return 1/a/b else return 0
        ll g= _gcd(x,y);//now T(x)=y/gcd(x,y)
        if (c%g)return 0;x/=g,y/=g,c/=g;//T(origin x)=now y=(*)T(x)
        x>y?exgcd(a,x,b,y):exgcd(b,y,a,x);//cout<<"x"<<x<<"y"<<y<<"a"<<a<<"b"<<b<<'\n';
        a=slowmul(a,c,y);return 1;/*a*=c;b*=c;will overflow when max(a,b)^2>1e18)*/  
    }
    pair<ll,ll>excrt(pair<ll,ll>pa,pair<ll,ll>pb)
    {//pa={a,c},pb={b,d}|t%a=c,t%b=d->ax%b=d-c,ax+by=d-c,(*)T(x)=b/gcd(a,b)
        //poutp(pa);poutp(pb);
        if(!pa.first||!pb.first)return {0,0};ll x,y;//t=ax+c<=a(*)T(x)+c,
        if(!exgcdp(x,pa.first,y,pb.first,pb.second-pa.second))return {0,0};
        //cout<<"->";poutp({_lcm(pa.first,pb.first),pa.first*x+pa.second});cout<<'\n';
        return {_lcm(pa.first,pb.first),pa.first*x+pa.second};//x modified already
    }
}Exc;
struct exLucas{
    vector<pair<ll,ll> >facs;vector<vector<ll> >mul;ll mod,phi,pk,p;int siz;
    ll poww(ll bs,ll x,ll mod){ll res=1;for(bs%=mod;x;x>>=1,(bs*=bs)%=mod)if(x&1)(res*=bs)%=mod;return res;}
    ll invv(ll bs,ll mod){return poww(bs,phi-1,mod);}
    vector<pair<ll,ll> >era(vector<ll>&v){vector<pair<ll,ll> >v2;
        for(auto k:v){if(v2.empty()||v2.back().first!=k)
            v2.push_back({k,k});else v2.back().second*=k;}return v2;}
    void precal(ll _mod){
        mod=_mod;vector<ll>f2=mil.disolve(mod);facs=era(f2);siz=facs.size();
        phi=mod;for(auto k:facs)phi=phi/k.first*(k.first-1);
        vector<ll>bas(siz+1,0);bas[0]=1;mul.resize(siz);
        for(int e=0;e<siz;e++){
            ll pk=facs[e].second,p=facs[e].first;mul[e].resize(pk+1);mul[e][0]=1;
            for(int i=1;i<pk;i++)mul[e][i]=(i%p)?mul[e][i-1]*i%pk:mul[e][i-1];}}
    pair<ll,ll>fac(ll n,int pos){
        if(!n)return {1,0};pair<ll,ll>r2=fac(n/p,pos);ll b=n/p+r2.second;
        ll a=poww(mul[pos][pk-1],n/pk,pk)*mul[pos][n%pk]%pk*r2.first%pk;return {a,b};}
    ll C(ll n,ll m){
        if(n<m)return 0;pair<ll,ll>ans={1,0};for(int i=0;i<siz;i++){
            p=facs[i].first;pk=facs[i].second;pair<ll,ll>a=fac(n,i),b=fac(m,i),c=fac(n-m,i);
            ll val=a.first*invv(b.first,pk)%pk*invv(c.first,pk)%pk,cnt=a.second-b.second-c.second;
            (val*=poww(p,cnt,pk))%=pk;ans=Exc.excrt(ans,{pk,val});
        }return ans.second;}
}exL;
void solve(){ll n,m,p;cin>>n>>m>>p;exL.precal(p);cout<<exL.C(n,m)<<'\n';}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t=1;while(t--)solve();//cin>>t;**/
}
