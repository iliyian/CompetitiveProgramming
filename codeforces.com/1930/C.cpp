#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += i;
  }
  sort(a.begin() + 1, a.end(), greater());
  a[0] = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= a[i - 1]) {
      a[i] = min(a[i], a[i - 1] - 1);
    }
    cout << a[i] << " \n"[i == n];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}