#include <cstdio>
#include <algorithm>
#include <numeric>
#include <array>
using namespace std;

int main() {
  int n, m, ans = -1;
  array<int, 20> scores{};
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      scanf("%d", scores.begin() + j);
    int sum = accumulate(scores.begin(), scores.begin() + m, 0);
    pair<int*, int*> minmax = minmax_element(scores.begin(), scores.begin() + m);
    sum -= *minmax.first + *minmax.second;
    if (sum > ans) ans = sum;
  }
  printf("%.2lf", ans / 1.0 / (m - 2));
  return 0;
}