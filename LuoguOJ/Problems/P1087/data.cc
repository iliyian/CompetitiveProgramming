#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
  srand(time(NULL));
  freopen("data.in", "w", stdout);

  printf("10\n");
  for (int i = 0; i < 1024; i++) {
    printf("%d", rand() & 1 ? 1 : 0);
  }
  return 0;
}