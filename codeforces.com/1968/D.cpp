#include <bits/stdc++.h>
#define int long long
#define N 200000
using namespace std;

void solve() {
  int n, k, pb, ps;
  cin >> n >> k >> pb >> ps;
  vector<int> p(n + 1), a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  auto calc = [&](int s) {
    int ans = 0, sum = 0, mx = 0;
    bitset<N + 1> vis;
    for (int t = 0; t < min(k, n); t++) {
      mx = max(a[s], mx);
      sum += a[s];
      ans = max(ans, sum + (k - t - 1) * mx);
      s = p[s];
    }
    return ans;
  };
  int ansb = calc(pb), anss = calc(ps);
  cerr << ansb << ' ' << anss << '\n';
  if (ansb == anss) {
    cout << "Draw\n";
  } else if (ansb > anss) {
    cout << "Bodya\n";
  } else {
    cout << "Sasha\n";
  }
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