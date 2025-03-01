#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<vector<int>> ans;

int n, cnt = 0;

void dfs(int sum) {
  if (sum > n) return;
  if (nums.size() == 10 && sum == n) {
    ans.push_back(nums);
    cnt++;
    // for (int i = 0; i < 10; i++) {
    //   cout << nums[i] << " ";
    // }
    // cout << '\n';
    return;
  }
  for (int i = 1; i <= 3; i++) {
    nums.push_back(i);
    dfs(sum + i);
    nums.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  if (n < 10 || n > 30) {
    cout << 0;
    return 0;
  }
  dfs(0);
  cout << cnt << '\n';
  for (auto a : ans) {
    for (auto i : a) {
      cout << i << ' ';
    }
    cout << '\n';
  }
  return 0;
}