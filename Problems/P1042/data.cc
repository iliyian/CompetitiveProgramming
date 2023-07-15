#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
  srand(time(NULL));
  freopen("data.in", "w", stdout);

  int n = rand();
  for (int i = 0; i < n; i++) {
    printf("%c", rand() % 2 ? 'W' : 'L');
  }
  return 0;
}