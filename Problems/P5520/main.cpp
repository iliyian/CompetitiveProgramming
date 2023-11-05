// 经典插空法

#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, n, m, mod;

int A(int n, int m) {
  int ans = 1;
  for (int i = n; i >= n - m + 1; i--)
    ans *= i % mod, ans %= mod;
  return ans;
}

signed main() {
  cin >> t >> n >> m >> mod;
  cout << A(n - m + 1, m) % mod << '\n';
  return 0;
}