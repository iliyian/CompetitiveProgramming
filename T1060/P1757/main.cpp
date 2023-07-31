#include <bits/stdc++.h>
using namespace std;

int cnt[101], dp[1001];

struct Item {
  int w, v;
} t[101][1001];

int main() {
  int m, n, ts = 0;
  cin >> m >> n;
  memset(cnt, 0, sizeof(cnt));
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    int w, v, k;
    cin >> w >> v >> k;
    ts = max(ts, k);
    t[k][cnt[k]++] = {w, v};
  }
  for (int i = 1; i <= ts; i++) {
    for (int j = m; j >= 0; j--) {
      for (int k = 0; k < cnt[i]; k++) {
        if (j >= t[i][k].w)
          dp[j] = max(dp[j], dp[j - t[i][k].w] + t[i][k].v);
      }
    }
  }
  cout << dp[m];
  return 0;
}