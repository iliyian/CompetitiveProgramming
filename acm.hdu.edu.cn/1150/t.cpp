#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define fst first
#define scd second
#define mid (s + t) / 2
#define lc p << 1
#define rc p << 1 | 1

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

void solve() {
    ll n, q;
    cin >> n >> q;
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
    set<ll> s;

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

    // std::cout << "qwq\n";
    std::vector<std::vector<std::pair<int, int>>> ask(n + 1);
    std::vector<std::vector<int>> vecl(n + 1);
    for(auto [L, R]:v){
        cout << L << " " << R << "\n";
        vecl[R].push_back(L);
    }
    cout << "\n";

    return;

    std::vector<int> ans(q + 1);
    int res = 0;

    std::vector<int> maxr(n << 2), maxlen(n << 2);
    auto query = [&](auto self, int l, int r, int s, int t, int p, std::vector<int> &d) -> int {
      if (l > t || r < s) return 0;
      if (l <= s && t <= r) return d[p];
      return std::max(self(self, l, r, s, mid, lc, d), self(self, l, r, mid + 1, t, rc, d));
    };
    auto add = [&](auto self, int x, int s, int t, int p, int r) {
      if (x > t || x < s) return;
      if (s == t) {
        maxr[p] = std::max(maxr[p], r);
        maxlen[p] = std::max(maxlen[p], r - x + 1);
        return;
      }
      self(self, x, s, mid, lc, r);
      self(self, x, mid + 1, t, rc, r);
      maxr[p] = std::max(maxr[lc], maxr[rc]);
      maxlen[p] = std::max(maxlen[lc], maxlen[rc]);
    };
    for (int i = 1; i <= q; i++) {
      int l, r;
      std::cin >> l >> r;
      ask[r].push_back({l, i});
    }
    for (int i = 1; i <= n; i++) {
      for (auto l : vecl[i]) {
        add(add, l, 1, n, 1, i);
      }
      for (auto [l, idx] : ask[i]) {
        if (l == i) {
          ans[idx] = 0;
          continue;
        }
        ans[idx] = std::max(query(query, 1, l, 1, n, 1, maxr) - l + 1, query(query, l, i, 1, n, 1, maxlen));
      }
    }
    for (int i = 1; i <= q; i++) {
      res += i * ans[i] % modN;
      res %= modN;
    }
    std::cout << res << '\n';
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