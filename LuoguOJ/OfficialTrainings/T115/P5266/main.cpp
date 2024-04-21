#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int op, score;
    string name;
    cin >> op;
    switch (op) {
      case 1:
        cin >> name >> score;
        m[name] = score;
        cout << "OK\n";
      break;
      case 2:
        cin >> name;
        if (!m.count(name)) {
          cout << "Not found\n";
        } else cout << m[name] << '\n';
      break;
      case 3:
        cin >> name;
        if (m.count(name)) {
          m.erase(name);
          cout << "Deleted successfully\n";
        } else cout << "Not found\n";
      break;
      case 4:
        cout << m.size() << '\n';
      break;
    }
  }
  return 0;
}