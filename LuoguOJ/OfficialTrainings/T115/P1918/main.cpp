#include <bits/stdc++.h>
using namespace std;

set<int> s;
map<int, int> id;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
    id[x] = i;
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int m;
    cin >> m;
    if (!s.count(m)) cout << "0\n";
    else cout << id[m] + 1 << '\n';
  }
  return 0;
}