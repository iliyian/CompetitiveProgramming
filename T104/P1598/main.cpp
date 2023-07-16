#include <cstdio>
#include <cctype>
#include <array>
#include <algorithm>

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  char ch = getchar();
  std::array<int, 26> ans{};
  while (ch != EOF) {
    if (isalpha(ch)) {
      ans[ch - 'A']++;
      // printf("ch=%c\n", ch);
    }
    ch = getchar();
  }
  int *maxn = std::max_element(ans.begin(), ans.end());
  // printf("maxn=%d\n", *maxn);
  for (int i = *maxn; i >= 1; i--) {
    int r = 0;
    for (int j = 25; j >= 0; j--) {
      if (i <= ans[j]) {
        r = j; break;
      }
    }
    for (int j = 0; j <= r; j++) {
      putchar(i <= ans[j] ? '*' : ' ');
      if (j != r) putchar(' ');
    }
    putchar('\n');
  }
  for (char i = 'A'; i <= 'Z'; i++) {
    putchar(i);
    if (i != 'Z') putchar(' ');
  }
  return 0;
}