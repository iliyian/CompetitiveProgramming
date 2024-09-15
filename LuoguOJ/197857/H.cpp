#include <bits/stdc++.h>
#define int long long

signed main() {
  freopen("H.in", "r", stdin);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1), id(n + 1);
  int x = 0, y = 0;
  std::iota(id.begin() + 1, id.end(), 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  std::sort(id.begin() + 1, id.end(),
    [&](const int &x, const int &y) {
      return a[x] - b[x] > a[y] - b[y];
    });

  int cur = 0;
  for (int i = 1; i <= n; i++) {
    if (a[id[i]] > b[id[i]]) {
      cur++;
    } else if (a[id[i]] < b[id[i]]) {
      cur--;
    }
  }

  int sum = 0;
  for (int i = 1; i <= n && cur <= 0; i++) {
    if (a[id[i]] == b[id[i]]) {
      cur++;
      sum++;
    } else if (a[id[i]] < b[id[i]]) {
      cur++;
      sum += b[id[i]] - a[id[i]];
      if (cur > 0) break;
      cur++;
      sum++;
    }
  }

  std::cout << sum << '\n';
  return 0;
}