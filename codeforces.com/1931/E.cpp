#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  auto check0 = [&](auto self, int x) -> int {
    if (x < 10) return 0;
    return (x % 10 == 0 ? (1 + self(self, x / 10)) : 0);
  };
  auto check = [&](auto self, int x) -> int {
    if (x) return 1 + self(self, x / 10);
    return 0;
  };
  vector<pair<int, int>> vec;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vec.push_back({check0(check0, a[i]), check(check, a[i])});
  }
  sort(vec.begin(), vec.end(), greater());
  int ans = 0;
  for (int i = 0; i < vec.size(); i++) {
    int zlen = vec[i].first, len = vec[i].second;
    if (i % 2 == 0) ans += len - zlen;
    else ans += len;
  }
  cout << (ans <= m ? "Anna" : "Sasha") << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}