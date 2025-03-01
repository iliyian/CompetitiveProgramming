#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> m;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int len;
    cin >> len;
    if (m[len]) m.erase(len);
    else m[len] = true;
  }
  cout << m.begin()->first;
  return 0;
}