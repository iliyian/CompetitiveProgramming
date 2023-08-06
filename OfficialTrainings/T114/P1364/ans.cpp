#include <cstdio>
#include <bits/stdc++.h>
#define rep(i, m, n) for(register int i = m; i <= n; ++i)
#define INF 2147483647
#define Open(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define Close fclose(stdin);fclose(stdout);
using namespace std;
inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') { s = s * 10 + ch - '0'; ch = getchar(); }
	return s * w;
}
const int MAXN = 10010;
struct Edge{
	int next, to;
}e[MAXN << 1];
int head[MAXN], num, w[MAXN], n, sz[MAXN];
long long ans = INF, f[MAXN];
inline void Add(int from, int to){
	e[++num].to = to;
	e[num].next = head[from];
	head[from] = num;
}
void dfs(int u, int fa, int dep){ //预处理f[1]和sz
    sz[u] = w[u];
	for(int i = head[u]; i; i = e[i].next){
	   if(e[i].to != fa)
	     dfs(e[i].to, u, dep + 1), sz[u] += sz[e[i].to];
	}
	f[1] += w[u] * dep;
}
void dp(int u, int fa){  //转移
    for(int i = head[u]; i; i = e[i].next)
       if(e[i].to != fa)
         f[e[i].to] = f[u] + sz[1] - sz[e[i].to] * 2, dp(e[i].to, u);
    ans = min(ans, f[u]); //取最小值
}
int a, b;
int main(){
    Open("data");
    ans *= ans;
    n = read();
    rep(i, 1, n){
       w[i] = read();
       a = read(); b = read();
       if(a) Add(i, a), Add(a, i);
       if(b) Add(i, b), Add(b, i);
    }
    dfs(1, 0, 0);
    dp(1, 0);
    printf("%lld\n", ans);
    //Close;
    return 0;
}

