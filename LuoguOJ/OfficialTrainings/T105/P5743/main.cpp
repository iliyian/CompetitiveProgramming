#include <iostream>
using namespace std;

int main() {
  int n, ans = 1;
  cin >> n;
  while (--n) {
    ans += 1;
    ans <<= 1;
  }
  cout << ans;
  return 0;
}