#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  long long A, B;
  cin >> A >> B;
  vector<long long> all;
  auto dfs = [&](auto self, int cur, int x) {
    if (cur == 11) return;
    if (x) {
      all.push_back(x);
    }
    self(self, cur + 1, x * 10 + 6);
    self(self, cur + 1, x * 10 + 8);
  };
  dfs(dfs, 0, 0);

  sort(all.begin(), all.end(), greater());
  
  vector<long long> nums;
  for (int i = 0; i < all.size(); i++) {
    bool f = false;
    for (int j = i + 1; j < all.size(); j++) {
      if (all[i] % all[j] == 0) {
        f = true;
        break;
      }
    }
    if (!f) {
      nums.push_back(all[i]);
    }
  }

  vector<int> a;
  int ans = 0;
  auto dfs2 = [&](auto self, int cur, __int128_t lc) -> void {
    if (a.size()) {
      ans += (floor(double(B) / lc) - ceil(double(A) / lc) + 1)
        * (a.size() & 1 ? 1 : -1);
    }
    for (int i = cur + 1; i < nums.size(); i++) {
      bool f = true;

      __int128_t nlc = lcm(lc, __int128_t(all[i]));
      if (nlc > B) continue;

      a.push_back(all[i]);
      self(self, i, nlc);
      a.pop_back();
    }
  };
  dfs2(dfs2, -1, 1);
  cout << ans << '\n';

  return 0;
}