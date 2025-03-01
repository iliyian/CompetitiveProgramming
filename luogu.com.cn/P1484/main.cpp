// date: 2024-08-13 09:26:13
// tag: 反悔贪心

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 2), l(n + 2), r(n + 2), vis(n + 2);
  std::priority_queue<std::pair<int, int>> q;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    q.push({a[i], i});
    l[i] = i - 1, r[i] = i + 1;
  }
  r[0] = 1, l[n + 1] = n;
  int sum = 0, ans = 0;
  for (int i = 1; i <= k; i++) {
    while (!q.empty() && vis[q.top().second]) q.pop();
    if (q.empty()) break;
    auto [x, id] = q.top(); q.pop();
    sum += x;
    a[id] = a[l[id]] + a[r[id]] - x;
    q.push({a[id], id});
    vis[l[id]] = vis[r[id]] = true;
    l[id] = l[l[id]], r[id] = r[r[id]];
    r[l[id]] = id, l[r[id]] = id;
    ans = std::max(ans, sum);
  }
  std::cout << ans << '\n';

  return 0;
}