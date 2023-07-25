#include <cstdio>
#include <cstring>

int transform(char *s, int len) {
  int mul = 1;
  for (int i = 0; i < len; i++) {
    mul *= s[i] - 'A' + 1;
  }
  // printf("%d\n", mul, len);
  return mul % 47;
}

int main() {
  char a[7], b[7];
  scanf("%s\n%s", a, b);
  printf("%s", transform(a, strlen(a)) == transform(b, strlen(b)) ? "GO" : "STAY");
  return 0;
}