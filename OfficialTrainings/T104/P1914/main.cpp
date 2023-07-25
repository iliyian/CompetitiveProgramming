#include <cstdio>
#include <cstring>

int main() {
  char s[51];
  int n;
  scanf("%d %s", &n, s);
  for (int i = 0; i < strlen(s); i++) {
    int raw = s[i] - 'a' + n;
    if (raw >= 26) raw %= 26; 
    printf("%c", 'a' + raw);
  }
  return 0;
}