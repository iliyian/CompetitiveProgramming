// date: 2024-08-11 12:09:25
// tag: 中位数，分类讨论，值域二分

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::pair<int, int>> a(n + 1);
  int sum = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first;
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].second;
    if (a[i].second) {
      sum += a[i].first, cnt++;
    }
  }
  std::sort(a.begin() + 1, a.end());
  int ans = 0;
  int mid = (n + 1) / 2;
  for (int i = 1; i <= n; i++) {
    if (a[i].second) {
      ans = std::max(ans, a[i].first + k + a[(n & 1 ? (i < mid ? mid : mid - 1) : (i <= mid ? mid + 1 : mid))].first);
    }
  }
  auto get = [&](int m) {
    int cnt = 0;
    std::vector<int> vec;
    for (int i = 1; i < n; i++) {
      if (a[i].first >= m) {
        cnt++;
      } else if (a[i].second) {
        vec.push_back(m - a[i].first);
      }
    }
    int kk = k;
    for (auto &x : vec | std::views::reverse) {
      if (kk >= x) { 
        kk -= x;
        cnt++;
      }
    };
    return cnt;
  };
  int l = 0, r = 2e9 + 5, med = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (get(m) >= (n + 1) / 2) l = m + 1, med = m;
    else r = m - 1;
  }
  std::cout << std::max(ans, med + a.back().first) << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}