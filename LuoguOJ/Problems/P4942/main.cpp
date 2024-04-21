#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long l, r;
  cin >> l >> r;
  long long a = (l + r), b = (r - l + 1);
  if (a & 1) b = b / 2 % 9;
  else a = a / 2 % 9;
  long long ans = a * b % 9;
  cout << ans << '\n';
}

int main() {
  int Q;
  cin >> Q;
  while (Q--) solve();
  return 0;
}