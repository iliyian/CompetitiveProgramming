#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, T, maxn = -1, ans = 0;
  cin >> n >> T;

  for (int i = 0; i < n; i++) {
    int v, t;
    cin >> v >> t;
    int h = (T - t) * v;
    if (h > maxn) {
      maxn = h;
      ans = i;
    }
  }
  cout << ans + 1;
  return 0;
}