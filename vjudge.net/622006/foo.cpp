#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("foo.in", "r", stdin);
  freopen("foo.out", "w", stdout);

  int sum = 0;
  int prv = -1, cur;
  while (cin >> cur) {
    if (prv != -1) {
      sum += abs(prv - cur);
    }
    prv = cur;
  }
  cout << sum << '\n';

  return 0;
}