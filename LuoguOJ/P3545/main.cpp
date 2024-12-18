// date: 2024-08-12 21:39:06
// tag: 反悔贪心

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  std::priority_queue<std::pair<int, int>> q;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  int cnt = 0, ans = 0, cur = 0;
  std::vector<int> ok(n + 1);
  for (int i = 1; i <= n; i++) {
    cur += a[i];
    while (!q.empty() && cur < b[i] && q.top().first > b[i]) {
      cur += q.top().first;
      ok[q.top().second] = false;
      q.pop();
      cnt--;
    }
    if (cur >= b[i]) {
      cur -= b[i];
      ok[i] = true;
      q.push({b[i], i});
      cnt++;
    }
    ans = std::max(ans, cnt);
  }
  std::cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    if (ok[i]) {
      std::cout << i << ' ';
    }
  }
  std::cout << '\n';

  return 0;
}