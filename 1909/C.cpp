#include <bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> l(n), r(n), c(n);
  set<int> sr;
  for (int i = 0; i < n; i++)
    cin >> l[i];
  for (int i = 0; i < n; i++)
    cin >> r[i], sr.insert(r[i]);
  for (int i = 0; i < n; i++)
    cin >> c[i];
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());

  vector<int> d(n), id(n);

  // int t = upper_bound(r.begin(), r.end(), l.back()) - r.begin();
  // reverse(r.begin() + t, r.end());

  for (int i = n - 1; i >= 0; i--) {
    auto t = sr.upper_bound(l[i]);
    d[i] = *t - l[i];
    sr.erase(t);
  }

  sort(c.begin(), c.end());

  for (int i = 0; i < n; i++)
    d[i] = r[i] - l[i];
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](const int &x, const int &y) {
    return d[x] > d[y];
  });

  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += d[id[i]] * c[i];
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}