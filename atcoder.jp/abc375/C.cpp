#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("C.in", "r", stdin);
  int n;
  std::cin >> n;
  std::vector<std::vector<char>> a(n + 1, std::vector<char>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j]; 
    }
  }
  for (int t = 1; t <= n / 2; t++) {
    std::vector<char*> v;
    for (int i = t; i <= n - t; i++) {
      v.push_back(&a[t][i]);
    }
    for (int i = t; i <= n - t; i++) {
      v.push_back(&a[i][n - t + 1]);
    }
    for (int i = t; i <= n - t; i++) {
      v.push_back(&a[n - t + 1][n - i + 1]);
    }
    for (int i = t; i <= n - t; i++) {
      v.push_back(&a[n - i + 1][t]);
    }
    std::vector<char> u(v.size());
    for (int i = 0; i < u.size(); i++) {
      u[i] = *v[i];
    }
    int len = (t % 4) * (n - t * 2 + 1) % u.size();
    for (int i = 0; i < u.size(); i++) {
      *v[i] = u[i - len < 0 ? i - len + (int)u.size() : i - len];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cout << a[i][j];
    }
    std::cout << '\n';
  }
  return 0;
}