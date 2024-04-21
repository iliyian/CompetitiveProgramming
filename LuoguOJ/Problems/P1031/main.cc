#include <cstdio>
// 贪心要根据当前改变未来，而非改变过去，
// 改变过去成本很大，而未来会自然的到来

int main() {
  int N, p[102], sum = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", p+i), sum += p[i];
  int avg = sum /= N;
  // printf("avg=%d\n", avg);
  for (int i = 0; i < N; i++)
    p[i] -= avg;
  int c = 0;
  for (int i = 0; i < N; i++) {
    if (!p[i]) continue;
    else {
      p[i+1] += p[i];
      c++;
    }
  }
  printf("%d", c);
  return 0;
}