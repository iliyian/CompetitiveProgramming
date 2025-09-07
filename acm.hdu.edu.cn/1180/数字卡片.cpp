#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
  int a[11];
  for(int i = 0; i < 10; i++)
    cin >> a[i];
  int ans = 0;
  int cnt1 = a[1] + a[3] + a[5] + a[7];
  int cnt2 = a[2];
  ans = a[0] + a[4] + a[8];
  int tot = a[6] + a[9];
  int d = cnt1 - cnt2; d = abs(d);
  if(d <= tot) ans += (max(cnt1,cnt2) + (tot - d) / 2);
  else ans += (max(cnt1,cnt2) - (d - tot));
  cout << ans << '\n';
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