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
const int N = 2e5 + 7;
const int M = 2e6 + 7;
const int modN = 998244353;
const double PI = acos(-1);
mt19937_64 rng(time(0));

ll a[N], dp[N], d[N];
vector<ll> e[N];
bool vis[N];
ll ans = 0, mx = 0;
void dfs(ll x){
    vis[x] = 1;
    for(auto v: e[x]){
        dp[v] = dp[x] + 1;
        dfs(v);
    }
    mx = max(mx, dp[x]);
}
void cut(ll x, ll s){
    vis[x] = 1;
    for(auto v: e[x]){
        if(v == s)
            ans = ans + dp[x] - dp[v] + 1;
        else{
            dp[v] = dp[x] + 1;
            cut(v, s);
        }
    }
}
void solve(){
    ll n;
    cin >> n;

    for (int i = 1; i <= n;i++){
        cin >> a[i];
        if(a[i] == i){
            ans++;
            continue;
        }
        d[a[i]]++;
        e[a[i]].PB(i);
    }
    for (int i = n + 1; i <= n * 2;i++){
        mx = 0;
        dfs(i);
        ans += mx;
    }
    
    for (int i = 1; i <= n;i++){
        if(!vis[i] && e[i].size() >= 2){
            cut(i, i);
        }
    }
    for (int i = 1; i <= n;i++){
        if(!vis[i] && e[i].size() == 1)
            ans++;
    }
    cout << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    solve();

    return 0;
}