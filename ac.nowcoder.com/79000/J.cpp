#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("J.in", "r", stdin);
  freopen("J.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  sort(a.begin() + 1, a.end());
  sort(b.begin() + 1, b.end());
  
  int p = n * (a[(n + 1) / 2]), q = n * (b[(n + 1) / 2]);
  if (p > q) {
    cout << "Yes\n";
  } else if (p < q) {
    cout << "No\n";
  } else {
    cout << "NY\n";
  }

  return 0;
}