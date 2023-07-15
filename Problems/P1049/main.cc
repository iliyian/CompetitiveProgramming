#include <cstdio>
#include <cstring>
#include <algorithm>

// for max value equals for max weigh
int main() {
  int V, n;
  scanf("%d %d", &V, &n);
  int d[31];
  for (int i = 0; i < n; i++) {
    scanf("%d", d+i);
  }
  
  int dp[20001];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    for (int j = V; j >= d[i]; j--) {
      dp[j] = std::max(dp[j], dp[j-d[i]] + d[i]);
    }
  }
  printf("%d", V - dp[V]);
  return 0;
}