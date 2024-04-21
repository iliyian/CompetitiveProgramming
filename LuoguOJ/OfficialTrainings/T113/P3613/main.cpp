// 甚至可以把两个int hash成long long节省空间

#include <bits/stdc++.h>
using namespace std;

map<int, map<int, int>> cab;

int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < q; i++){
    int op, a, b, c;
    cin >> op >> a >> b;
    if (op == 1) {
      cin >> c;
      cab[a][b] = c;
    } else {
      cout << cab[a][b] << '\n';
    }
  }
  return 0;
}