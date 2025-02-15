// date: 2025-01-31 17:50:11
// tag: 总体来说比较少见的小值域的dp，还是期望dp，由于值域比较小所以可以直接O(nV)了，
// 还是很好写的，就是要滚动数组这点有点坑，也确实空间O(nV)还是有些吃紧了
// 这种题logV估计也挺难的，但是？可以吗，如果题目改成或然后改成平方的期望，得，新题目来源于看错题
// 小值域期望dp，也是十分套路的按照当前已经放了的，然后由于结果可以直接合并，所以可以直接按值转移，而不用像状压那样只能根据一定的条件转移

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

constexpr int qpow(int a, int b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
constexpr int inv(int x) {return qpow(x, mod - 2);}
constexpr int N = 1024;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), p(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i];
    p[i] = (long long)p[i] * inv(10000) % mod;
  }
  std::vector<std::vector<int>> f(2, std::vector<int>(N));
  f[0][0] = 1;
  int cur = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < N; j++) {
      f[cur][j] = f[cur ^ 1][j ^ a[i]] * p[i] % mod + f[cur ^ 1][j] * ((1 - p[i] + mod) % mod) % mod;
      f[cur][j] %= mod;
    }
    cur ^= 1;
  }
  cur ^= 1;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans += i * i * f[cur][i] % mod;
    ans %= mod;
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