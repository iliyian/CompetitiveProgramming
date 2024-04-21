#include <bits/stdc++.h>
using namespace std;


map<int, int> nums;

int maxn = 0, ans = 0, maxnums = 0;

int getCount() {

  for (map<int, int>::iterator it = nums.begin(); it != nums.end(); it++) {
    if (it->second > nums[maxn]) maxn = it->first, maxnums = it->second;
  }
  for (map<int, int>::iterator it = nums.begin(); it != nums.end(); it++) {
    if (it->second == maxnums) ans++;
  }

  return ans;
}

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    nums[a]++;
  }
  
  for (int t = 0; t < k; t++) {
    
  }

  if (nums[maxn] <= k) cout << "pigstd";
  else cout << getCount();
  return 0;
}