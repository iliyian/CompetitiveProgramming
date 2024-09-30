// date: 2023/12/9
// tmd,a,c的开头是tmd 0

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("F.in", "r", stdin);
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1), c(n + 1), d(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i] - a[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    d[i] = c[i] - c[i - 1];
  }
  if (a[1] != c[1] || a.back() != c.back()) {
    cout << "No";
    return 0;
  }
  // b.pop_front(), d.pop_front();
  sort(b.begin(), b.end());
  sort(d.begin(), d.end());
  cout << (b == d ? "Yes" : "No");
}