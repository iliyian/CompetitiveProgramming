// 思维题
// wa#01: 1 << i 不会自动变成 i 的类型ull
// wa#02: 带减法的模忘了处理负数情况
// wa#03: 编译环境导致的wa，由gnu c++17换成gnu c++20即可，
//        本地gcc v13.1.0 可过原本oj上错误的数据

#include <bits/stdc++.h>
#define mod 1000000007
#define int unsigned long long
using namespace std;

int calc(int x) {
  if (x < 4) return 0;
  int ans = 0;
  for (int i = 2; i <= 60; i++) {
    // 遍历每个 f 变化的区间，不可越界
    int l = 1ull << i, r = min(x, (1ull << i + 1) - 1);
    if (l > x) break;
    for (int j = 1, base = i; j <= 60; j++, base *= i) {
      // base: i^n, [base,base*i-1]
      if (base * i < l) continue;
      if (base > r) break;
      int nl = max(l, base), nr = min(r, base * i - 1);
      // 可能 base很小，base * i - 1 也很小
      if (nl > nr) continue;
      // j即g或说z，但似乎有很大优化空间
      ans += (nr - nl + 1) % mod * j % mod;
      ans %= mod;
    }
  }
  return ans;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int t; cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int ans = (calc(r) - calc(l - 1) + mod) % mod;
    cout << ans << '\n';
  }
  return 0;
}