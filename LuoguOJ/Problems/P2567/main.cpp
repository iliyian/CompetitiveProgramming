// date: 2024-05-29 22:53:28
// tag: 容斥，搜索

#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

// no special handle
int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int A, B;
  cin >> A >> B;
  vector<int> all;
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
  
  vector<int> nums;
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

  int ans = 0;

  for (int i = 0; nums[i] * 3 > B; i++) {
    if (nums[i] < A) break;
    ans += (nums[i] <= B);
  }

  auto dfs2 = [&](auto self, int dep, int lc, int cnt, bool f) -> void {
    if (cnt > 0 && f) {
      ans += (floor(double(B) / lc) - ceil(double(A) / lc) + 1)
        * (cnt & 1 ? 1 : -1);
    }
    if (dep >= nums.size()) return;
    self(self, dep + 1, lc, cnt, false);
    int nlc = lcm(lc, nums[dep]);
    if (nums[dep] * 3 <= B && nlc <= B) {
      self(self, dep + 1, nlc, cnt + 1, true);
    }
  };
  dfs2(dfs2, 0, 1, 0, false);
  cout << ans << '\n';

  return 0;
}