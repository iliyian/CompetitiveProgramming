// date: 2024-07-30 12:42:06
// tag: 常见的区间贡献和mx，mn

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> mx(21, std::vector<int>(n + 1));
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    ans += (i - 1) * (n - i + 1);
    mx[0][i] = a[i];
  }
  for (int j = 1; j <= 20; j++) {
    for (int i = 0; i + (1 << (j - 1)) <= n; i++) {
      mx[j][i] = std::max(mx[j - 1][i], mx[j - 1][i + (1 << (j - 1))]);
    }
  }
  auto query = [&](int l, int r) {
    int len = std::__lg(r - l + 1);
    return std::max(mx[len][l], mx[len][r - (1 << len) + 1]);
  };
  std::vector<int> ll(n + 2), rl(n + 2);
  std::stack<int> s;
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] > a[i]) {
      s.pop();
    }
    ll[i] = (s.empty() ? 0 : s.top());
    s.push(i);
  }
  while (!s.empty()) {
    s.pop();
  }
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] > a[i]) {
      s.pop();
    }
    rl[i] = (s.empty() ? n + 1 : s.top());
    s.push(i);
  }
  for (int i = 1; i <= n; i++) {
    int l = 0, r = ll[i] - 1, k = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (query(mid, ll[i] - 1) > a[i]) l = mid + 1, k = mid;
      else r = mid - 1;
    }
    ans -= (ll[i] - k) * (rl[i] - i);
  }
  std::cout << ans << '\n';
  // for (int i = 1; i <= n; i++) {
  //   std::cout << l[i] << " \n"[i == n];
  // }
  // for (int i = 1; i <= n; i++) {
  //   std::cout << r[i] << " \n"[i == n];
  // }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D1.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}