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
//inline int read() {
//	int ret = 0, f = 1; char ch = getchar();
//	while (!isdigit(ch)) { if (ch == '-')f = -f; ch = getchar(); }
//	while (isdigit(ch)) { ret = ret * 10 + ch - '0'; ch = getchar(); }
//	return ret * f;
//}
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
//const int INF = 1e9+7;
const double eps = 1e-8;
const int mod = 1e9;
const int N = 5e3 + 100;
//int a[N];
//int b[N];
//const int p=998244353;
const int maxn = 2e5 + 10;
//int a[300005],b[300005];
//int c[N][2];
//int a[N],h[N];
//
struct Edge
{
	int to, w, next;
}edges[N*4];
int head[N], cnt = 1;
inline void add(int from, int to, int w)
{
	cnt++;
	edges[cnt].w = w;
	edges[cnt].to = to;
	edges[cnt].next = head[from];
	head[from] = cnt;
}
int n, m, l;
int s, t, lv[N], cur[N];
int nxt[N];
inline bool bfs()
{
	memset(lv, -1, sizeof(lv));
	lv[s] = 0;
	memcpy(cur, head, sizeof(head));//当前弧优化初始化 
	queue<int>q;
	q.push(s);
	while (!q.empty())
	{
		int p = q.front();
		q.pop();
		for (int eg = head[p]; eg; eg = edges[eg].next)
		{
			int to = edges[eg].to;
			int vol = edges[eg].w;
			if (vol > 0 && lv[to] == -1)
			{
				lv[to] = lv[p] + 1;
				q.push(to);
			}
		}
	}
	return lv[t] != -1;//汇点未访问过说明无法到达汇点，返回0 
}
int dfs(int p = s, int flow = INF)
{
	if (p == t)return flow;
	int rmn = flow;
	for (int eg = cur[p]; eg && rmn; eg = edges[eg].next)
	{
		cur[p] = eg;//当前弧优化，更新当前弧
		int to = edges[eg].to;
		int vol = edges[eg].w;
		if (vol > 0 && lv[to] == lv[p] + 1)//往层数高的方向增广 
		{
			int c = dfs(to, min(vol, rmn));//尽可能多地传递 
			rmn -= c;// 剩余流量减少
			edges[eg].w -= c;// 更新残余容量
			edges[eg ^ 1].w += c;
			if (c)//只有增广成功才修改nxt
			{
				nxt[p] = to - N;
				//如果选择用x+n记录从点x拆出的点，这里就这样写，记录下一个点
			}
		}
	}
	return flow - rmn;
}
inline int dinic()
{
	int ans = 0;
	while (bfs())
	{
		ans += dfs();
	}
	return ans;
}
int cul(int x, int y, int z)
{
	return((x - 1) * m + y + (z - 1) * n * m);
}
void solve()
{
	cin >> n >> m >> l;
	s = 0; t = n * m * l + 1;
	//s=cul(1,1,1);t=cul(n,m,l);
	vector<vector<vector<int>>>a(l + 5, vector<vector<int>>(n + 5, vector<int>(m + 5)));
	vector<vector<string>>ss(l + 5, vector<string>(n + 5));
	for (int k = 1; k <= l; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> ss[k][i];
			ss[k][i] = ' ' + ss[k][i];
		}
	}
//	for (int k = 1; k <= l; k++)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= m; j++)
//			{
//				/*int qq; qq = read();
//				a[k][i][j]=qq;*/
//				cin >> a[k][i][j];
//			}
//		}
//	}
	for (int k = 1; k <= l; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> a[k][i][j];
				int x = cul(i, j, k);
				if (ss[k][i][j] == 'B')
				{
					add(x, t, a[k][i][j]);
					add(t, x, 0);
				}
				else if (ss[k][i][j] == 'W')
				{
					add(s, x, a[k][i][j]);
					add(x, s, 0);
				}
				int x1 = i - 1, y1 = j - 1, z1 = k - 1;
				if (x1 >= 1 && x1 <= n)
				{
					int y = cul(x1, j, k);
					add(x, y, INF);
					add(y, x, 0);
				}
				if (y1 >= 1 && y1 <= m)
				{
					int y = cul(i, y1, k);
					add(x, y, INF);
					add(y, x, 0);
				}
				if (z1 >= 1 && z1 <= l)
				{
					int y = cul(i, j, z1);
					add(x, y, INF);
					add(y, x, 0);
				}
			}
		}
	}
	int xx = cul(1, 1, 1), yy = cul(n, m, l);
	add(s, yy, INF);
	add(yy, s, 0);
	add(xx, t, INF);
	add(t, xx, 0);
	int an = dinic();
	cout << an << endl;
	return;
}
signed main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int _; _ = 1;
	//cin >> _;//scanf("%d",&_);
	while (_--)solve();
	return 0;
}
