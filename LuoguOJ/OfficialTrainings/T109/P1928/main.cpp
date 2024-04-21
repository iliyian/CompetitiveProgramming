// cin 自动判断类型太爽了

#include <bits/stdc++.h>
using namespace std;

string str;

int find(char ch, int l, int r) {
  for (int i = l; i < r; i++) {
    if (str[i] == ch)
      return i;
  }
  return -1;
}

// [)
void solve(int l, int r) {
  int lc = find('[', l, r), cnt = 0, rc;
  for (int i = lc; i < r; i++) {
    if (str[i] == '[') cnt++;
    if (str[i] == ']') cnt--;
    if (!cnt) {rc = i; break;}
  }
  if (lc != -1) {
    solve(l, lc);
    int n = str[lc+1] - '0';
    if (isdigit(str[lc+2])) n = n * 10 + str[lc+2] - '0', lc = lc + 3;
    else lc = lc + 2;
    for (int j = 0; j < n; j++) {
      solve(lc, rc);
    }
    solve(rc + 1, r);
  } else for (int i = l; i < r; i++)
    cout << str[i];
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> str;
  solve(0, str.size());
  return 0;
}