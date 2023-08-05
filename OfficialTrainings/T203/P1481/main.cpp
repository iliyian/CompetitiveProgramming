#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  vector<int> dp(n);
  vector<string> strs;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    strs.push_back(str);
    for (int j = 0; j < i; j++) {
      string &pre = strs[j];
      if (str.find(pre) == 0)
        dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  cout << *max_element(dp.begin(), dp.end()) + 1;
  return 0;
}