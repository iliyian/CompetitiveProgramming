#include <bits/stdc++.h>
using namespace std;

int h[10001], ans[10001];
bitset<10001> dp;

int main() {
  freopen("data.in", "r", stdin);
  int n, minh = 0x7fffffff;
  cin >> n;
  memset(ans, 0, sizeof(ans));
  for (int i = 0; i < n; i++) {
    int x, cnt = 0, sum = 0;
    while (cin >> x) {
      if (x == -1) break;
      h[cnt++] = x;
      sum += x;
    }
    minh = min(minh, sum);
    dp.reset();
    dp[0] = true;
    for (int i = 0; i < cnt; i++) {
      for (int j = minh; j >= h[i]; j--) {
        if (dp[j - h[i]] && !dp[j])
          dp[j] = true, ans[j]++;
      }
    }
  }
  for (int i = minh; i >= 0; i--)
    if (ans[i] == n) {
      cout << i;
      return 0;
    }
  cout << 0;
  return 0;
}