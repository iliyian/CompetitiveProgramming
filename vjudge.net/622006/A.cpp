#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int n, q;
  cin >> n >> q;
  // for (int n = 1, q = 0; n <= 100; n++) {
  if (n == 1) {
    cout << 1 << '\n';
  } else if (n == 2) {
    cout << 3 << '\n';
  } else {
    int x = (n + 1) / 2 + 1;
    int sum = 3 + __int128(2 + x) * (x - 3) + (n % 2 ? x : x * 2);
    cout << sum << '\n';
  }
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    cout << (x <= 2 ? x : (x + 1) / 2 + 1) << '\n';
  }
  // }

  return 0;
}