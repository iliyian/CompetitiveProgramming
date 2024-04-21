#include <bits/stdc++.h>
using namespace std;

int main() {
  int L;
  string str;
  cin >> L >> str;
  vector<int> pi(1e6 + 1);
  for (int i = 1; i < L; i++) {
    int j = pi[i - 1];
    while (j > 0 && str[i] != str[j]) j = pi[j - 1];
    if (str[i] == str[j]) j++;
    pi[i] = j;
  }
  cout << L - pi[L - 1];
  return 0;
}