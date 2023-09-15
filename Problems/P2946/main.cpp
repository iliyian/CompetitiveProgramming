#include <bits/stdc++.h>
using namespace std;

int a[2000], f[2000][];

int main() {
  int N, F, sum = 0;
  cin >> N >> F;
  for (int i = 0; i < N; i++)
    cin >> a[i], sum += a[i];
  for (int i = 0; i < N; i++)
    for (int j = sum; i >= a[i]; i--)
      
}