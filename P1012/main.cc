#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

bool cmp(const string &a, const string &b) {
  // cout << a << " " << b << endl;
  // int alen = a.length(), blen = b.length();
  // int len = fmax(alen, blen);
  // for (int i = 0; i < len; i++) {
  //   char ac = i >= alen ? '0' : a.at(i);
  //   char bc = i >= blen ? '0' : b.at(i);
  //   if (ac != bc) return ac >= bc;
  // }
  return (a + b) >= (b + a);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string nums[20];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> nums[i];
  sort(nums, nums+n, cmp);
  for (int i = 0; i < n; i++) cout << nums[i];
  return 0;
}