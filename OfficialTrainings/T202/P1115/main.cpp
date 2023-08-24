#include <bits/stdc++.h>
#define inf 0x7fffffff
using namespace std;

int main() {
  int n, a, sum = -inf, ans = -inf;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    sum = max(0, sum) + a;
    ans = max(ans, sum);
  }
  cout << ans;
  return 0;
}