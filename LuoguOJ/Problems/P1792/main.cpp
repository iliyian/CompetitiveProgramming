// date: 2024-08-13 09:34:30
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
  std::vector<int> a(n + 1), l(n + 1), r(n + 1), vis(n + 1);
  std::priority_queue<std::pair<int, int>> q;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    q.push({a[i], i});
    l[i] = i - 1, r[i] = i + 1;
  }
  l[1] = n, r[n] = 1;
  if (k > n / 2) {
    std::cout << "Error!\n";
    return 0;
  }
  int sum = 0;
  for (int i = 1; i <= k; i++) {
    while (!q.empty() && vis[q.top().second]) q.pop();
    auto [x, id] = q.top(); q.pop();
    sum += x;
    a[id] = a[l[id]] + a[r[id]] - x;
    q.push({a[id], id});
    vis[l[id]] = vis[r[id]] = true;
    l[id] = l[l[id]], r[id] = r[r[id]];
    r[l[id]] = id, l[r[id]] = id;
  }
  std::cout << sum << '\n';

  return 0;
}