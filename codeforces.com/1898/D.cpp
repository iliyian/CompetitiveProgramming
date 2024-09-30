// date: 2024/02/26 12:03:09
// tag: 形象化，一遍过

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  int sum = 0;
  vector<int> id(n + 1);
  iota(id.begin() + 1, id.end(), 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    sum += abs(a[i] - b[i]);
  }
  int r = 0x3f3f3f3f, l = -0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    l = max(l, min(a[i], b[i]));
    r = min(r, max(a[i], b[i]));
  }
  cout << (l > r ? sum + 2 * (l - r) : sum) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}