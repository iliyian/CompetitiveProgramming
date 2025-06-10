#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
const int MAX_SHIFT = 60, MAX_OPERATIONS = 60;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  const unsigned long long INF = numeric_limits<unsigned long long>::max();
  vector<vector<unsigned long long>> min_cost(
      MAX_SHIFT + 1, vector<unsigned long long>(MAX_SHIFT + 1, INF));
  min_cost[0][0] = 0;
  for (int operation = 1; operation <= MAX_OPERATIONS; operation++) {
    vector<vector<unsigned long long>> updated_cost = min_cost;
    for (int shift_x = 0; shift_x <= MAX_SHIFT; shift_x++)
      for (int shift_y = 0; shift_y <= MAX_SHIFT; shift_y++)
        if (min_cost[shift_x][shift_y] != INF) {
          if (shift_x + operation <= MAX_SHIFT)
            updated_cost[shift_x + operation][shift_y] =
                min(updated_cost[shift_x + operation][shift_y],
                    min_cost[shift_x][shift_y] + (1ULL << operation));
          if (shift_y + operation <= MAX_SHIFT)
            updated_cost[shift_x][shift_y + operation] =
                min(updated_cost[shift_x][shift_y + operation],
                    min_cost[shift_x][shift_y] + (1ULL << operation));
        }
    min_cost = move(updated_cost);
  }
  struct ShiftCombo {
    int shift_x, shift_y;
    unsigned long long cost;
  };
  vector<ShiftCombo> possible_shifts;
  for (int shift_x = 0; shift_x <= MAX_SHIFT; shift_x++)
    for (int shift_y = 0; shift_y <= MAX_SHIFT; shift_y++)
      if (min_cost[shift_x][shift_y] != INF)
        possible_shifts.push_back(
            {shift_x, shift_y, min_cost[shift_x][shift_y]});
  int test_cases;
  cin >> test_cases;
  while (test_cases--) {
    unsigned long long value_x, value_y;
    cin >> value_x >> value_y;
    if (value_x == value_y) {
      cout << 0 << "\n";
      continue;
    }
    unsigned long long optimal_cost = INF;
    for (auto &shift : possible_shifts)
      if ((value_x >> shift.shift_x) == (value_y >> shift.shift_y))
        optimal_cost = min(optimal_cost, shift.cost);
    cout << optimal_cost << "\n";
  }
  return 0;
}