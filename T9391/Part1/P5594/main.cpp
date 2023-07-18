#include <cstdio>
#include <bitset>
using namespace std;

bitset<1002> count[1002];

int n, m, k;

int main() {
  scanf("%d %d %d", &n, &m, &k);
  while (n--) {
    for (int i = 0; i < m; i++) {
      int a;
      scanf("%d", &a);
      count[a][i] = true;
    }
  }
  for (int i = 1; i <= k; i++) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
      sum += count[i][j];
    }
    printf("%d ", sum);
  }
  return 0;
}