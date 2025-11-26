#include <bits/stdc++.h>
#define int long long

std::mt19937_64 rd(std::random_device{}());

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::vector<std::vector<int>> ans(11, std::vector<int>(11));
  for (int n = 1; n <= 10; n++) {
    std::vector<int> p(n + 1);
    std::vector<std::vector<int>> v;
    std::ranges::iota(p, 0);
    v.push_back(p);
    auto work = [n](std::vector<int> p, int x) {
      for (int i = 1; i <= n; i++) {
        if (p[i] < x) p[i]++;
        else if (p[i] > x) p[i]--;
      }
      return p;
    };
    for (int i = 1; i <= 500000; i++) {
      int j = rd() % v.size();
      v.push_back(work(v[j], rd() % n + 1));
      std::ranges::sort(v);
      v.erase(std::unique(v.begin(), v.end()), v.end());
    }
    for (auto p : v) {
      for (int i : p) {
        ans[n][i]++;
      }
    }
    for (int i = 1; i <= n; i++) {
      std::cout << ans[n][i] << ' ';
    }
    std::cout << '\n';
  }

  return 0;

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}