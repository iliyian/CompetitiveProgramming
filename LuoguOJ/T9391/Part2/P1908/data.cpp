#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("data.in", "w", stdout);
  srand(time(NULL));
  int n = rand() % 100 + 1000;
  cout << n << endl;
  for (int i = 0; i < n; i++)
    cout << rand() % 1000 << " ";
  return 0;
}