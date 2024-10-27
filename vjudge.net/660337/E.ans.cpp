#include <bits/stdc++.h>

int main() {
  freopen("E.in", "r", stdin);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int op, l, r;
    std::cin >> op >> l >> r;
    l++, r++;
    if (op == 0) {
      for (int j = l; j <= r; j++) {
        a[j] = 0;
      }
    } else if (op == 1) {
      for (int j = l; j <= r; j++) {
        a[j] = 1;
      }
    } else if (op == 2) {
      for (int j = l; j <= r; j++) {
        a[j] ^= 1;
      }
    } else if (op == 3) {
      int cnt = 0;
      for (int j = l; j <= r; j++) {
        cnt += (a[j] == 1);
      }
      std::cout << cnt << '\n';
    }
  }
  return 0;
}