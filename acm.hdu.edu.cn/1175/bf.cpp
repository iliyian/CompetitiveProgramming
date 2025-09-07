#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, a[2000];
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  while (m--) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1)
      a[x] = y;
    else {
      int ans = 0;
      for (int i = x; i <= y; i++) {
        int b[2000] = {};
        for (int j = i; j <= y; j++) {
          b[a[j]]++;
          bool flag = 1;
          for (int k = 0; k <= j - i; k++)
            if (a[i + k] != b[k]) {
              flag = 0;
              break;
            }
          if (flag)
            ans = max(ans, j - i + 1);
        }
      }
      cout << ans << endl;
    }
  }
}
int main() {
  int T = 1;
  cin >> T;
  while (T--)
    solve();
  return 0;
}