// date: 2024-03-03 20:26:13
// tag: 欧拉函数，关键在于求和符号的上界和gcd可以同时改变，
// 关键在于和欧拉函数扯上关系

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


  vector<bool> vis(n + 1);
  vector<int> pri, phi(n + 1), s(n + 1);
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      pri.push_back(i);
      phi[i] = i - 1;
    }
    for (int p : pri) {
      if (i * p > n) break;
      vis[i * p] = true;
      if (i % p == 0) {
        phi[i * p] = p * phi[i];
        break;
      }
      phi[i * p] = phi[p] * phi[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    phi[i] += phi[i - 1];
  }

  int ans = 0;
  for (int p : pri) {
    ans += 2 * phi[n / p] - 1;
  }
  cout << ans << '\n';

  return 0;
}