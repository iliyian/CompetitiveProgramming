// date: 2024-03-31 21:27:48
// tag: 尺取法，

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  auto check = [&](int l, int r) {
    for (int i = l; i <= r; i++) {
      for (int j = i + 1; j <= r; j++) {
        for (int k = j + 1; k <= r; k++) {
          if (a[i] <= a[j] && a[j] <= a[k]) return false;
          if (a[i] >= a[j] && a[j] >= a[k]) return false;
        }
      }
    }
    return true;
  };
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int r = 1, l = 1; r <= n; r++) {
    while (r >= l && !check(l, r)) {
      l++;
    }
    ans += r - l + 1;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}