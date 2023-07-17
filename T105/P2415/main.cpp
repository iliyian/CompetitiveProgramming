#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;
int arr[1000];

int main() {
  int n = 0, a;
  while (cin >> a) arr[n++] = a;
  long long sum = accumulate(arr, arr + n, 0);
  sum *= pow(2, n - 1);
  cout << sum;
  return 0;
}