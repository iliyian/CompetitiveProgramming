#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int mod = 1e9 + 7;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());
  freopen("d.in", "w", stdout);

  int t = 1;
  std::cout << t << '\n';
  while (t--) {
    int n = 10, w = 10;
    std::cout << n << '\n';
    std::vector<std::pair<int, int>> op(n);
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
      op[i] = {rd() % w, rd() % w};
    }
    int ans = 0;
    auto ansp = p;
    do {
      int x = 0;
      for (int i = 0; i < n; i++) {
        auto [a, b] = op[p[i]];
        x = (x * a % mod + b) % mod;
      }
      if (x > ans) {
        ans = x;
        ansp = p;
      }
    } while (std::next_permutation(p.begin(), p.end()));
    for (auto [a, b] : op) {
      std::cout << a << ' ' << b << '\n';
    }
    for (int i = 0; i < n; i++) {
      auto [a, b] = op[ansp[i]];
      std::cerr << a << ' ' << b << '\n';
      std::cerr << 1.0 * (a == 1 ? -111 : b / (a - 1)) << ' ';
    }
    std::cout << ans << '\n';
  }

  return 0;
}