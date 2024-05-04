// date: 2024-05-03 14:01:11
// tag: 二分，map套vector

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 2), s(n + 2);
  map<int, vector<int>> pos;
  pos[0].push_back(0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] ^ a[i];
    pos[s[i]].push_back(i);
  }
  auto lo = [&](auto val, int x) {
    return lower_bound(pos[val].begin(), pos[val].end(), x);
  };
  auto up = [&](auto val, int x) {
    return upper_bound(pos[val].begin(), pos[val].end(), x);
  };
  for (int _ = 1; _ <= q; _++) {
    int l, r;
    cin >> l >> r;
    int k = s[r] ^ s[l - 1];
    if (k == 0) {
      cout << "YES\n";
      continue;
    }
    int ll = *lo(s[r], l), rr = *(up(s[l - 1], r) - 1);
    if (ll <= rr) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}