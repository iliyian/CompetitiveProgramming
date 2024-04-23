// date: 2024-04-23 12:43:57
// tag: 位运算，构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  bitset<1 << 17> vis;
  
  if (k == n - 1) {
    if (n == 2 || n == 4) {
      cout << -1 << "\n\n";
      return;
    }
    cout << 0 << ' ' << 2 << '\n';
    cout << 1 << ' ' << n - 3 << '\n';
    cout << n - 1 << ' ' << n - 2 << '\n';
    vis[0] = vis[1] = vis[2] = vis[n - 1] = vis[n - 2] = vis[n - 3] = true;
  } else {
    cout << n - 1 << ' ' << k << '\n';
    vis[k] = vis[n - 1] = true;
    if (k) {
      cout << 0 << ' ' << n - k - 1 << '\n';
      vis[0] = vis[n - k - 1] = true;
    }
  }

  for (int i = 0; i < n; i++) {
    if (!vis[i] && !vis[n - i - 1]) {
      cout << i << ' ' << n - i - 1 << '\n';
      vis[i] = vis[n - i - 1] = true;
    }
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}