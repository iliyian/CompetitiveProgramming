// date: 2024-04-20 22:24:49
// tag: 构造，模拟

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int ans = 0;
  stack<int> s;
  bool f = false;
  for (int i = 0; i <= n; i++) {
    if (f) {
      cout << -1 << ' ';
    } else {
      cout << ans + cnt[i] << ' ';
    }

    for (int j = 1; j <= cnt[i]; j++) {
      s.push(i);
    }

    if (s.empty()) {
      f = true;
    } else {
      ans += i - s.top();
      s.pop();
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