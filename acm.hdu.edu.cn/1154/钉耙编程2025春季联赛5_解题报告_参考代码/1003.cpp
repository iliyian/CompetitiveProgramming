#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 131072 * 2 + 10;
const int K = 30;

int n, tim, m;
int dfn[N], sz[N], lg2[N], to_tree_id[N];
vector<int> e[N];
struct Hamel_pre {  
    ll t[K];int p[K]; 
    void init() { 
        memset(t, 0, sizeof(t)); 
        memset(p, 0, sizeof(p)); 
    } 
    void insert(ll x, int pos) { 
        for (int i = K - 1; i >= 0; --i) { 
            if ((x >> i) & 1) { 
                if (!t[i]){
                    t[i] = x;
                    p[i] = pos;
                    return;
                }else
                if (pos > p[i]) { 
                    swap(t[i], x); 
                    swap(p[i], pos);
                } 
                x ^= t[i]; 
            } 
        } 
    } 
}hamel_pre[N << 1];  
struct Hamel_suf {  
    ll t[K];int p[K]; 
    void init() { 
        memset(t, 0, sizeof(t)); 
        memset(p, 0, sizeof(p)); 
    } 
    void insert(ll x, int pos) { 
        for (int i = K - 1; i >= 0; --i) { 
            if ((x >> i) & 1) { 
                if (!t[i]){
                    t[i] = x;
                    p[i] = pos;
                    return;
                }else
                if (pos < p[i]) { 
                    swap(t[i], x); 
                    swap(p[i], pos);
                } 
                x ^= t[i]; 
            } 
        } 
    } 
}hamel_suf[N << 1]; 
void dfs(int u, int fa){
    sz[u] = 1;
    dfn[u] = ++tim;
    for (auto v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
void build(int rt, int l, int r){
    if (rt % 2 != 0)
        hamel_suf[rt].init();
    else    
        hamel_pre[rt].init();
    if (l == r) {
        to_tree_id[l] = rt;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}
void modify(int rt, int l, int r, int pos, ll x){
    if (rt % 2 != 0)
        hamel_suf[rt].insert(x, pos);
    else
        hamel_pre[rt].insert(x, pos);
    if (l == r) 
        return;
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(rt << 1, l, mid, pos, x);
    else modify(rt << 1 | 1, mid + 1, r, pos, x);
}
int getlca(int x, int y){
    return x >> lg2[x ^ y];
}
ll ansp[K], ansp_[K];
ll getans(int u, ll k){
    for (int i = K - 1;i >= 0;--i) ansp[i] = ansp_[i] = 0;
    if (dfn[u] == dfn[u] + sz[u] - 1){
        if (to_tree_id[dfn[u]] % 2 != 0){
            for (int i = K - 1;i >= 0;--i)
            if (hamel_suf[to_tree_id[dfn[u]]].p[i] <= dfn[u] + sz[u] - 1) ansp[i] = hamel_suf[to_tree_id[dfn[u]]].t[i];
        }else{
            for (int i = K - 1;i >= 0;--i)
            if (hamel_pre[to_tree_id[dfn[u]]].p[i] >= dfn[u]) ansp[i] = hamel_pre[to_tree_id[dfn[u]]].t[i];
        }
    }else{
        int lca = getlca(to_tree_id[dfn[u]], to_tree_id[dfn[u] + sz[u] - 1]);
        //cout<<"lca = "<<lca<<'\n';
        for (int i = K - 1;i >= 0;--i){
            if (hamel_pre[lca << 1].p[i] >= dfn[u]) ansp[i] =  hamel_pre[lca << 1].t[i];
        }
        for (int i = K - 1;i >= 0;--i){
            if (hamel_suf[lca << 1 | 1].p[i] <= dfn[u] + sz[u] - 1){
                ll x = hamel_suf[lca << 1 | 1].t[i];
                for (int j = K - 1;j >= 0; --j)
                if ((x >> j) & 1){
                    if (!ansp[j]) {
                        ansp[j] = x;
                        break;
                    }
                    else x ^= ansp[j];
                }
            }
        }
    }
    int tot = 0;
    for (int i = 0;i < K;++i){
        for (int j = i - 1;j >= 0;--j)
        if ((ansp[i] >> j) & 1) ansp[i] ^= ansp[j];
        if (ansp[i])
            ansp_[tot++] = ansp[i];
    }
    if ((1ll << tot) <= k) return -1;
    ll ans = 0;
    for (int i = 0;i < tot;++i){
        if ((k >> i) & 1)
            ans ^= ansp_[i];
    }
    return ans;
}
void solve(){
    cin>>n>>m;
    tim = 0;
	for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 1;i < n;++i) {
        int x, y;
        cin>>x>>y;
        e[x].push_back(y);
		e[y].push_back(x);
    }
    dfs(1, 0);
    //for (int i = 1;i <= n;++i) cout<<dfn[i]<<' '<<sz[i]<<'\n';cout<<'\n';
    n = (1ll << lg2[n]);//cout<<"n = "<<n<<'\n';
    build(1, 1, n);
    while (m--) {
        int op;
        cin>>op;
        if (op == 1){
            int u;ll x;
            cin>>u>>x;
            modify(1, 1, n, dfn[u], x);
        }else{
            int u;ll k;
            cin>>u>>k;
            cout<<getans(u, k)<<'\n';
        }
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("std.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // clock_t c1 = clock();
    lg2[0] = 0;lg2[1] = 1;
    for (int i = 2;i <= N - 10;++i) lg2[i] = lg2[i >> 1] + 1;
    int T = 1;cin>>T;
    while (T--){
        solve();
    }
    // cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}
/* 
Input
2
5 7
1 2
1 3
2 4
2 5
1 1 1
2 1 1
1 4 2
2 1 3
1 2 4
2 1 6
2 2 2
4 2
1 2
2 3
3 4
1 2 1
2 1 2
Output
1
3
6
4
-1

2
5 7
1 2
1 3
2 4
2 5
1 1 1
2 1 1
1 4 2
2 1 3
1 2 4
2 1 6
2 2 2
4 5
1 2
2 3
3 4
1 2 1
2 1 2
1 3 2
1 4 3
2 1 1
*/
