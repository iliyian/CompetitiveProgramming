#include <algorithm>
#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1), v;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] -= k;
    a[i] += a[i - 1];
    v.push_back(a[i]);
  }
  v.push_back(0);
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  auto id = [&](int x) {
    return std::lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
  };
  int len = v.size();
  std::vector<int> d(len + 1);
  auto add = [&](int x) {
    for (int i = x; i <= len; i += i & -i) d[i]++;
  };
  auto query = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += d[i];
    return ans;
  };
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += query(id(a[i]));
    add(id(a[i]));
  }
  std::cout << ans << '\n';

  return 0;
}