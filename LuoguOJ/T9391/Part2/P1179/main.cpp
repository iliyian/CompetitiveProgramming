#include <bits/stdc++.h>
using namespace std;

int check(int n) {
  int ans = 0;
  while (n) {
    ans += (n % 10 == 2);
    n /= 10;
  }
  return ans;
}

int main() {
  int l, r, ans = 0;
  cin >> l >> r;
  for (int i = l; i <= r; i++) {
    ans += check(i);
  }
  cout << ans;
  return 0;
}