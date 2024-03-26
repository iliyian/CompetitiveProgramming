#include <bits/stdc++.h>
#define int long long
#define N 1000006
using namespace std;

int n, p, a[N];

__int128 check(int mid) {
  __int128 ans = mid * p;
  for (int i = 1; i <= n; i++) {
    ans += 2 * abs(mid - a[i]);
  }
  return ans;
}

void solve() {
  cin >> n >> p;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  int ans = a[1], dis = 0;
  for (int i = 1; i <= n; i++) {
    dis += 2 * abs(a[i] - ans);
  }
  int mn = dis;
  for (int i = 2; i <= n; i++) {
    dis -= (n - i) * (a[i] - a[i - 1]);
    dis += (i - 1) * (a[i] - a[i - 1]);
    dis -= p * a[i - 1];
    dis += p * a[i];
    if (dis < mn) {
      mn = dis, ans = a[i];
    }
  }
  if (check(a[1] - 1) < mn || check(a[n] + 1) < mn) {
    cout << "No\n";
  } else {
    cout << ans << '\n';
  }
  
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}