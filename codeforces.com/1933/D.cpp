#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  sort(a.begin() + 1, a.end());
  int g = 0;
  for (int i = 1; i <= n; i++) {
    g = gcd(g, a[i]);
  }
  // cout << (cnt[a[1]] < 2 ? "YES" : "NO") << '\n';
  cout << (cnt[g] < 2 ? "YES" : "NO") << '\n';
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