#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/detail/default_ops.hpp>
#include <bits/stdc++.h>
#include <boost/multiprecision/fwd.hpp>
#include <ratio>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  using namespace boost::multiprecision;
  cpp_int a, b, ans = 1;
  std::cin >> a >> b;
  auto start = std::chrono::high_resolution_clock::now();

  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::cout << ans << '\n';
  // std::cout << ans.str().size() << '\n';
  std::cout << std::chrono::duration<double, std::milli>(end - start) << '\n';
  return 0;
}