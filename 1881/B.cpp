#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int _; cin >> _;
  while (_--) {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    bool f = true;
    if (a[0] == a[1] && a[0] == a[2]) {
      cout << "YES" << '\n';
      continue;
    }
    if (a[0])
  }
}