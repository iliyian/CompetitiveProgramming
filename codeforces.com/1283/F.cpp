// date: 2024-08-03 09:25:40
// tag: 构造，树

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), in(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    std::cin >> a[i];
    in[a[i]]++;
  }
  std::priority_queue<int, std::vector<int>, std::greater<>> q;
  for (int i = 1; i <= n; i++) {
    if (!in[i]) {
      q.push(i);
    }
  }
  std::vector<std::pair<int, int>> g;
  for (int i = n - 1; i >= 1; i--) {
    int u = q.top(); q.pop();
    g.push_back({u, a[i]});
    if (!--in[a[i]]) q.push(a[i]);
  }
  std::cout << a[1] << '\n';
  for (auto [x, y] : g) {
    std::cout << x << ' ' << y << '\n';
  }

  return 0;
}