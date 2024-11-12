#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e4;

std::vector<int> ans(N);

void solve() {
  int n;
  std::cin >> n;
  if (!ans[n]) {
    std::cout << "no\n";
  } else {
    std::cout << ans[n] << '\n';
  }
}

signed main() {
  int t = 1;
  std::cin >> t;
  for (int i = 1; i < N; i++) {
    int t = i, sum = 0;
    for (int j = 1; j * j <= t; j++) {
      if (t % j == 0) {
        sum += j;
        if (j * j != t) {
          sum += t / j;
        }
      }
    }
    ans[i] = (sum - i == i);
    ans[i] += ans[i - 1];
  }
  while (t--) {
    solve();
  }
  return 0;
}