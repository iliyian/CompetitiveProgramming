#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), vis(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (k == 1) {
    for (int i = 1; i <= n; i++) {
      if (a[i] != i) {
        cout << "NO\n";
        return;
      }
    }
  } else {
    for (int i = 1; i <= n; i++) {
      int j = i;
      while (vis[j] == -1) {
        vis[j] = i;
        j = a[j];
      }
      // 环的长度
      if (vis[j] == i) {
        int x = j, len = 0;
        do {
          x = a[x];
          len++;
        } while (x != j);
        if (k != len) {
          cout << "NO\n";
          return;
        }
      }
    }
  }
  cout << "YES\n";
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