#include <bits/stdc++.h>
#define int long long

std::mt19937_64 rd(std::random_device{}());

using u64 = unsigned long long;

void solve() {
  int n, m1, m2;
  std::cin >> n >> m1 >> m2;
  std::vector<std::array<int, 3>> e1(m1), e2(m2);
  for (auto &[w, x, y] : e1) {
    std::cin >> x >> y >> w;
  }
  for (auto &[w, x, y] : e2) {
    std::cin >> x >> y >> w;
  }
  int nn = n + n - 1;
  std::vector<u64> xval(nn + 1);
  for (int i = 1; i <= nn; i++) {
    xval[i] = rd();
  }
  auto work = [&](std::vector<std::array<int, 3>> &e) -> int {
    std::ranges::sort(e);
    std::vector<std::vector<int>> g(nn + 1);
    std::vector<int> pa(nn + 1);
    std::ranges::iota(pa, 0);
    auto find = [&](this auto &&self, int x) -> int {return x == pa[x] ? x : pa[x] = self(pa[x]);};
    int tot = n;
    std::vector<int> val(nn + 1), l(nn + 1), r(nn + 1);
    for (auto [w, x, y] : e) {
      x = find(x), y = find(y);
      if (x != y) {
        int u = ++tot;
        l[u] = x, r[u] = y;
        pa[x] = pa[y] = u;
        val[u] = w;
      }
    }
    u64 cur = 0, ans = 0;
    auto dfs = [&](this auto &&self, int u) -> u64 {
      if (!val[u]) return xval[u];
      u64 x = self(l[u]), y = self(r[u]);
      cur += x * y * val[u];
      return x + y;
    };
    for (int i = 1; i <= tot; i++) {
      if (pa[i] == i) {
        cur = 0;
        dfs(i);
        ans ^= cur;
      }
    }
    return ans;
  };
  auto s1 = work(e1), s2 = work(e2);
  std::cout << (s1 == s2 ? "YES" : "NO") << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}