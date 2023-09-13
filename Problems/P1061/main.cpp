#include <bits/stdc++.h>
using namespace std;

int s, t, w;

string str;
void dfs(int pos) {
  if (pos == -1) return;
  if (str[pos] - 'a' < t - 1 && (str[pos] < str[pos + 1] - 1 || pos == w - 1)) {
    str[pos]++;
    for (int i = pos + 1; i < w; i++)
      str[i] = str[i - 1] + 1;
    for (int i = 0; i < w; i++)
      cout << str[i];
    cout << '\n';
    return;
  }
  dfs(pos - 1);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> s >> t >> w;
  cin >> str;
  for (int i = 0; i < 5; i++)
    dfs(w - 1);
  return 0;
}