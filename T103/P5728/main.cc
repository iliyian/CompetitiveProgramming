#include <cstdio>
#include <cmath>

int main() {
  int n, aarr[1005], barr[1005], carr[1005], sums[1005];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", aarr + i, barr + i, carr + i);
    sums[i] = aarr[i] + barr[i] + carr[i];
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (abs(aarr[i] - aarr[j]) <= 5 && abs(barr[i] - barr[j]) <= 5 && abs(carr[i] - carr[j]) <= 5
        && abs(sums[i] - sums[j]) <= 10)
          count++;
    }
  }
  printf("%d", count);
  return 0;
}