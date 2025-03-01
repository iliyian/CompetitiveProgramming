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
const int N = 3e5 + 7;
const int M = 5e8 + 7;
const int modN = 1e9 + 7;
const double PI = acos(-1);
mt19937_64 rng(time(0));

ll num[N];
struct node {
  ll a, b, c;
};

node cal(ll x, ll y, ll p) {
  ll ans1 = 0, ans2 = 0, ans3 = 0;
  ll base = 1;
  while (x || y) {
    ll resx = x % p, resy = y % p;
    ans1 = ans1 + min(resx, resy) * base;
    ans2 = ans2 + max(resx, resy) * base;
    ans3 = ans3 + ((resx + resy) % p) * base;
    base *= p;
    x /= p;
    y /= p;
  }
  return {ans1, ans2, ans3};
}
void solve() {
  ll n, A, x;
  cin >> n >> A >> x;
  for (int i = 1; i <= n; i++)
    cin >> num[i];

  ll lim = A;
  while (lim < 1024) {
    lim *= A;
  }
  vector<bool> vis(lim, 0);
  vis[x] = 1;
  for (int i = 1; i <= n; i++) {
    vector<bool> mvis(lim, 0);
    for (int j = 0; j < lim; j++) {
      if (vis[j]) {
        node p;
        p = cal(j, num[i], A);
        mvis[p.a] = mvis[p.b] = mvis[p.c] = 1;
      }
    }
    vis = mvis;
  }

  ll ans = 0;
  for (int i = 1; i < lim; i++)
    ans = ans + i * vis[i];
  cout << ans << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}