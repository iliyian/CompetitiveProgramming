#include <bits/stdc++.h>
#define int long long

signed main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  a.erase(std::unique(a.begin() + 1, a.end()), a.end());
  int mex = 0;
  for (int i = 1; i <= std::min(k, (int)a.size() - 1); i++) {
    if (a[i] == mex) {
      mex++;
    } else {
      break;
    }
  }
  std::cout << mex << '\n';
}