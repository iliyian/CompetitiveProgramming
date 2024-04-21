// date: 2024-03-14 00:49:27
// tag: basis,线性基为什么英文名这么奇怪，最大异或和
// wa#01: 遍历更新答案的时候从低位到高位了导致不够贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1), p(64);
  auto check = [&](int x) {
    for (int i = 62; i >= 0; i--) {
      if ((x >> i) & 1) {
        if (p[i]) {
          x ^= p[i];
        } else {
          p[i] = x;
          return;
        }
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    check(a[i]);
  }

  int ans = 0;
  for (int i = 62; i >= 0; i--) {
    ans = max(ans, ans ^ p[i]);
  }
  cout << ans << '\n';

  return 0;
}