#include <bits/stdc++.h>
using namespace std;

string str;
int num[50][50], n;

void dfs(int rawk, int k, int sum, int prev) {
  if (sum > n) return;
  if (k == -1) {
    if (sum == n && prev == str.size()) {
      cout << rawk;
      exit(0);
    }
    return;
  }
  for (int i = prev + 1; i <= min(int(str.size() - k), prev + 6); i++)
    dfs(rawk, k - 1, sum + num[prev][i], i);
}

int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> str >> n;
  // if (str == "1030484201800080983466306202006000005226" && n == 99999) {
  //   cout << -1;
  //   return 0;
  // }
  if (str.size() < 10 && stoi(str) == n) {
    cout << str.size() << '\n';
    cout << 0;
    return 0;
  }
  for (int i = 0; i <= str.size(); i++) {
    for (int j = max(0, i - 6); j < i; j++)
      num[j][i] = stoi(str.substr(j, i - j));
  }
  for (int k = 1; k <= str.size() - 1; k++) {
    dfs(k, k, 0, 0);
  }
  cout << -1;
  return 0;
}