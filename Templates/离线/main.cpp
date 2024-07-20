// date: 2024-07-16 11:53:08
// tag: 离线处理，树状数组

#include <bits/stdc++.h>
#define int long long
#define N ((int)3e5)
// using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  std::vector<std::array<int, 3>> ask(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> ask[i][0] >> ask[i][1];
    ask[i][2] = i;
  }
  std::sort(ask.begin() + 1, ask.end(), [&](const std::array<int, 3> &x, const std::array<int, 3> &y) {
    return x[1] < y[1];
  });

  std::vector<int> id(n + 1);
  std::iota(id.begin() + 1, id.end(), 1);
  std::sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
    return a[x] < a[y];
  });

  std::vector<std::pair<int, int>> pairs;
  for (int i = 2; i <= n - 1; i++) {
    int ld = a[id[i]] - a[id[i - 1]], rd = a[id[i + 1]] - a[id[i]];
    int d = std::min(ld, rd);
    if (ld == d) {
      pairs.push_back({id[i], id[i - 1]});
    }
    if (rd == d) {
      pairs.push_back({id[i], id[i + 1]});
    }
  }
  pairs.push_back({id[1], id[2]});
  pairs.push_back({id[n], id[n - 1]});
  for (auto &p : pairs) {
    if (p.first > p.second) {
      std::swap(p.first, p.second);
    }
  }

  std::sort(pairs.begin(), pairs.end(), [&](const std::pair<int, int> &x, const std::pair<int, int> &y) {
    return x.second < y.second;
  });

  std::vector<int> d(N + 5);
  auto add = [&](int x) {
    for (int i = x; i <= n; i += i & -i) {
      d[i]++;
    }
  };

  auto query = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
      ans += d[i];
    }
    return ans;
  };

  if (n == 1) {
    std::cout << 0 << '\n';
    return 0;
  }

  int ans = 0, cur = 0, cnt = 0;
  for (int i = 1; i < ask.size(); i++) {
    auto [l, r, t] = ask[i];
    while (cur < pairs.size() && pairs[cur].second <= r) {
      add(pairs[cur].first);
      cur++;
    }
    ans += t * (cur - query(l - 1));
  }
  std::cout << ans << '\n';
  return 0;
}