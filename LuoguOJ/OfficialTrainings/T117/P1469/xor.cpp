#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans = 0, n;
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    ans ^= a;
  }
  cout << ans;
  return 0;
}