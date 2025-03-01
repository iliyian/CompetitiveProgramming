#include <bits/stdc++.h>

int mex(const std::set<int> &x) {
  int ans = 0;
  while (x.count(ans)) {
    ans++;
  }
  return ans;
}

int main(int argc, char **argv) {
  if (argc > 1) freopen(argv[1], "r", stdin);
  if (argc > 2) freopen(argv[2], "w", stdout);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> b(n + 1, std::vector<int>(n + 1));
  std::vector<std::vector<int>> c(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      std::set<int> x;
      for (int k = i; k <= j; k++) {
        x.insert(a[k]);
      }
      b[i][j] = mex(x);
    }
  }
#ifndef ONLINE_JUDGE
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j >= i) {
        std::cout << b[i][j] << ' ';
      } else {
        std::cout << "  ";
      }
    }
    std::cout << '\n';
  }
#endif
  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      std::set<int> x;
      for (int l = i; l <= j; l++) {
        for (int r = l; r <= j; r++) {
          for (int k = l; k <= r; k++) {
            x.insert(b[k][r]);
          }
        }
      }
      c[i][j] = mex(x);
      s.insert(c[i][j]);
    }
  }
#ifndef ONLINE_JUDGE
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j >= i) {
        std::cout << c[i][j] << ' ';
      } else {
        std::cout << "  ";
      }
    }
    std::cout << '\n';
  }
#endif
  std::cout << mex(s) << '\n';
  return 0;
}