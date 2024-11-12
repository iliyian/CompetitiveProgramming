#include <bits/stdc++.h>
#include <queue>
#define int long long
using namespace std;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), x(m + 1), t(m + 1);
  // std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
  std::priority_queue<int, std::vector<int>, std::greater<>> q;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  auto raw = a;
  for (int i = 1; i <= m; i++) {
    std::cin >> x[i] >> t[i];
  }
  std::vector<int> nxt(m + 1), pos(n + 1);
  for (int i = 1; i <= m; i++) {
    nxt[pos[t[i]]] = i;
    if (!pos[t[i]]) {
      q.push(i);
    }
    pos[t[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (!pos[i]) {
      q.push({});
    }
  }
  for (int i = 1; i <= m; i++) {
    std::cout << nxt[i] << " \n"[i == m];
  }
  int k = 1, ans = 0;
  while (!q.empty()) {
    auto [pos, id] = q.top(); q.pop();
    if (k <= m && x[k] - ans <= a[id]) {
      ans = x[k];
      a[t[pos]] = raw[t[pos]];
      q.push(nxt[pos]);
      if (a[t[pos]] != a[k]) {
        q.push(k);
      }
      k++;
    } else {
      ans += a[t[pos]];
      a[t[pos]] = 0;
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}