#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
  char word[100];
  int count[256];
  scanf("%s", word);
  memset(count, 0, sizeof(count));
  int len = strlen(word);
  for (int i = 0; i < len; i++) {
    count[word[i]]++;
  }
  
  int maxn = -1e9, minn = 1e9;
  for (int i = 'a'; i <= 'z'; i++) {
    maxn = fmax(maxn, count[i]);
    if (count[i]) minn = fmin(minn, count[i]);
  }
  int n = maxn - minn;

  if (n < 2) {
    printf("No Answer\n0");
    return 0;
  }

  for (int i = 2; i*i <= n; i++) {
    if (n % i == 0) {
      printf("No Answer\n0");
      return 0;
    }
  }
  printf("Lucky Word\n%d", n);
  return 0;
}