#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  string str;
  cin >> str;
  int c1 = 0, c2 = 0;
  for (int i = 0; i < 5; i++) {
    c1 += str[i] == 'A', c2 += str[i] == 'B';
  }
  cout << (c1 > c2 ? 'A' : 'B') << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}