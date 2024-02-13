// date: 2024/02/12 22:42:17
// tag: wa#01: 没有考虑到因子是(k-1)而不是k，需要特殊处理
// (n+x)/2=(k-1)t+k -> (n+x)/2-1=(k-1)(t-1) x<=k+1
// (n-x)/2=(k-1)t x<=k

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  if ((n + x) % 2 != 0) {
    cout << 0 << '\n';
    return;
  }
  int d = (n - x) / 2, ans = 0;
  for (int k = 1; k * k <= d; k++) {
    if (d % k != 0) {
      continue;
    }
    ans += (x < k + 1);
    // 另外半边
    if (k * k != d) {
      ans += (x < d / k + 1);
    }
  }
  int e = (n + x) / 2 - 1;
  if (x > 1) {
    for (int k = 1; k * k <= e; k++) {
      if (e % k != 0) {
        continue;
      }
      ans += (x <= k + 1);
      if (k * k != e) {
        ans += (x <= e / k + 1);
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}