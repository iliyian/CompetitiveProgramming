#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define fst first
#define scd second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
using vi = vector<int>;
using vl = vector<ll>;
const ll INF = 1e18 + 7;
const int N = 1e5 + 7;
const int M = 5e5 + 7;
const int modN = 998244353;
mt19937_64 rng(time(0));

ll fa[N][64];
ll n, m, q, V;
vector<ll> e[N];
struct node{
    ll u, v, w;
} edge[M];
void build(ll p){
    for (int i = 1; i <= m;i++){
        ll u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if(w & p){
            e[u].PB(v);
            e[v].PB(u);
        }
    }
}
ll find(ll x, ll p){
    if(x == fa[x][p])
        return x;
    return fa[x][p] = find(fa[x][p], p);
}
void add(ll x,ll y,ll p){
    ll fx = find(x, p), fy = find(y, p);
    if(fx != fy)
        fa[fy][p] = fx;
}
void dfs(ll x, ll pre, ll p){
    for(auto v: e[x]){
        if(v == pre)
            continue;
        add(x, v, p);
        dfs(v, x, p);
    }
}
void solve(){
    cin >> n >> m >> q >> V;

    for (int i = 1; i <= m;i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    ll cur = 0;
    for (int j = 59; j >= 0;j--){
        for (int i = 1; i <= n;i++){
            e[i].clear();
            fa[i][j] = i;
        }
        ll cnt = (1ll << j);
        if(cnt & V){
            cur += cnt;
            continue;
        }
        else{
            build(cnt + cur);
            for (int i = 1; i <= n;i++){
                if(i == fa[i][j])
                    dfs(i, i, j);
            }
        }
        
    }
    for (int i = 1; i <= q;i++){
        ll u, v;
        cin >> u >> v;
        bool flag = 0;
        for (int j = 59; j >= 0;j--){
            if(find(u, j) == find(v, j)){
                flag = 1;
                break;
            }
        }
        if(flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}   
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}   