// date: 2024-10-21 12:23:58
// tag: 二维树状数组

#include <bits/stdc++.h>
// #define int long long

constexpr int N = 2048;

int t1[N + 2][N + 2], t2[N + 2][N + 2], t3[N + 2][N + 2], t4[N + 2][N + 2];
int n, m;

void add(int x, int y, int v) {
  x++, y++;
  for (int i = x; i <= n; i += i & -i) {
    for (int j = y; j <= m; j += j & -j) {
      t1[i][j] += v;
      t2[i][j] += y * v;
      t3[i][j] += x * v;
      t4[i][j] += x * y * v;
    }
  }
}

void range_add(int a, int b, int c, int d, int v) {
  add(a - 1, b - 1, v);
  add(a - 1, d, -v);
  add(c, b - 1, -v);
  add(c, d, v);
}

int query(int x, int y) {
  x++, y++;
  int ans = 0;
  for (int i = x; i > 0; i -= i & -i) {
    for (int j = y; j > 0; j -= j & -j) {
      ans += x * y * t1[i][j];
      ans -= x * t2[i][j];
      ans -= y * t3[i][j];
      ans += t4[i][j];
    }
  }
  return ans;
}

int range_query(int a, int b, int c, int d) {
  return query(c, d) - query(a - 1, d) - query(c, b - 1) + query(a - 1, b - 1);
}

signed main() {
  freopen("main.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  char op;
  std::cin >> op >> n >> m;
  while (std::cin >> op) {
    int a, b, c, d, x;
    if (op == 'L') {
      std::cin >> a >> b >> c >> d >> x;
      range_add(a, b, c, d, x);
    } else {
      std::cin >> a >> b >> c >> d;
      std::cout << range_query(a, b, c, d) << '\n';
    }
  }
  return 0;
}