#include <bits/stdc++.h>
#define int long long

struct Node {
  int idx, v;
  bool operator < (const Node &b) const {
    return v > b.v;
  }
};

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;

  for (int i = 2; i <= n; i++) {
    int j = i;
    while (j >= 2 && str[j] > str[j - 1] + 1) {
      std::swap(str[j], str[j - 1]);
      j--;
      str[j]--;
    }
  }
  std::cout << str.substr(1, str.size() - 1) << '\n';
  return;

  std::vector<int> p(n + 1), a(n + 1);
  std::iota(p.begin(), p.end(), 0);
  for (int i = 1; i <= n; i++) {
    a[i] = str[i] - '0' - i;
  }
  std::stable_sort(p.begin() + 1, p.end(), [&](const int &x, const int &y) {
    return std::tie(a[x], str[x]) > std::tie(a[y], str[y]);
  });
  std::vector<int> d(n + 1);
  auto add = [&](int x) {
    for (int i = x; i <= n; i += i & -i) d[i]++;
  };
  auto query = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += d[i];
    return ans;
  };
  for (int i = 1; i <= n; i++) {
    // std::cout << p[i] << ' ' << p[i] + i - 1 - query(p[i]) << '\n';
    // std::cout << char(str[p[i]] - std::max(0ll, p[i] + i - 1 - query(p[i]) - i));
    std::cout << char(str[p[i]] - std::max(0ll, p[i] - i));
    add(p[i]);
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}