#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string &s) {
  int n = s.size();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

int main() {
  freopen("data.in", "r", stdin);
  string s1, s2;
  cin >> s1 >> s2;

  string cur = s2 + '#' + s1;
  vector<int> ans;
  vector<int> lps = prefix_function(cur);
  int sz1 = s1.size(), sz2 = s2.size();
  for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
    if (lps[i] == sz2)
      ans.push_back(i - 2 * sz2);
  }
  for (auto pos : ans)
    cout << pos + 1 << '\n';
  for (int i = 0; i < sz2; i++)
    cout << lps[i] << ' ';
  return 0;
}