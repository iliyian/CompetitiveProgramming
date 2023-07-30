#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("data.in", "w", stdout);
  mt19937 myrand(random_device{}());
  int n = 10;
  cout << "10 10\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << myrand() % 10000 << ' ';
    }
    cout << '\n';
  }
  return 0;
}