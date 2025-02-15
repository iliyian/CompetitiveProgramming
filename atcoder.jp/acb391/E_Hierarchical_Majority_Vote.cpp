// date: 2025-02-02 21:53:21
// tag: 少见的递归解题，以及常见的没有证明的思路是正确的但是实现是错误的导致以为思路是错误的
// 总之还是结构很好，刚好是某个数的某次幂，就几乎很明显的提示要递归了，就像分治也是递归，只不过如果长度不是2的若干次幂就不会很明显
// 实在要证明的话大概可以从子结构入手？毕竟有点像dp，从底向上的dp

#include <bits/stdc++.h>
#define int long long

std::string str;
int n;

std::pair<int, int> get(int l, int r) {
  if (r == l + 1) return {str[l] == '1', 1};
  int len = (r - l) / 3;
  auto a = get(l, l + len), b = get(l + len, l + len * 2), c = get(l + len * 2, l + len * 3);
  int cnt = a.first + b.first + c.first;
  if (a.first == b.first && b.first == c.first) {
    int mx = std::max({a.second, b.second, c.second}), sum = a.second + b.second + c.second;
    return {cnt >= 2, sum - mx};
  }
  if (a.first != b.first && a.first != c.first) {
    return {cnt >= 2, std::min(b.second, c.second)};
  }
  if (a.first == c.first) {
    assert(a.first != b.first);
    std::swap(b, c);
  }
  return {cnt >= 2, std::min(a.second, b.second)};
}

void solve() {
  std::cin >> n;
  std::cin >> str;
  n = pow(3, n);
  std::cout << get(0, n).second << '\n';
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