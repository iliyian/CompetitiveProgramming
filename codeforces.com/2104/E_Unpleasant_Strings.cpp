#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  int q;
  std::cin >> q;
  std::vector<std::vector<int>> pos(k);
  for (int i = 1; i <= n; i++) {
    pos[str[i] - 'a'].push_back(i);
  }
  std::set<int> s;
  std::vector<int> ans(n + 2, 1);
  for (int i = n; i >= 1; i--) {
    ans[i] = ans[i + 1];
    if (s.size() == k) {
      ans[i]++;
      s.clear();
    }
    s.insert(str[i] - 'a');
  }
  while (q--) {
    std::string t;
    std::cin >> t;
    int p = 0;
    std::vector<int> q(k);
    for (auto c : t) {
      // auto q = std::upper_bound(pos[c - 'a'].begin(), pos[c - 'a'].end(), p) - pos[c - 'a'].begin();
      while (q[c - 'a'] < pos[c - 'a'].size() && pos[c - 'a'][q[c - 'a']] <= p) q[c - 'a']++;
      if (q[c - 'a'] < pos[c - 'a'].size()) {
        p = pos[c - 'a'][q[c - 'a']];
      } else {
        std::cout << 0 << '\n';
        goto end;
      }
    }
    // while (1) {
    //   ans++;
    //   int mx = p;
    //   for (int i = 0; i < k; i++) {
    //     // auto q = std::upper_bound(pos[i].begin(), pos[i].end(), p) - pos[i].begin();
    //     while (q[i] < pos[i].size() && pos[i][q[i]] <= p) q[i]++;
    //     if (q[i] == pos[i].size()) {
    //       goto end2;
    //     }
    //     mx = std::max(mx, pos[i][q[i]]);
    //   }
    //   p = mx;
    // }
    // end2:
    std::cout << ans[p] << '\n';
    end:
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}