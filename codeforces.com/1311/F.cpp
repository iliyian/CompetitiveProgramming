// date: 2024-08-03 11:40:05
// tag: 树状数组

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  std::vector<int> v;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].second;
    v.push_back(a[i].second);
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first;
  }
  std::sort(a.begin() + 1, a.end(), std::greater());
  std::sort(v.begin(), v.end());
  auto id = [&](int x) {
    return std::lower_bound(v.begin(), v.end(), x) - v.begin();
  };
  std::vector<int> d(n + 1), cnt(n + 1);
  auto addd = [&](int x, int c) {
    for (int i = x; i <= n; i += i & -i) {
      d[i] += c;
    }
  };
  auto addc = [&](int x, int c) {
    for (int i = x; i <= n; i += i & -i) {
      cnt[i] += c;
    }
  };
  auto queryd = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
      ans += d[i];
    }
    return ans;
  };
  auto queryc = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
      ans += cnt[i];
    }
    return ans;
  };
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    auto [v, x] = a[i];
    ans += (queryd(n) - queryd(id(x) + 1)) - (queryc(n) - queryc(id(x) + 1)) * x;
    addd(id(x) + 1, x);
    addc(id(x) + 1, 1);
  }
  std::cout << ans << '\n';

  return 0;
}