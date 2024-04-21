#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  bool f = false;
  for (int i = 0; n - 5 * i >= 0; i++)
      if ((n - 5 * i) % 3 == 0) {
        f = true;
        printf("men = %d, women = %d, child = %d\n",
          i, (n - 5 * i) / 3, n - i - (n - i * 5) / 3);
      }
  if (!f) cout << "None\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("6.in", "r", stdin);
  freopen("6.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}