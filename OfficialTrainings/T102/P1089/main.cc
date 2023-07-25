#include <cstdio>

int main() {
  int saved = 0, rest = 0;
  for (int i = 1; i <= 12; i++) {
    int a;
    scanf("%d", &a);
    rest += 300;
    rest -= a;
    if (rest < 0) {
      printf("-%d", i);
      return 0;
    }
    if (rest >= 100) {
      int save = rest / 100 * 100;
      rest -= save;
      saved += save;
    }
    // printf("rest=%d, saved=%d\n", rest, saved);
  }
  printf("%d", int(1.2 * saved) + rest);
  return 0;
}

/*
290 
230 
280 
200 
300 
170 
330 
50 
90 
80 
200 
60 
*/