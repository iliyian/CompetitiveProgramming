// 可以精简，但是AC，算了

#include <cstdio>
#include <cctype>

int getLen(int n) {
  int len = 0;
  if (n <= 0) n = -n, len = 1;
  while (n) n /= 10, len++;
  return len;
}

int main() {
  // freopen("data.in", "r", stdin);

  int n;
  scanf("%d\r\n", &n);
  char opr;
  while (n--) {
    int a = 0, b;
    char ch = getchar();
    if (isalpha(ch)) {
      scanf("%d", &a);
    } else if (isdigit(ch)) {
      while (!isspace(ch)) {
        a *= 10;
        a += ch - '0';
        ch = getchar();
      }
    } else {
      ch = getchar();
      while (!isspace(ch)) {
        a *= 10;
        a -= ch - '0';
        ch = getchar();
      }
    }
    scanf("%d\r\n", &b);
    int ans = 0;
    if (isalpha(ch)) {
      switch (ch) {
        case 'a':
          opr = '+';
          break;
        case 'b':
          opr = '-';
          break;
        case 'c':
          opr = '*';
          break;
        case 'd':
          opr = '/';
          break;
      }
    }
    switch(opr) {
      case '+':
        ans = a + b;
        break;
      case '-':
        ans = a - b;
        break;
      case '*':
        ans = a * b;
        break;
      case '/':
        ans = a / b;
        break;
    }
    printf("%d%c%d=%d\n%d\n", a, opr, b, ans, getLen(a) + getLen(b) + getLen(ans) + 2);
  }
  return 0;

}