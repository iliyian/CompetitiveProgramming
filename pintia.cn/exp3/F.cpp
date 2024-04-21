#include <bits/stdc++.h>
#define N 100005
using namespace std;

int a[55];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    a[x]++;
  }
  for (int i = 0; i <= 50; i++)
    if (a[i])
      printf("%d:%d\n", i, a[i]);
  return 0;
}