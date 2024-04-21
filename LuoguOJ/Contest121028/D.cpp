#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int n, c, ans = 0x7fffffff, maxa = -1, k;
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    maxa = max(maxa, a);
    int cur = maxa + c * (n - i - 1);
    if (cur < ans) {
      ans = cur, k = i + 1;
    }
  }
  if (c * n < ans) {
    cout << 0 << ' ' << c * n;
  } else cout << k << ' ' << ans;
  return 0;
}