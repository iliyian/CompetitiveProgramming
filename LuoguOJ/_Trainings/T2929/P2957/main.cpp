// 数据量200不到，O(n^2)都能，甚至O(n^3);
// 当然KMP之外也可以优化，但是AC了，不管了 2023/8/4 20:03

#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string &str) {
  int n = str.size();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && str[i] != str[j]) j = pi[j - 1];
    if (str[i] == str[j]) j++;
    pi[i] = j;
  }
  return pi;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  string cur1 = s1 + '#' + s2, cur2 = s2 + '#' + s1;
  vector<int> pi1 = prefix_function(cur1), pi2 = prefix_function(cur2);
  int ans1 = *max_element(pi1.begin() + s1.size(), pi1.end()),
    ans2 = *max_element(pi2.begin() + s2.size(), pi2.end());
  cout << max(ans1, ans2);
  return 0;
}