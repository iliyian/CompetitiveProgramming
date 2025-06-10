#include<bits/stdc++.h>
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
const int N = 1e6 + 7;
const int M = 2e6 + 7;
const int modN = 998244353;
const double PI = acos(-1);
mt19937_64 rng(time(0));

struct node{
    ll u, v, w;
    bool operator<(const node p)const{
        return w < p.w;
    }
};
vector<pll> e[N];
ll fa[N], dep[N];
ll st[N][30], mx[N][30][2];
ll anns[2];
ll find(ll x){
    if(x == fa[x])
        return x;
    return fa[x] = find(fa[x]);
}
bool merge(ll x, ll y){
    ll fx = find(x), fy = find(y);
    if(fx == fy)
        return false;
    fa[fx] = fy;
    return true;
}
void dfs(ll x, ll pre){
    for(auto [v, w]: e[x]){
        if(v == pre)
            continue;
        dep[v] = dep[x] + 1;
        st[v][0] = x;
        mx[v][0][w % 2] = w;
        dfs(v, x);
    }
}
void init(ll n){
    for (int j = 1; j <= 29;j++){
        for (int i = 1; i <= n;i++){
            st[i][j] = st[st[i][j - 1]][j - 1];
            mx[i][j][0] = max(mx[st[i][j - 1]][j - 1][0], mx[i][j - 1][0]);
            mx[i][j][1] = max(mx[st[i][j - 1]][j - 1][1], mx[i][j - 1][1]);
        }
    }
}
ll LCA(ll u, ll v, ll w) {
    ll typ = (w % 2) ^ 1;
    ll ans = 0;
    if (dep[u] < dep[v])
        swap(u, v);
    ll h = dep[u] - dep[v];
    for (int i = 0; i < 30; i++) {
        if ((1ll << i) & h){
            ans = max(ans, mx[u][i][typ]);
            u = st[u][i];
        }
    }
    if (u == v){
        return ans;
    }
    for (int i = 19; i >= 0; i--) {
        if (st[u][i] != st[v][i]) {
            ans = max(ans, mx[u][i][typ]);
            ans = max(ans, mx[v][i][typ]);
            u = st[u][i], v = st[v][i];
        }
    }
    ans = max(ans, mx[u][0][typ]);
    ans = max(ans, mx[v][0][typ]);
    return ans;
}
void solve(){
    ll n, m;
    cin >> n >> m;
    anns[0] = anns[1] = INF;
    for (int i = 1; i <= n;i++){
        e[i].clear();
        fa[i] = i;
        dep[i] = 0;
        mx[i][0][0] = mx[i][0][1] = 0;
    }
    vector<node> arr;
    for (int i = 1; i <= m;i++){
        ll u, v, w;
        cin >> u >> v >> w;
        arr.PB({u, v, w});
    }
    sort(arr.begin(), arr.end());
    ll tot = n, sum = 0, p = 0;
    for(auto [u, v, w]:arr){
        if(merge(u, v)){
            e[u].PB({v, w});
            e[v].PB({u, w});
            tot--;
            sum += w;
        }
        p++;
        if(tot == 1){
            anns[sum % 2] = sum;
            break;
        }
    }
    if(tot != 1){
        cout << "-1 -1\n";
        return;
    }

    st[1][0] = 0;
    dfs(1, 1);
    init(n);

    for (auto [u,v,w]:arr){
        // ll u = arr[i].u, v = arr[i].v, w = arr[i].w;

        ll cur = LCA(u, v, w);
        if(cur){
            ll num = sum + w - cur;
            anns[num % 2] = min(anns[num % 2], num);
            // cerr << cur << " ";
        }
    }
    if(anns[0] == INF)
        anns[0] = -1;
    if(anns[1] == INF)
        anns[1] = -1;
    cout << anns[0] << " " << anns[1] << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;
    while(T--)
        solve();

    return 0;
}