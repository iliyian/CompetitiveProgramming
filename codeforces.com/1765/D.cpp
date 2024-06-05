// date: 2024-06-05 23:50:08
// tag: 双指针

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin() + 1, a.end());
  int ans = sum + n;
  int l = 1, r = n;
  while (l < r) {
    if (a[l] + a[r] <= m) {
      l++, r--; // as for a[l]+a[r]<=m, so a[l]+a[r-1]<=m, so 2
      ans -= 2;
    }
    else r--;
  }
  cout << (ans + (l > r)) << '\n';
  
  return 0;
}