#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

int main() {
  int n, maxs = -1;
  string winner;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string name;
    int s;
    cin >> name >> s;
    m[name] += s;
    if (maxs < m[name]) {
      maxs = m[name];
      winner = name;
    }
  }
  cout << winner;
  return 0;
}