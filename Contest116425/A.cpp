#include <bits/stdc++.h>
using namespace std;

void solve() {
  int op, n, x;
  cin >> op >> n >> x;
  if (op == 1) {
    if (n >= x + 2) {
      cout << "-1\n";
      return;
    }
    for (int i = 0; i < n - 2; i++)
      cout << 1 << ' ';
    for (int i = 0; i < 2; i++)
      cout << x - n + 2 << ' ';
    cout << '\n';
  } else {
    if (n >= (long long)x + 2) {
      cout << "-1\n";
      return;
    }
    for (int i = 0; i < n - 1; i++) 
      cout << 1 << ' ';
    cout << x - n + 2 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}