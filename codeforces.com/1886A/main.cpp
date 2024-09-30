#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int n; 
    cin >> n;
    bool f = false;
    for (int i = 1; i <= n / 3 && !f; i++) {
      if (i % 3 == 0) continue;
      for (int j = i + 1; j <= n / 3 * 2 && !f; j++) {
        if (j % 3 == 0) continue;
        int k = n - i - j;
        if (k % 3 == 0 || k == i || k == j) continue;
        cout << "YES\n";
        cout << i << ' ' << j << ' ' << k << '\n';
        f = true;
      }
    }
    if (!f)
      cout << "NO\n";
  }
  return 0;
}