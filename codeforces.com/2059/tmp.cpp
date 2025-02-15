#include<bits/stdc++.h>
//#define int __int128
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<string>
#include<queue>
//#define lson (o << 1)
//#define rson (o << 1 | 1)
//#define mt ((l+r)/2)
#define lowbit(x) x & -x
#define endl '\n'
#define int long long
#define PII pair<int,int>
using namespace std;
using ll = long long;//using ll =__int128;
//mt19937_64 rnd(time(0));
//const int q=1e9+7;
inline int read()
{
	int k = 0, f = 1; char c = getchar(); while (c < '0' || c>'9') { if (c == '-')f = -1; c = getchar(); }
	while (c >= '0' && c <= '9')k = k * 10 + c - '0', c = getchar(); return k * f;//getchar_unlocked()
}
//template<typename T> inline void print(T x) { if (x > 9)  print(x / 10); putchar(x % 10 + '0'); }
//template<typename T> inline void Pr(T x, char c = '\n') { if (x < 0) putchar('-'), x = -x; print(x); putchar(c); }
//inline void write(int x) { if (x < 0)putchar('-'), x = -x; if (x > 9) write(x / 10); putchar(x % 10 + '0'); }
//int exgcd(int a, int b, int& x, int& y) { if (b == 0) { x = 1; y = 0; return a; }int d = exgcd(b, a % b, y, x); y -= (a / b) * x; return d; }
//inline ll inv(ll a, ll p) { ll x, y; exgcd(a, p, x, y); return(x % p + p) % p; }
////template<typename T>T qpow(T a, ll n){T ans = 1; while (n){if (n & 1)ans = ans * a; n >>= 1;a = a * a;}return ans;}
//inline ll crt(ll a[], ll b[], ll n)//a是模数数组,b是余数数组,n是数组长度 x==b(mod a)
//{
//	ll p = 1, x = 0; for (int i = 1; i <= n; i++)p *= a[i]; for (int i = 1; i <= n; i++) { ll r = p / a[i]; x += (b[i] * r * inv(r, a[i])) % p; }return x % p;
//}
//int lcm(int a,int b){return a*b/__gcd(a,b);}
//inline ll C(ll m,ll n,ll p){return m<n?0:fact[m]*inv(fact[n],p)%p*inv(fact[m-n],p)%p;}//int fact[N];
//inline ll lucas(ll m,ll n,ll p){return n==0?1%p:lucas(m/p,n/p,p)*C(m%p,n%p,p)%p;}
//const int Mod = 1e9 + 7;
//priority_queue<int, vector<int>, greater<int> > q1;//小根堆
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f3f3f3f3f;
//const int N=5e5+10;
const double eps = 1e-8;
const int mod = 1e9;
const int N = 5e5 + 10;
//int a[N],b[N];
void solve()
{
	int k,l1,r1,l2,r2;
	cin>>k>>l1>>r1>>l2>>r2;
//	for(int i=l1;i<=r1;i++)
//	{
//		for(int j=l2;j<=r2;j++)
//		{
//			for(int kk=1;kk<=1000;kk*=k)
//			if(j==i*kk)
//			//if(((j/i)==1)||((j/i)%k==0))
//			{
//				cout<<"i: "<<i<<"j: "<<j<<endl;
//			}
//		}
//	}
	int qq=1;
	int cnt=0;
	int lt=l1;
	for(int i=1;;i++)
	{
		if(lt>=l2)break;
		lt=lt*k;
		qq*=k;
	}
	for(int i=1;;i++)
	{
		
		//cout<<"lt: "<<lt<<endl;
		if(lt>=l2&&lt<=r2)
		{
			int tm1=(r2-lt)/qq+1;
			int tm2=(r1-l1+1);
			int tmp=min(tm1,tm2);
			cnt+=tmp;
			cout<<"cnt: "<<cnt<<endl;
		}
		else
		{
			break;
		}
		lt=lt*k;
		qq*=k;
	}
	cout<<cnt<<endl;
	return;
 } 
//stack<int>stk;
//int cnt,cscc;
//int dfsn[N],low[N],instk[N],scc[N];
//vector<int>edges[N],edges2[N];
////int wt[N],newt[N],dp[N];
//void tarjan(int p)
//{
//	low[p]=dfsn[p]=++cnt;
//	instk[p]=1;
//	stk.push(p);//进栈 
//	for(auto q:edges[p])
//	{
//		if(!dfsn[q])//未访问过
//		{
//			tarjan(q);//递归地搜索
//			low[p]=min(low[p],low[q]);
//		}
//		else if(instk[q])//访问过,且q可达p
//		{
//			low[p]=min(low[p],dfsn[q]);
//		}
//	}
//	if(low[p]==dfsn[p])//发现强连通分量的根
//	{
//		int top;
//		cscc++;
//		do
//		{
//			top=stk.top();
//			stk.pop();
//			instk[top]=0;
//			scc[top]=cscc;//记录所属的强连通分量
//			//newt[cscc]+=wt[top];
//		}
//		while(top!=p);//直到弹出p才停止
//	}
//}
//void build(int n)
//{
//	for(int u=1;u<=n;u++)
//	{
//		for(auto v:edges[u])
//		{
//			if(scc[u]!=scc[v])
//			{
//				edges2[scc[u]].push_back(scc[v]);
//			}
//		}
//	}
//}
//void DP()
//{
//	vector<int>order;
//	vector<int>in(cscc+1,0);
//	for(int i=1;i<=cscc;i++)
//	{
//		for(auto j:edges2[i])
//		{
//			in[j]++;
//		}
//	}
//	queue<int>q;
//	for(int i=1;i<=cscc;i++)
//	{
//		if(in[i]==0)q.push(i);
//	}
//	while(!q.empty())
//	{
//		int u=q.front();
//		q.pop();
//		order.push_back(u);
//		for(auto v:edges2[u])
//		{
//			if(--in[v]==0)q.push(v);
//		}
//	}
//	for(int i=order.size()-1;i>=0;i--)
//	{
//		int u=order[i];
//		dp[u]=newt[u];
//		for(auto v:edges2[u])
//		{
//			dp[u]=max(dp[u],dp[v]+newt[u]);
//		}
//	}
//}
//void DP()
//{
//	for(int i=cscc;i>=1;i--)
//	{
//		dp[i]=newt[i];
//		for(auto j:edges2[i])
//		{
//			dp[i]=max(dp[i],dp[j]+newt[i]);
//		}
//	}
//}
//void solve()
//{
//    int n,m;
//    cin>>n>>m;
////    for(int i=1;i<=n;i++)
////    {
////    	cin>>wt[i];
////	}
//	for(int i=1;i<=m;i++)
//	{
//		int u,v;
//		cin>>u>>v;
//		edges[u].push_back(v);
//	}
//	for(int i=1;i<=n;i++)
//	{
//		if(!dfsn[i])
//		{
//			tarjan(i);
//		}
//	}
//	build(n);
////	for(int i=1;i<=cscc;i++)
////	{
////		out[i]=0;
////	}
//
//    vector<int>in(cscc+5,0);
//	for(int i=1;i<=cscc;i++)
//	{
//		for(auto j:edges2[i])
//		{
//			in[j]++;
//		}
//	}
//	int f=-1;
//	int qq=0;
//	for(int i=1;i<=cscc;i++)
//	{
//		if(in[i]==0)
//		{
//			f=i;
//			qq++;
//		}
//	}
//	cout<<qq<<endl;
////	DP();
////	int ans=0;
////	for(int i=1;i<=cscc;i++)
////	{
////		ans=max(ans,dp[i]);
////	}
////	cout<<ans<<endl;
//    return ;
//}
signed main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int _;
	_ = 1;
	cin >> _;//scanf("%d",&_);
	while (_--)solve();
	return 0;
}