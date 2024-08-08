// date: 2024-07-31 14:01:26
// tag: 二分

#include <bits/stdc++.h>
#define N ((int)2e5)
// #define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n, Q;
  std::cin >> n >> Q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  std::vector<int> mx(n + 1);

  std::vector<int> d(N + 5);
  auto add = [&](int x, int c) {
    for (int i = x; i <= N; i += i & -i) d[i] += c;
  };
  auto query = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
      ans += d[i];
    }
    return ans;
  };

  for (int i = 1; i <= n; i++) {
    int l = 1, r = n, ans = n + 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (query(mid) / mid + 1 <= a[i]) {
        r = mid - 1, ans = mid;
      } else {
        l = mid + 1;
      }
    }
    add(ans, 1);
    mx[i] = ans;
  }

  while (Q--) {
    int i, x;
    std::cin >> i >> x;
    std::cout << (x >= mx[i] ? "YES" : "NO") << '\n';
  }


  return 0;
}