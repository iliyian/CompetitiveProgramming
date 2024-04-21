#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == 'V' && s[i + 1] == 'K') {
      ans++;
      s[i] = s[i + 1] = 0;
    }
  }
  bool chance = true;
  for (int i = 0; i < n - 1 && chance; i++) {
    if ((s[i] == 'V' && s[i + 1]) || (s[i + 1] == 'K' && s[i])) {
      chance = false;
      ans++;
    }
  }
  cout << ans;
  return 0;
}