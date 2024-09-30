// date: 2024-04-19 11:12:57
// tag: 博弈，背包

#include <bits/stdc++.h>
#define int long long
#define N 100000
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("E.in", "r", stdin);
  // freopen("E.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  bool f = false;
  bitset<301> in;
  if (sum % 2 == 0) {
    vector<int> dp(N);
    vector<vector<int>> g(n + 1, vector<int>(N));
    for (int i = 1; i <= n; i++) {
      for (int j = sum / 2; j >= a[i]; j--) {
        if (dp[j - a[i]] + a[i] > dp[j]) {
          dp[j] = dp[j - a[i]] + a[i];
          g[i][j] = true;
        }
      }
    }
    int v = sum / 2;
    if (dp[v] == v) {
      for (int i = n; i >= 1; i--) {
        if (g[i][v]) {
          in[i] = true;
          v -= a[i];
        }
      }
      f = true;
    }
  }

  auto write = [&](auto x) {
    cout << x << '\n';
    cout.flush();
  };

  auto print = [&]() {
    for (int i = 1; i <= n; i++) {
      cerr << a[i] << " \n"[i == n];
    }
  };

  if (sum % 2 || !f) {
    write("First");
    while (true) {
      int y = 0;
      for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
          y = i;
          write(i);
          break;
        }
      }
      int x;
      cin >> x;
      if (x == 0) {
        return 0;
      }
      int t = min(a[x], a[y]);
      a[x] -= t, a[y] -= t;
      print();
    }
  } else {
    write("Second");
    while (true) {
      int x, y;
      cin >> x;
      if (x == 0) {
        return 0;
      }
      for (int i = 1; i <= n; i++) {
        if (in[i] != in[x] && a[i] > 0) {
          y = i;
          write(y);
          break;
        }
      }
      if (y == 0) {
        for (int i = 1; i <= n; i++) {
          if (i != x && a[i] > 0) {
            y = i;
            write(y);
            break;
          }
        }
      }
      int t = min(a[x], a[y]);
      a[x] -= t, a[y] -= t;
      print();
    }
  }

  return 0;
}