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


void solve(){
    ll n, m;
    cin >> n >> m;
    if(m % n == 0){
        cout << "0\n";
        return;
    }
    else if(n > m){
        cout << n - m << "\n";
        return;
    }
    ll mul = m / n + 1;
    ll cur = n;
    ll cnt = mul * cur;
    ll ans = INF;
    ll sum = 0;
    while(cur > 1){
        // cerr << cur << " " << cnt << "\n";
        ll dis = cnt - m;
        ll now = dis / mul;
        sum += now;
        ans = min(ans, sum + (dis % mul));
        sum++;
        cur -= now + 1;
        mul = m / cur + 1;
        cnt = mul * cur;
    }
    cout << ans << "\n";
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