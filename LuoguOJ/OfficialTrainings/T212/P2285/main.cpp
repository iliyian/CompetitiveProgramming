#include <bits/stdc++.h>
using namespace std;

int times[10001], dp[10001], xs[10001], ys[10001];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> times[i] >> xs[i] >> ys[i];
  }
  for (int i = 0; i < m; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (abs(xs[i] - xs[j]) + abs(ys[i] - ys[j]) <= abs(times[j] - times[i])) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  cout << *max_element(dp, dp + m);
  return 0;
}