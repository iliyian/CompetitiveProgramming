#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("data.in", "w", stdout);
  srand(time(NULL));
  int n = 500 + rand() % 500;
  int h = 5000 + rand() % 5000;
  int r = 1000 + rand() % 500;
  cout << 1 << endl;
  cout << n << " " << h << " " << r << endl;
  for (int i = 0; i < n; i++) {
    cout << rand() % h << " " << rand() % h << " " << rand() % h << endl;
  }
  return 0;
}