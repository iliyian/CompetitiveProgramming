// date: 2024-07-15 15:02:59
// tag: 折半搜索

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
// using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n, k, s;
  std::cin >> n >> k >> s;
  std::vector<int> a(n + 1), A(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    A[i] = 1;
    for (int j = 2; j <= a[i]; j++) {
      A[i] *= j;
      if (A[i] > inf) {
        A[i] = inf;
        break;
      }
    }
  }

  int ans = 0, mid = n >> 1;
  std::map<std::pair<int, int>, int> mp;
  // std::map<int, int> mp;
  std::set<int> vis;
  auto dfs = [&](auto self, int u, int cnt, int sum, int ed) {
    if (u == ed + 1) {
      if (ed == mid) {
        mp[{cnt, sum}]++;
        vis.insert(sum);
      } else if (ed == n && vis.count(s - sum)) {
        // ans += mp[{k - cnt, s - sum}];
        for (int i = 0; i <= k - cnt; i++) {
          ans += mp[{i, s - sum}];
        }
      }
      return;
    }
    if (cnt < k && sum + A[u] <= s) {
      self(self, u + 1, cnt + 1, sum + A[u], ed);
    }
    if (sum + a[u] <= s) {
      self(self, u + 1, cnt, sum + a[u], ed);
    }
    self(self, u + 1, cnt, sum, ed);
  };

  dfs(dfs, 1, 0, 0, mid);
  dfs(dfs, mid + 1, 0, 0, n);

  std::cout << ans << '\n';

  return 0;
}