// 灵光一现，模拟然后找规律即可
// 不难发现某块地如果比前面低，为免费，比前面高，假设前面已经为0，则此块地已不能被免费，则时间加上差值
// 这次确实没看答案了，虽然诗很久前的思路

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, prev = 0, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a > prev) ans += a - prev;
    prev = a;
  }
  cout << ans;
  return 0;
}