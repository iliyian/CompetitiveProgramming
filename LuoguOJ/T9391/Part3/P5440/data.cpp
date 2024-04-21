#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("data.in", "w", stdout);
  mt19937 myrand(random_device{}());
  cout << 10 << '\n';
  for (int i = 1; i <= 10; i++) {
    for (int j = 0; j < 8; j++) {
      if (myrand() % i == 0)
        cout << '-';
      else cout << myrand() % 10;
    }
    cout << '\n';
  }
  return 0;
}