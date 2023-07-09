#include <cstdio>
#include <cstring>
#include <algorithm>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int d[26], v[26];
  for (int i = 0; i < m; i++) {
    int lv;
    scanf("%d %d", d+i, &lv);
    v[i] = d[i] * lv;
    // printf("d[%d]=%d\n", i, d[i]);
  }

  int dp[30001];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < m; i++) {
    for (int j = n; j >= d[i]; j--) {
      dp[j] = std::max(dp[j], dp[j - d[i]] + v[i]);
    }
  }
  printf("%d", dp[n]);
  return 0;
}