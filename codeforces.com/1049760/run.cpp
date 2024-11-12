#include <bits/stdc++.h>

int main(int argc, char **argv) {
  system(std::format("g++ {}.cpp -o {} -g -fsanitize=address,undefined", argv[1], argv[1]).c_str());
  system(std::format("./{} < {}.in", argv[1], argv[1]).c_str());
}