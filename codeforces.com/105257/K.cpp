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
const int N = 5e5 + 7;
const int M = 2e6 + 7;
const int modN = 998244353;
const double PI = acos(-1);
mt19937_64 rng(time(0));

ll n, m, k;
struct node{
    ll t, x, y;
    bool operator<(const node p) const {
        return t < p.t; 
    };
} a[N];
bool check(ll mid){
    vector<ll> cnt(n + 1, 0);
    ll res = mid;
    for (int i = m; i >= 1;i--){
        if(a[i].t > mid)
            continue;
        ll lim = mid - a[i].t + 1 - (a[i].y - 1) / k - cnt[a[i].x];
        cnt[a[i].x] += max(0ll, lim);
        if(res - a[i].t + 1 >= lim)
            res -= max(0ll, lim);
        else
            return false;

    }
    return true;
}
void solve(){
    cin >> n >> m >> k;
    set<ll> s;
    for (int i = 1; i <= m;i++){
        cin >> a[i].t >> a[i].x >> a[i].y;
        s.insert(a[i].x);
    }
    if(s.size() == 1){
        cout << "-1\n";
        return;
    }
    sort(a + 1, a + 1 + m);
    ll l = 0, r = 4e18;
    
    while(l < r){
        ll mid = (l + r + 1) / 2;
        if(check(mid))
            l = mid;
        else
            r = mid - 1;

    }
    cout << l << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    solve();

    return 0;
}