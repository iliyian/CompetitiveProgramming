#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int k;
  cin >> k;
  vector<int> a(k + 1), pre(k + 1, 0);
  int sum = 0;
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
  }
  int n, m, x;
  cin >> n >> m >> x;
  x %= m;
  for (int i = 1; i <= k; i++) {
    a[i] %= m;
    pre[i] = pre[i - 1] + a[i];

  }
  int bn = pre[k] * (n / k) + pre[n % k] + x;
  int ans = n;
  // cerr << bn <<" ";
  ans = ans - bn / m;
  cout << ans <<"\n"; 
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