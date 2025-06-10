// date: 2025-05-16 17:01:39
// tag: 怎么说呢？题目难度确实呈现逐年上升的趋势。这什么水题啊。正解则主要还是根据奇偶性绝对可以互相转换，然后正常推导即可。

#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e3;
std::vector<int> ans(N + 1, -1);

bool solve(int x) {
  if (ans[x] != -1) return ans[x];
  bool f = false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      if (!solve(x - i)) {
        f = true;
        break;
      }
      if (i * i != x) {
        if (!solve(x - x / i)) {
          f = true;
          break;
        }
      }
    }
  }
  return ans[x] = f;
}

void solve() {
  int i;
  std::cin >> i;
  std::cout << (i % 2 == 0 && (__builtin_popcountll(i) != 1 || (63 - __builtin_clzll(i)) % 2 == 0) ? "Alice" : "Bob") << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int i = 1; i <= N; i++) {
  //   std::cout << i << ": " << solve(i) << '\n';
  //   if (i % 2 == 0 && (__builtin_popcountll(i) != 1 || (63 - __builtin_clzll(i)) % 2 == 0)) {
  //     assert(solve(i) == 1);
  //   } else {
  //     if (solve(i) == 1) {
  //       std::cerr << i << '\n';
  //     }
  //     assert(solve(i) == 0);
  //   }
  // }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}