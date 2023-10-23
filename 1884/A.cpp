#include <bits/stdc++.h>
using namespace std;

int cal(int n) {
  if (n < 10) return n;
  return n % 10 + cal(n / 10);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int x, k;
    cin >> x >> k;
    for (int i = x;; i++) {
      if (cal(i) % k == 0) {
        cout << i << '\n';
        break;
      }
    }
  }
  return 0;
}