#include <bits/stdc++.h>
using namespace std;

string strs[1001];
int cont[30];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int n, g;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> strs[i];
    if (i == 0)
      for (int j = 0; j < strs[i].size(); j++)
        cont[int(strs[i][j] - 'a')] = true;
  }
  cin >> g;
  for (int i = 0; i < g; i++) {
    string str;
    cin >> str;
    int ans = n;
    for (int j = 0; j < n; j++) {
      bool f = true;
      for (int k = 0; k < 5; k++) {
        if (str[k] == '*') {
          if (strs[j][k] != strs[0][k])
            f = false;
        } else if (str[k] == '!') {
          if (strs[j][k] == strs[0][k] || !cont[strs[j][k] - 'a'])
            f = false;
        } else if (str[k] == 'X') {
          if (strs[j][k] == strs[0][k] || cont[strs[j][k] - 'a'])
            f = false;
        }
        if (!f) break;
      }
      if (!f) ans--;
      // else cout << j << '\n';
    }
    cout << ans << "\n";
  }
}