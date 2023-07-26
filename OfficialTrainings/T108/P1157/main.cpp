#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> nums;

void dfs(int idx, int prev) {
  if (idx == m - 1) {
    for (auto i : nums)
      cout << setw(3) << i;
    cout << '\n';
    return;
  }
  for (int i = prev + 1; i <= n; i++) {
    nums.push_back(i);
    dfs(idx + 1, i);
    nums.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n - m + 1; i++) {
    nums.push_back(i);
    dfs(0, i);
    nums.pop_back();
  }
  return 0;
}