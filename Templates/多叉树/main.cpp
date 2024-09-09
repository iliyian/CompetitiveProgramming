// date: 2024-08-24 13:28:45
// tag: 树状数组维护多叉树的树上逆序对
// [k*(x-1)+2, k*x+1]

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> ans(n + 1);
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first;
    a[i].second = i;
  }
  std::sort(a.begin() + 1, a.end());
  std::vector<int> d(n + 1);
  auto add = [&](int x, int c) {
    for (int i = x; i <= n; i += i & -i) d[i] += c;
  };
  auto query = [&](int x) -> int {
    if (x == 0) return 0;
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += d[i];
    return ans;
  };
  for (int i = 1; i <= n; i++) {
    for (int k = 1; k <= n - 1; k++) {
      int l = k * (a[i].second - 1) + 2, r = k * a[i].second + 1;
      if (l > n) break;
      ans[k] += query(std::min(n, r)) - query(l - 1);
    }
    add(a[i].second, 1);
  }
  for (int i = 1; i <= n - 1; i++) {
    std::cout << ans[i] << " \n"[i == n - 1];
  }

  return 0;
}