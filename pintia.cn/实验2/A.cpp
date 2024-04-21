#include <bits/stdc++.h>
using namespace std;

int a[11];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  swap(*min_element(a, a + n), a[0]);
  swap(*max_element(a, a + n), a[n - 1]);
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
  return 0;
}