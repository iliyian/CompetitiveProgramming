// date: 2024-07-20 09:21:28
// tag: 数位dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

std::vector<std::vector<int>> f(11, std::vector<int>(10));

int solve(int x) {
  int ans = 0, t = x;
  std::vector<int> a;
  while (t) {
    a.push_back(t % 10);
    t /= 10;
  }
  for (int i = 1; i < a.back(); i++) {
    ans += f[a.size()][i];
  }
  for (int i = 1; i < a.size(); i++) {
    for (int j = 1; j < 10; j++) {
      ans += f[i][j];
    }
  }
  for (int i = a.size() - 2; i >= 0; i--) {
    for (int j = 0; j <= a[i] - 1; j++) {
      if (std::abs(j - a[i + 1]) >= 2) {
        ans += f[i + 1][j];
      }
    }
    if (std::abs(a[i + 1] - a[i]) < 2) {
      break;
    }
  }
  return ans;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  fill(f[1].begin(), f[1].end(), 1);
  for (int i = 2; i <= 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        if (abs(j - k) >= 2) {
          f[i][j] += f[i - 1][k];
        }
      }
    }
  }

  int l, r;
  std::cin >> l >> r;
  std::cout << solve(r + 1) - solve(l) << '\n';

  // int ans = 0;
  // for (int i = l; i <= r; i++) {
  //   auto s = std::to_string(i);
  //   bool f = true;
  //   for (int j = 0; j < s.size() - 1; j++) {
  //     if (abs(s[j] - s[j + 1]) < 2) {
  //       f = false;
  //       break;
  //     }
  //   }
  //   ans += f;
  // }
  // std::cout << ans << '\n';

  return 0;
}