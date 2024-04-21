// 多维费用问题

#include <bits/stdc++.h>
using namespace std;

array<pair<int, int>, 101> dreams{};
array<array<int, 201>, 201> dp{};

int main() {
  int n, M, T;
  cin >> n >> M >> T;
  for (int i = 0; i < n; i++) {
    int m, t;
    cin >> m >> t;
    dreams[i] = make_pair(m, t);
  }
  for (int i = 0; i < n; i++) {
    for (int j = M; j >= dreams[i].first; j--) {
      for (int k = T; k >= dreams[i].second; k--) {
        dp[j][k] = max(dp[j][k], dp[j - dreams[i].first][k - dreams[i].second] + 1);
      }
    }
  }
  cout << dp[M][T];
  return 0;
}