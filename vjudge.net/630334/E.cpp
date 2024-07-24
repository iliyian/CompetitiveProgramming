#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> b;
  int src = 0;
  for (int i = 1; i <= n; i++) {
    if (b.empty() || a[i] > b.back()) {
      if (b.empty()) src = i;
      b.push_back(a[i]);
    }
    else {
      auto p = lower_bound(b.begin(), b.end(), a[i]);
      if (p - b.begin() == 0 && *p != a[i]) src = i;
      *p = a[i];
    }
  }
  int maxlen = b.size();
  vector<int> can(n + 1);
  int anscnt = 0;
  for (int i = 1; i <= n; i++) {
    auto p = lower_bound(b.begin(), b.end(), a[i]);
    if (p != b.end() && *p == a[i] && i >= src) {
      can[i] = true;
      anscnt++;
    }
  }
  cout << anscnt << '\n';
  for (int i = 1; i <= n; i++) {
    if (can[i]) {
      cout << i << ' ';
    }
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}