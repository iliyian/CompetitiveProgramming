#include <bits/stdc++.h>
using namespace std;

int C(int n, int m) {
  int ans = 1;
  for (int i = n; i >= n - m + 1; i--) ans *= i;
  for (int i = 2; i <= m; i++) ans /= i;
  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  string str;
  cin >> str;
  int len = str.size(), ans = 0;

  for (int i = 0; i < len - 1; i++)
    if (str[i + 1] <= str[i]) {
      cout << 0;
      return 0;
    }

  for (int i = 1; i < len; i++)
    ans += C(26, i);
  char l = 'a';
  for (int i = 0; i < len; i++) {
    for (char j = l; j < str[i]; j++)
      ans += C(26 - (j - 'a' + 1), len - i - 1);
      // 我也不太懂上面那步怎么回事, 但是AC，管他呢
    l = str[i] + 1;
  }
  cout << ans + 1;
  return 0;
}