#include <bits/stdc++.h>
#define N 1005
using namespace std;

int a[N], len = 0;

int partition(int l, int r) {
  int p = a[l];
  int i = l, j = r;
  while (i < j) {
    while (i < j && a[j] > p) j--;
    while (i < j && a[i] <= p) i++;
    swap(a[i], a[j]);
  }
  swap(a[i], a[l]);
  return i;
}

void quicksort(int l, int r) {
  if (l >= r) return;
  int p = partition(l, r);
  for (int i = 0; i < len; i++)
    cout << a[i] << ' ';
  cout << '\n';
  quicksort(l, p - 1);
  quicksort(p + 1, r);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("G.in", "r", stdin);
  cin >> len;
  for (int i = 0; i < len; i++)
    cin >> a[i];
  quicksort(0, len - 1);
  for (int i = 0; i < len; i++)
    cout << a[i] << ' ';
  cout << '\n';
  return 0;
}