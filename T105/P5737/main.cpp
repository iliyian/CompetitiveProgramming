#include <cstdio>
#include <array>
using namespace std;

bool isRun(int n) {
  return ((!(n % 4) && n % 100) || !(n % 400));
}

int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  array<int, 2000> years{};
  int count = 0;
  for (int i = x; i <= y; i++) {
    if (isRun(i)) years[count++] = i;
  }
  printf("%d\n", count);
  for (int i = 0; i < count; i++)
    printf("%d ", years[i]);
  return 0;
}