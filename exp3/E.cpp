#include <bits/stdc++.h>
using namespace std;

char a[15];

int main() {
  int n;
  cin >> n;
  iota(a, a + n, 'A');
  a[n] = '\0';
  do {
    printf("%s\n", a);
  } while (next_permutation(a, a + n));
  return 0;
}