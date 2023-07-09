#include <cstdio>
#include <cstring>
#include <cmath>

struct Herbar {
  int t, v;
}herbars[101];

int main() {
  int T, M;
  scanf("%d %d", &T, &M);

  for (int i = 0; i < M; i++) {
    int t, v;
    scanf("%d %d", &t, &v);
    herbars[i].t = t;
    herbars[i].v = v;
  }

  int dp[1001];
  memset(dp, 0, sizeof(dp));

  // 对于每一株药草，遍历所有时间情况
  // j是剩余时间
  // dp[j] 表示j时间下最多的值
  // 时间只能变少，不能变多
  for (int i = 0; i < M; i++) {
    for (int j = T; j >= herbars[i].t; j--) {
      dp[j] = fmax(dp[j], dp[j-herbars[i].t] + herbars[i].v);
    }
  }

  printf("%d", dp[T]);
  return 0;
}