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
const int N = 2e6 + 7;
const int M = 5e8 + 7;
const int modN = 1e9 + 7;
const double PI = acos(-1);
mt19937_64 rng(time(0));

ll a[N];
ll st[N][20];
ll rst[N];

ll query(ll l, ll r){
    if(l > r)
        return 0;
    ll ans = 0;
    for (int i = 19; i >= 0;i--){
        if(l + (1ll << i) - 1 <= r){
            ans = max(st[l][i], st[r - (1ll << i) + 1][i]);
            break;
        }
    }

    return ans;
}

void solve() {
    ll n, q;
    cin >> n >> q;
    for (int i = 1; i <= n;i++) {
        rst[i] = i;
        st[i][0] = 0;
    }

    for (int i = 1; i <= n;i++)
        cin >> a[i];
    
    ll typ = 0;
    ll l = 1, r = 1;
    vector<pll> dt;
    for (int i = 2; i <= n;i++) {
        if(a[i] > a[i - 1]){
            if(typ == 1){
                if(l != r)
                    dt.PB({l, r});
                i--;
                l = r = i;
                typ = 0;
            }
            else{
                typ = 1;
                r = i;
            }
        }
        else if(a[i] < a[i - 1]){
            if(typ == -1){
                if(l != r)
                    dt.PB({l, r});
                i--;
                l = r = i;
                typ = 0;
            }
            else{
                typ = -1;
                r = i;
            }
        }
        else{
            if (l != r)
                dt.PB({l, r});
            l = r = i;
            typ = 0;
        }  
    }
    if (l != r)
        dt.PB({l, r});

    // for(auto [L, R]: dt){
    //     cout << L << " " << R << "\n";
    // }

    vector<pll> v;

    for(auto [L, R]: dt){
        priority_queue<pll, vector<pll>, greater<pll>> q1;
        priority_queue<pll, vector<pll>, less<pll>> q2;
        bool typp = 0;
        if(a[L + 1] - a[L] > 0)
            typp = 1;
        ll cur = L;
        // cout << "\n";
        for (int i = L; i <= R;i++){
            if(typp){
                if((i - L) % 2)
                    q1.push({a[i], i});
                else
                    q2.push({a[i], i});
                if(q1.size() && q2.size() && q1.top().fst <= q2.top().fst)
                    v.PB({cur, i - 1});
                while (q1.size() && q2.size() && q1.top().fst <= q2.top().fst){
                    cur++;
                    while(q1.size() && q1.top().scd < cur)
                        q1.pop();
                    while (q2.size() && q2.top().scd < cur)
                        q2.pop();
                }
                // cout << cur << " ";
            }
            else{
                if ((i - L) % 2)
                    q2.push({a[i], i});
                else
                    q1.push({a[i], i});
                if (q1.size() && q2.size() && q1.top().fst <= q2.top().fst)
                    v.PB({cur, i - 1});
                while (q1.size() && q2.size() && q1.top().fst <= q2.top().fst) {
                    cur++;
                    while (q1.size() && q1.top().scd < cur)
                        q1.pop();
                    while (q2.size() && q2.top().scd < cur)
                        q2.pop();
                }
                // cout << cur << " ";
            }
        }
        v.PB({cur, R});
    }

    // for(auto [L, R]: dt){
    //     cerr << L << " " << R << "\n";
    // }

    ll cur = n;
    while(!v.empty()){
        auto [L, R] = v.back();
        // cout << L << " " << R << "\n";
        v.pop_back();
        for (cur = min(cur, R); cur >= L;cur--){
            rst[cur] = R;
            st[cur][0] = R - cur + 1;
        }
    }
    for (int j = 1; j < 20;j++){
        for (int i = 1; i + (1ll << j) - 1 <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1ll << j - 1)][j - 1]);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= q;i++){
        ll x, y;
        cin >> x >> y;
        ll now = lower_bound(rst + x, rst + 1 + y, y) - rst;
        ll cnt = y - now + 1;
        // cout << now << "\n";
        cnt = max(cnt, query(x, now - 1));
        cout << cnt << "\n";
        ans = ans + cnt * i;
        ans %= modN;
    }
    cout << ans << "\n\n";
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