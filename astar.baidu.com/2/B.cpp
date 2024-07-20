#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<int> s(n + 2), a(n + 1);
  for (int i = 1; i <= k; i++) {
    int l, r;
    cin >> l >> r;
    s[l]++, s[r + 1]--;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + s[i];
  }
  sort(a.begin() + 1, a.end());
  if (n & 1) {
    cout << a[(n + 1) / 2] << '\n';
  } else {
    cout << (a[n / 2] + a[n / 2 + 1]) / 2.0 << '\n';
  }

  return 0;
}