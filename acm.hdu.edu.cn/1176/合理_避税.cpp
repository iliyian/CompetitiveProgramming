#include <bits/stdc++.h>
#define ll long long
#define int ll
#define N 400005
using namespace std;
int n, m, p, k, a[N], b[N];
bool cmp(int x, int y) { return x > y; }
bool check(int x) {
  if (x * p * k < m)
    return 0;
  int c = 0, tot = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    int d = a[i] / k;
    if (d >= x)
      tot += x;
    else {
      tot += d;
      if (a[i] % k)
        b[++cnt] = a[i] % k;
    }
    if (tot >= x * p) {
      tot = x * p;
      if (tot * k >= m)
        return 1;
      else
        return 0;
    }
    if (tot * k >= m)
      return 1;
  }
  //    cout<<x<<' '<<tot<<' '<<cnt<<endl;
  sort(b + 1, b + cnt + 1, cmp);
  c = tot * k;
  for (int i = 1; i <= cnt; i++) {
    //        cout<<'!'<<b[i]<<endl;
    tot++;
    c += b[i];
    if (c >= m)
      return 1;
    if (tot >= x * p)
      return 0;
  }
  return 0;
}
void solve() {
  cin >> n >> m >> k >> p;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1, cmp);
  //    for (int i=1;i<=n;i++)cout<<a[i]<<' '<<endl;
  int l = 1, r = 1000000050, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--)
    solve();
  return 0;
}