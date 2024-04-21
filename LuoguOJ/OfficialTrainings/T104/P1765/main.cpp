#include <cstdio>
#include <cctype>

int count[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

int main() {
  char ch = getchar();
  int ans = 0;
  while (ch != EOF) {
    if (ch == '\n' || ch == '\r') {
      ch = getchar();
      continue;
    }
    else if (isspace(ch)) ans++;
    else if (isalpha(ch)) ans += count[ch - 'a'];
    ch = getchar();
  }
  printf("%d", ans);
  return 0;
}