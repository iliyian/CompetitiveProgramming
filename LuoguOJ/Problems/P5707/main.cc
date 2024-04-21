#include <cstdio>
#include <ctime>

int main() {
  int s, v;
  scanf("%d %d", &s, &v);

  int t = (s - 1) / v + 1;

  int nowh = 7, nowm = 50;
  for (int i = 0; i < t; i++) {
    if (!nowm) {
      if (!nowh) nowh = 23;
      else nowh--;
      nowm = 59;
    } else nowm--;
  }
  printf("%02d:%02d", nowh, nowm);
  return 0;
}