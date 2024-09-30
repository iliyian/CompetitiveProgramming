#include <bits/stdc++.h>
#define int long long
using namespace std;

mt19937 rd(random_device{}());

void solve() {
  int n = 4000000;
  cout << n << '\n';
  for (int i = 1; i <= n / 2; i++) {
    cout << 1 << ' ';
  }
  cout << '\n';
  for (int i = 1; i <= n / 2; i++) {
    cout << 1 << ' ';
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}