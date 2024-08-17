// date: 2024-08-12 21:25:24
// tag: 反悔贪心

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;
  std::priority_queue<int> q;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first >> a[i].second;
  }
  std::sort(a.begin() + 1, a.end());
  int cur = 0, cnt = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    auto [x, t] = a[i];
    cur += x - a[i - 1].first + t;
    cnt++;
    q.push(t);
    while (!q.empty() && cur > m) {
      cur -= q.top(); q.pop();
      cnt--;
    }
    if (cur > m) {
      break;
    }
    ans = std::max(ans, cnt);
  }
  std::cout << ans << '\n';

  return 0;
}