#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

void solve(int n) {
  vector<int> f(n + 2);
  auto dfs = [&](auto self, int sum) -> int {
    if (sum <= 2) return 1;
    if (f[sum]) return f[sum] % mod;
    int ans = 0;
    // for (int t = 2; t <= )
    for (int i = 1; i <= sum / 2; i++) {
      ans += self(self, i) * self(self, sum - i) % mod;
      ans %= mod;
    }
    return f[sum] = ans;
  };
  cout << dfs(dfs, n + 1) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.old.out", "w", stdout);

  for (int i = 1; i <= 1000; i++) {
    solve(i);
  }

  return 0;
}