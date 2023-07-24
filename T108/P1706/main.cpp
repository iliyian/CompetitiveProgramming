#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int nums[10];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    nums[i] = i + 1;
  }
  do {
    for (int i = 0; i < n; i++)
      cout << setw(5) << nums[i];
    cout << '\n';
  } while (next_permutation(nums, nums + n));
  return 0;
}