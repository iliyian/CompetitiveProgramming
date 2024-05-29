// date: 2024-05-28 21:38:04
// tag: 枚举，字符串，kmp

#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> prefix_function(const string &s) {
  vector<int> pi(s.size());
  for (int i = 1; i < s.size(); i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

int calc(const string &a, const string &b) {
  vector<int> pi = prefix_function(a + '#' + b);
  int lap = pi.back();
  for (int i : pi) {
    if (i == a.size()) {
      lap = i;
      break;
    }
  }
  return lap;
}

void solve() {
  vector<string> str(3);
  int tot = 0;
  for (int i = 0; i < 3; i++) {
    cin >> str[i];
    tot += str[i].size();
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i != j && calc(str[i], str[j]) == str[i].size()) {
        int k;
        for (k = 0; k < 3; k++) {
          if (k != i && k != j) {
            break;
          }
        }
        cout << tot - str[i].size() - max(calc(str[j], str[k]), calc(str[k], str[j]));
        return;
      }
    }
  }

  vector<int> id(3);
  iota(id.begin(), id.end(), 0);
  int ans = 0x3f3f3f3f;
  do {
    int sum = tot;
    for (int i = 1; i < 3; i++) {
      int lap = calc(str[id[i]], str[id[i - 1]]);
      sum -= lap;
    }
    ans = min(ans, sum);
  } while (next_permutation(id.begin(), id.end()));
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _ = 1;

  while (_--) {
    solve();
  }

  return 0;
}