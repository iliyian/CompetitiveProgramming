#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("data.in", "w", stdout);
  srand(time(NULL));
  int a[10];
  for (int i = 0; i < 9; i++)
    a[i] = i;
  random_shuffle(a, a + 10);
  for (int i = 1; i <= 9; i++)
    cout << a[i] % 10;
  return 0;
}