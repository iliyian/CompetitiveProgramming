// date: 2024-03-24 22:48:23
// tag: 卢卡斯定理

#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;

vector<int> fac(200001);

void exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

int C(int n, int m, int p) {
  // if (n < m) return 0;
  int ans = 1;
  for (int i = n; i >= n - m + 1; i--) {
    ans = ans * i % p;
  }
  for (int i = 2; i <= m; i++) {
    int x, y;
    exgcd(i, p, x, y);
    x = (x % p + p) % p;
    ans = ans * x % p;
  }
  return ans;
}

int Lucas(int n, int m, int p) {
  if (m == 0) return 1;
  return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}

void solve() {
  int n, m, p;
  cin >> n >> m >> p;

  cout << Lucas(n + m, m, p) << '\n';
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