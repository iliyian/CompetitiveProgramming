#include <bits/stdc++.h>
#define int long long

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> p(32);
  for (int k = 3; k <= 31; k++) {
    p[k].push_back(0);
    for (int i = 1;; i++) {
      int cur = qpow(i, k);
      if (cur > (1ll << 31)) break;
      p[k].push_back(cur + p[k].back());
    }
  }
  auto answer = [&](int l, int r, int i) {
    for (int j = l; j <= r; j++) {
      std::cout << j << "^" << i;
      if (j == r) {
        std::cout << "\n";
      } else {
        std::cout << "+";
      }
    }
  };
  for (int i = 31; i >= 3; i--) {
    // for (int l = 0; l < p[i].size(); l++) {
    int l = 0;
      auto r = std::lower_bound(p[i].begin(), p[i].end(), n - p[i][l]) - p[i].begin();
      if (r != p[i].size() && p[i][r] - p[i][l] == n) {
        answer(l + 1, r, i);
        // for (int j = l + 1; j <= r; j++) {
        //   std::cout << j << "^" << i;
        //   if (j == r) {
        //     std::cout << "\n";
        //   } else {
        //     std::cout << "+";
        //   }
        // }
        return;
      }
    // }
  }
  int l = 1, r = 10000, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (mid * (mid + 1) * (2 * mid + 1) / 6 <= n) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  if (ans != -1 && ans * (ans + 1) * (2 * ans + 1) / 6 == n) {
    answer(1, ans, 2);
    return;
  }
  
  l = 1, r = 1e5;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (mid * (mid + 1) / 2 <= n) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  if (ans != -1 && ans * (ans + 1) / 2 == n) {
    answer(1, ans, 1);
    return;
  }
  std::cout << "Impossible for " << n << ".";
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}