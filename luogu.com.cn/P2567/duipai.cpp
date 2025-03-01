#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("duipai.out", "w", stdout);

  int l, r;
  cin >> l >> r;
  vector<int> nums;
  auto dfs = [&](auto self, int cur, int x) {
    if (cur == 10) return;
    if (x) {
      nums.push_back(x);
    }
    self(self, cur + 1, x * 10 + 6);
    self(self, cur + 1, x * 10 + 8);
  };
  dfs(dfs, 0, 0);
  sort(nums.begin(), nums.end());
  vector<int> ans;
  for (int i = l; i <= r; i++) {
    for (int j : nums) {
      if (j > i) break;
      if (i % j == 0) {
        ans.push_back(i);
        break;
      }
    }
  }
  
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
  cout << ans.size();

  return 0;
}