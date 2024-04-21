#include <bits/stdc++.h>
using namespace std;

int m[] = {0, 18, 18, 14, 14, 10, 10};

int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (i == n - 1) ans += a;
    ans += m[a];
  }
  cout << ans;
  return 0;
}