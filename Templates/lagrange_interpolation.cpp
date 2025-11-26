auto lagrange_interpolation(const std::vector<int> &x,
                                        const std::vector<Z> &y,
                                      int k) {
  const int n = x.size();
  std::vector<Z> M(n + 1), px(n, 1), f(n);
  M[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j >= 0; --j) {
      M[j + 1] = M[j] + M[j + 1];
      M[j] = -M[j] * x[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        px[i] = px[i] * (x[i] - x[j]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    Z t = y[i] * px[i].inv(), k = M[n];
    for (int j = n - 1; j >= 0; --j) {
      f[j] = f[j] + k * t;
      k = M[j] + k * x[i];
    }
  }
  Z ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ans = ans * k + f[i];
  }
  return std::make_pair(f, ans);
}