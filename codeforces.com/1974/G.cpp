// date: 2024-07-29 16:03:01
// tag: 反悔贪心

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int m, x;
  std::cin >> m >> x;
  std::vector<std::pair<int, int>> a(m + 1);
  std::vector<int> d(m + 5);

  for (int i = 1; i <= m; i++) {
    std::cin >> a[i].first;
    a[i].second = i;
  }
  int sum = 0;
  std::priority_queue<int> q;
  for (int i = 1; i <= m; i++) {
    sum -= a[i].first;
    q.push(a[i].first);
    if (sum < 0) {
      sum += q.top();
      q.pop();
    }
    sum += x;
  }
  std::cout << q.size() << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}