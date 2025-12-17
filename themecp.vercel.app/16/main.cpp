#include <bits/stdc++.h>

std::mt19937_64 rd(std::random_device{}());

int main() {
  std::vector<std::array<int, 3>> alloc;
  std::vector<std::array<int, 2>> free;
  auto print = [&]() {
    std::cout << "Allocated: ";
    for (auto &[id, start, len] : alloc) {
      std::print("Task %d start %d len %d", id, start, len);
    }
    std::cout << "Free: ";
    for (auto &[start, len] : free) {
      std::print("start %d len %d", start, len);
    }
    std::cout << std::endl;
  };
  int mx = 1 << 20;
  free.push_back({0, mx});
  while (1) {
    int op = rd() % 2;
    if (op == 1) { // insert

    } else { // release
      int idx = rd() % alloc.size();
      std::print("Release task %d", idx);
      auto [id, start, len] = alloc[idx];
      for ()
      alloc.erase(alloc.begin() + idx);
    }
  }
}