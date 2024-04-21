#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l = 0x7fffffff, r = -1;
  bool f = false;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a) l = min(l, i), r = max(r, i), f = true;
  }
  if (f)
    cout << r - l + 1;
  else cout << 0;
  return 0;
}