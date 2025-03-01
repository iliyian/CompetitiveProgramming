// tmd为什么用N,Y，太迷惑了

#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
bitset<1000001> a;

int main() {
  freopen("data.in", "r", stdin);
  int n, m, lastr = 1, lastwr = 1;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    char ch;
    cin >> ch;
    bool f = false;
    if (ch == 'N') {
      for (int i = lastwr; i <= n; i++) {
        if (!a[i]) {
          ans.push_back(i);
          f = true;
          a[i] = true;
          lastwr = i + 1;
          break;
        }
      }
    } else {
      for (int i = lastr; i <= n; i++)
        if (a[i]) {
          ans.push_back(i);
          f = true;
          lastr = i;
          break;
        }
    }

    if (!f) {
      cout << "No solution";
      return 0;
    }
  }
  for (auto i : ans) {
    cout << i << ' ';
  }
  return 0;
}