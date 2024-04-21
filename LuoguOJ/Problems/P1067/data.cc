#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
  freopen("data.in", "w", stdout);

  srand(time(NULL));
  int n = rand() % 101;
  printf("%d\n", n);
  for (int i = 0; i < n+1; i++) {
    int sig = rand() & 1 ? -1 : 0;
    int a = (rand() % 101) * sig;
    printf("%d ", a);
  }
  return 0;
}