#include <cstdio>

int main() {
  int y, m;
  int a[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  scanf("%d %d", &y, &m);
  bool r = (!(y % 4) && y % 100) || !(y % 400);
  if (m == 2) {
    if (r) printf("29");
    else printf("28");
  } else printf("%d", a[m]);
  return 0;
}