// windows 下新行开头的 CTRL+Z 表示 EOF
// linux 下为新行开头的 CTRL+D

#include <iostream>
using namespace std;

int main() {
  int ans = 0;
  char ch = getchar();
  while (ch != EOF) {
    ans += (!isspace(ch) && ch != '\r' && ch != '\n');
    ch = getchar();
  }
  cout << ans;
  return 0;
}