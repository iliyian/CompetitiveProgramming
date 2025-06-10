#include<bits/stdc++.h>
//#define int __int128
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<string>
#include<queue>
#define PII pair<int,int>
//#define lson (o << 1)
//#define rson (o << 1 | 1)
#define mt ((l+r)/2)
#define lowbit(x) x & -x
#define endl '\n'
#define int long long
//#define map unordered_map
using namespace std;
using ll = long long;//using ll =__int128;
//mt19937_64 rnd(time(0));
inline int read()
{
    int k=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();return k*f;//getchar_unlocked()
}
//template<typename T> inline void print(T x) { if (x > 9)  print(x / 10); putchar(x % 10 + '0'); }
//template<typename T> inline void Pr(T x, char c = '\n') { if (x < 0) putchar('-'), x = -x; print(x); putchar(c); }
//inline void write(int x){if(x<0)putchar('-'),x=-x;if (x > 9) write(x / 10);putchar(x % 10 + '0');}
//int exgcd(int a,int b,int &x,int &y){if(b==0){x=1;y=0;return a;}int d=exgcd(b,a%b,y,x);y-=(a/b)*x;return d;}
//inline ll inv(ll a,ll p){ll x,y;exgcd(a,p,x,y);return(x%p+p)%p;}
//template<typename T>T qpow(T a, ll n){T ans = 1; while (n){if (n & 1)ans = ans * a; n >>= 1;a = a * a;}return ans;}
//inline ll crt(ll a[],ll b[],ll n)//a是模数数组,b是余数数组,n是数组长度 x==b(mod a)
//{ll p=1,x=0;for(int i=1;i<=n;i++)p*=a[i];for(int i=1;i<=n;i++){ll r=p/a[i];x+=(b[i]*r*inv(r,a[i]))%p;}return x%p;}
//int lcm(int a,int b){return a*b/__gcd(a,b);}
//inline ll C(ll m,ll n,ll p){return m<n?0:fact[m]*inv(fact[n],p)%p*inv(fact[m-n],p)%p;}//int fact[N];
//inline ll lucas(ll m,ll n,ll p){return n==0?1%p:lucas(m/p,n/p,p)*C(m%p,n%p,p)%p;}
//const int Mod = 1e9 + 7;
//const int maxn = 2e6+10;
const int INF = 0x3f3f3f3f3f3f3f3f;
const double eps=1e-8; 
const int mod=1e9;
const int N = 2e6+100;
//int a[N];
//int b[N];
//const int p=998244353;
const int maxn = 5e5 + 10;
//int a[300005],b[300005];
//int c[N][2];
//int a[N],b[N];
//int n,k;
//int a[N];

double p0[maxn];
int p1[maxn];
int b[maxn];

int n,m;
inline void solve()
{
	double P;
	cin>>P;
	//n=read();m=read();
	cin>>n>>m;
	int cnt1=0,cnt0=0;
	for(int i=1;i<=n;i++)
	{
		//int x=read();int y=read();
		int x,y;
		cin>>x>>y;
		if(x==0)
		{
			p0[++cnt0]=0.1*y;
		}
		if(x==1)
		{
			p1[++cnt1]=y;
		}
	}
	sort(p0+1,p0+1+cnt0);
	sort(p1+1,p1+1+cnt1);
	reverse(p1+1,p1+1+cnt1);
	p0[0]=1;
	for(int i=1;i<=cnt0;i++)
	{
		p0[i]*=p0[i-1];
	}
	for(int i=1;i<=cnt1;i++)
	{
		p1[i]+=p1[i-1];
	}
	double ans=DBL_MAX;
	for(int i=0;i<=m&&i<=cnt0&&(m-i)<=cnt1;i++)
	{
    std::cerr << "qwq\n";
		ans=min(ans,P*p0[i]-p1[m-i]);
	}
	ans=max(ans,0.0);
	cout<<fixed<<setprecision(2)<<ans<<"\n";
}
signed main()
{
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	int _;
	_=1;
	cin >> _;//scanf("%d",&_);
    while(_--)solve();
    return 0;
}