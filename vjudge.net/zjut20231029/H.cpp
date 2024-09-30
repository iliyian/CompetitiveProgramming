#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> colors;

int main() {
  freopen("H.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  string str;
  cin >> str;
  colors.resize(m + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    colors[x].push_back(i);
  }
  string fina(str.size(), 0);
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < colors[i].size() - 1; j++) {
      fina[colors[i][j + 1]] = str[colors[i][j]];
    }
    fina[colors[i][0]] = str[colors[i].back()];
  }
  cout << fina;
  return 0;
}