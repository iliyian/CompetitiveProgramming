// date: 2024-07-16 12:19:26
// tag: 贪心

#include <bits/stdc++.h>
#define int long long
// using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first >> a[i].second;
  }
  std::sort(a.begin() + 1, a.end(), [&](const std::pair<int, int> &x, const std::pair<int, int> &y) {
    return x.second < y.second;
  });

  std::priority_queue<std::pair<int, int>> q;
  int cur = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    cur += a[i].first;
    q.push(a[i]);
    if (cur > a[i].second) {
      auto u = q.top(); q.pop();
      cur -= u.first;
    } else {
      ans++;
    }
  }
  std::cout << ans << '\n';

  return 0;
}