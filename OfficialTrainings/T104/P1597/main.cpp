// isspace对于换行符返回true

// 有个秒解，scanf("%c:=%c;");
#include <cstdio>
#include <cctype>

int main() {
  char ch = getchar();
  int vars[] = {0, 0, 0};
  char prealpha = 0;
  int num = 0;
  while (!isspace(ch) && ch != EOF) {
    if (isalpha(ch)) {
      if (prealpha) {
        vars[prealpha - 'a'] = vars[ch - 'a'];
        prealpha = 0;
      } else prealpha = ch;
    }
    if (isdigit(ch)) {
      vars[prealpha - 'a'] = ch - '0';
      prealpha = 0;
    }
    ch = getchar();
  }
  printf("%d %d %d", vars[0], vars[1], vars[2]);
  return 0;
}