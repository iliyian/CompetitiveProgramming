#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
int n, sum = 0;

void dfs(int prev) {
  int rest = n - sum;
  if (rest == 0 && nums.size() > 1) {
    cout << nums[0];
    for (int i = 1; i < nums.size(); i++) {
      cout << '+' << nums[i];
    }
    cout << '\n';
  }
  for (int i = prev; i <= rest; i++) {
    nums.push_back(i);
    sum += i;
    dfs(i);
    sum -= i;
    nums.pop_back();
  }
}

int main() {
  // int n;
  cin >> n;
  dfs(1);
  return 0;
}