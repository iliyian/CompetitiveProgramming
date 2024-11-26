#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;

std::vector<int> pri, vis(N + 1);

bool ispa(std::string str) {
  std::string rev = str;
  std::reverse(rev.begin(), rev.end());
  return rev == str;
}

int check(std::string a, std::string b) {
  int ans = 0, k = 0, j;
  		for(j=0, k = 0;j < a.size();)
		{
			if(a[j] == b[k])
			{
				j++; k++;
			}
			else
			{
				j -= k - 1;
				k=0;
			}
			if(k==b.size())
			{
        ans++;
				k = 0;
			}
		}
  return ans;
}

void solve() {
  std::string s0, s1, s2, s3, s;

  std::getline(std::cin, s0);
  std::getline(std::cin, s1);
  std::getline(std::cin, s2);
  std::getline(std::cin, s3);
  std::getline(std::cin, s);

  std::cout << check(s0, s) << ' ';
  std::cout << check(s1, s) << ' ';
  std::cout << check(s2, s) << ' ';
  std::cout << check(s3, s) << ' ';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}