#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  vector<int> a(200001);
  for (int i = 1; i <= 200000; i++) {
    int p = i, s = 0;
    while (p) s += p % 10, p /= 10;
    a[i] = a[i - 1] + s;
  }

  while (_--) {
    int n;
    cin >> n;
    cout << a[n] << '\n';
  }

  return 0;
}