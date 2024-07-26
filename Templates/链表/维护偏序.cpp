// date: 2024-07-26 11:44:00
// tag: 链表维护偏序关系，组合数

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int mod = 998244353;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> l(m + 1), r(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> l[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> r[i];
  }
  std::vector<int> L(n + 2), R(n + 2);
  R[n] = n + 1;
  L[n + 1] = n;
  R[0] = n;
  L[n] = 0;

  for (int i = 1; i <= m; i++) {
    int x = l[i], y = r[i];
    if (x < y) {
      L[x] = L[y];
      R[L[x]] = x;
      L[y] = x;
      R[x] = y;
    } else {
      R[y] = R[x];
      L[R[y]] = y;
      R[x] = y;
      L[y] = x;
    }
  }
  std::vector<int> sp;
  std::vector<int> vis(n + 1);
  for (int i = R[0]; i != n + 1; i = R[i]) {
    if (vis[i]) {
      std::cout << 0 << '\n';
      return 0;
    }
    sp.push_back(i);
    vis[i] = true;
  }
  std::vector<int> rule(n + 1);
  rule[sp.front()]++, rule[sp.back()]++;
  for (int i = 1; i < sp.size(); i++) {
    rule[std::max(sp[i], sp[i - 1])]++;
  }
  int cnt = 0, ans = 1;
  for (int i = n; i >= 1; i--) {
    if (!vis[i]) {
      ans = ans * cnt % mod;
      cnt++;
    }
    cnt += rule[i];
  }
  std::cout << ans << '\n';

  return 0;
}