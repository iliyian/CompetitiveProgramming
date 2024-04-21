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
  int li = lower_bound(nums.begin(), nums.end(), l) - nums.begin(),
    ri = upper_bound(nums.begin(), nums.end(), r) - nums.begin() - 1;
  set<int> ans;
  for (int i = li; i <= ri; i++) {
    ans.insert(nums[i]);
    for (int j = 1; j * nums[i] <= r; j++) {
      ans.insert(j * nums[i]);
    }
  }
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
  cout << ans.size();

  return 0;
}