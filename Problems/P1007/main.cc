#include <cstdio>
#include <cmath>
#include <algorithm>

int main() {
  int L, N;
  int bridge[5001];
  scanf("%d %d", &L, &N);
  if (N == 0) {
    printf("0 0");
    return 0;
  }
  for (int i = 0; i < N; i++) scanf("%d", bridge+i);
  std::sort(bridge, bridge+N);
  // for (int i = 0; i < N; i++) printf("bridge[%d]=%d\n", i, bridge[i]);
  int maxtime = fmax(L + 1 - bridge[0], bridge[N-1]);
  int mintime = -1;
  for (int i = 0; i < N; i++)
    mintime = fmax(mintime, fmin(bridge[i], L + 1 - bridge[i]));
  printf("%d %d", mintime, maxtime);
  return 0;
}