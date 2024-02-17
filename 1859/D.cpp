#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

void solve() {
  int n;
  cin >> n;
  set<pair<int, int>> s, ans;
  for (int i = 1; i <= n; i++) {
    int l, r, a, b;
    cin >> l >> r >> a >> b;
    s.insert({l, b});
  }
  auto it = s.begin();
  while (it != s.end()) {
    auto it2 = next(it);
    int r = it->second;
    while (it2 != s.end() && it2->first <= r) {
      r = max(r, it2->second);
      it2 = next(it2);
    }
    ans.insert({it->first, r});
    it = it2;
  }
  int q;
  cin >> q;
  for (int t = 1; t <= q; t++) {
    int x;
    cin >> x;
    auto it = ans.upper_bound({x, inf});
    if (it != ans.begin()) {
      it--;
      cout << max(x, it->second) << ' ';
    } else {
      cout << x << ' ';
    }
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}