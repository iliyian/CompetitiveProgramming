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
const int INF = 0x3f3f3f3f;
const int N = 2e6 + 7;
const int M = 2e6 + 7;
const int modN = 998244353;
const double PI = acos(-1);
mt19937_64 rng(time(0));

struct node{
    char c;
    ll u, v;
} a[N];
pll mat[505][505];
pll fa[505][505];
set<ll> s1[505], s2[505];
ll ans[505][505];
pll find(pll p){
    ll x = p.fst, y = p.scd;
    if(fa[x][y] == p)
        return p;
    return fa[x][y] = find(fa[x][y]);
}
void add(pll x, pll y){
    pll fx = find(x), fy = find(y);
    if(fx != fy)
        fa[fx.fst][fx.scd] = fy;
    
}
void solve(){
    ll n, t;
    cin >> n >> t;
    for (int i = 1; i <= t;i++)
        cin >> a[i].c >> a[i].u >> a[i].v;

    map<pll, vector<pll>> v;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            mat[i][j] = {i, j};
            fa[i][j] = {i, j};
        }
    }
    for (int i = 1; i <= t;i++){
        ll u = a[i].u, v = a[i].v;
        if(a[i].c == 'R'){
            for (int j = 1; j <= n;j++)
                swap(mat[u][j], mat[v][j]);
        }
        else{
            for (int j = 1; j <= n;j++)
                swap(mat[j][u], mat[j][v]);
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            add({i, j}, mat[i][j]);
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            v[fa[i][j]].PB({i, j});
        }
    }
    if(v.size() == n * n){
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                cout << (i + j - 1) % n + 1 << " \n"[j == n];
            }
        }
        return;
    }
    for(auto x: v){
        set<ll> ss1, ss2;
        for(auto [i, j]: x.scd){
            if(ss1.find(i) != ss1.end() || ss2.find(j) != ss2.end()){
                cout << '*';
                return;
            }
            ss1.insert(i);
            ss2.insert(j);
        }
        set<ll> S;
        for(auto [i, j]: x.scd){
            for(auto p: s1[i])
                S.insert(p);
            for(auto p: s2[j])
                S.insert(p);
        }
        ll cur = 1;
        for(auto p: S){
            if(cur == p)
                cur++;
            else
                break;
        }
        for(auto [i, j]: x.scd){
            s1[i].insert(cur);
            s2[j].insert(cur);
            ans[i][j] = cur;
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cout << ans[i][j] << " \n"[j == n];
        }
    }
    // for (int i = 1; i <= t;i++){
    //     ll u = a[i].u, v = a[i].v;
    //     if(a[i].c == 'R'){
    //         for (int j = 1; j <= n;j++)
    //             swap(ans[u][j], ans[v][j]);
    //     }
    //     else{
    //         for (int j = 1; j <= n;j++)
    //             swap(ans[j][u], ans[j][v]);
    //     }
    // }
    // cout << "\n";
    // for (int i = 1; i <= n;i++){
    //     for (int j = 1; j <= n;j++){
    //         cout << ans[i][j] << " \n"[j == n];
    //     }
    // }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}