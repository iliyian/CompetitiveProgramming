#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i == 1) a[i] += 3 * k;
    else {
      cnt += a[i] > a[1];
    }
  }
  if (n == 2) {
    cout << (a[2] > a[1] ? 1 : 0) << '\n';
    return 0;
  }

  sort(a.begin() + 2, a.end());
  int r = n - 1, l = 2;
  while (a[r] > a[1] && r >= l) {
    r--, l++;
  }
  cout << l << ' ' << r << '\n';
  if (l > r) {
    cout << n - 1 << '\n';
  } else {
    
  }

  return 0;
}