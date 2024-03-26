#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m, k, t;
  cin >> n >> m >> k >> t;
  vector<int> a;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
  }
  sort(a.begin(), a.end(), greater());
  int cur = 0, sum = 0;
  for (int i = 0; i < a.size(); i++) {
    if (t) {
      cur += a[i];
      sum += a[i];
      t--;
    }
    if (cur >= k) {
      t += cur / k;
      cur %= k;
    }
  }
  cout << sum << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  solve();

  return 0;
}