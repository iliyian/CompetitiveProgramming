#include <iostream>
using namespace std;
int main() {
  int a[30], low, height, mid, n, x, i;
  cin >> n >> x;
  for (i = 0; i < n; i++)
    cin >> a[i];
  low = 0;
  height = n - 1;
  while (low <= height) {
    mid = (low + height) / 2;
    if (a[mid] < x)
      low = mid + 1;
    else if (a[mid] > x)
      height = mid - 1;
    else
      break;
  }
  if (a[mid] == x)
    cout << mid;
  else
    cout << "No";
  return 0;
}