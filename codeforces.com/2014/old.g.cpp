// date: 2025-03-20 18:26:27
// tag: 总之很神奇，很难实现的小模拟，jiangly真nb，变量状态多了是真的特别容易搞混

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> d(n + 2), a(n + 2);
  d[n + 1] = LLONG_MAX / 3;
  for (int i = 1; i <= n; i++) {
    std::cin >> d[i] >> a[i];
  }
  std::stack<std::pair<int, int>> s;
  int cd = d[1], ans = 0;
  for (int i = 1; i <= n; i++) {
    s.push({d[i], a[i]});
    cd = d[i];
    while (!s.empty() && cd <= d[i + 1] - 1) {
      auto &[pd, pa] = s.top();
      if (pd + k - 1 < cd) {
        s.pop();
        continue;
      }; // 过期
      if (pa < m) {
        int sum = 0;
        while (!s.empty()) {
          auto &[_pd, _pa] = s.top();
          if (_pd + k - 1 < cd) {
            s.pop();
            continue;
          }
          if (sum + _pa >= m) {
            cd++;
            _pa -= m - sum;
            ans++;
            break;
          } else {
            sum += _pa;
            s.pop();
          }
        }
      } else {
        int rd = std::min({pd + k - 1, d[i + 1] - 1, cd + pa / m - 1});
        ans += rd - cd + 1;
        pa -= (rd - cd + 1) * m;
        cd = rd + 1;
      }
    }
  }
  std::cout << ans << '\n';
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