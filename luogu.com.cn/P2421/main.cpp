// date: 2024-03-03 14:52:39
// tag: wa:1e6写成1e5
// wa:mod没有除以gcd导致解错
// wa:没有考虑左边界

#include <bits/stdc++.h>
#define int long long
using namespace std;

int exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  int g = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return g;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int t = 1;

  while (t--) {
    int n, s = 1;
    cin >> n;
    vector<int> C(n + 1), P(n + 1), L(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> C[i] >> P[i] >> L[i];
      s = max(s, C[i]);
    }
 
    for (int m = s; m <= 1000000; m++) {
      bool f = false;
      for (int i = 1; i <= n && !f; i++) {
        for (int j = i + 1; j <= n && !f; j++) {
          int x, y;
          int a = (P[i] - P[j] + m) % m, b = m, c = (C[j] - C[i] + m) % m;
          int g = exgcd(a, b, x, y);
          if (c % g) {
            continue;
          }
          a /= g, b /= g, c /= g;
          x *= c;
          x = (x % b + b) % b;
          if (x <= min(L[i], L[j])) {
            f = true;
          }
        }
      }
      if (!f) {
        cout << m << '\n';
        break;
      }
    }

  }

  return 0;
}