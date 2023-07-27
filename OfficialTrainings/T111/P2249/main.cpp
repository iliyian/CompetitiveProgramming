#include <bits/stdc++.h>
using namespace std;

int a[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++) {
    int q;
    cin >> q;
    int *ans = lower_bound(a, a + n, q);
    if (ans != a + n && *ans == q)
      cout << ans - a + 1;
    else cout << -1;
    cout << ' ';
  }
  return 0;
}