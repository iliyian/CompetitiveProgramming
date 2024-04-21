#include <iostream>
#include <vector>
#include <array>
#include <numeric>
using namespace std;

struct Num {
  int n, idx, m1, area;
};

// array<vector<Num>, 4> areas{};
vector<Num> nums;

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n * 2; i++) {
    int a;
    cin >> a;
    int m1 = i % 2, m2 = i % k;
    nums.push_back(Num{a, i, m1, m2});
    // areas[m2].push_back(Num{a, i, m1});
  }
  array<int, 10001> accus{};
  // array<int, 4> count{};
  for (int i = 0; i < nums.size(); i++) {
    accus[nums[i].area] += nums[i].n;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i].m1 == 1) {
      nums[i].n = accus[nums[i].area] % nums[i].idx;
    }
  }

  for (int i = 0; i < nums.size(); i++)
    cout << nums[i].n << " ";

  return 0;
}