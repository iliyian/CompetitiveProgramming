// date: 2025-09-17 17:58:32
// tag: 
// tmd题解实在是太抽象了，对于奇数，就是在全部设置好加减号后，把前(n+1)/2个减号取消一个或者后(n+1)/2个加号取消一个的事情
// 不过这种+=\sum{r}，然后-=\part{r-l}的做法，确实好像应该是很常见的？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first >> a[i].second;
    sum += a[i].second + a[i].second - a[i].first;
  }
  std::sort(a.begin() + 1, a.end(), [&](auto x, auto y) {
    return x.first + x.second < y.first + y.second;
  });
  if (n % 2 == 0) {
    for (int i = 1; i <= n / 2; i++) {
      sum -= a[i].first + a[i].second;
    }
    std::cout << sum << '\n';
  } else {
    int ans = 0;
    for (int i = 1; i <= n / 2 + 1; i++) {
      sum -= a[i].first + a[i].second;
    }
    for (int i = 1; i <= n / 2 + 1; i++) {
      ans = std::max(ans, sum + a[i].first);
    }
    sum += a[(n + 1) / 2].first + a[(n + 1) / 2].second;
    for (int i = (n + 1) / 2; i <= n; i++) {
      ans = std::max(ans, sum - a[i].second);
    }
    std::cout << ans << '\n';
  }
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