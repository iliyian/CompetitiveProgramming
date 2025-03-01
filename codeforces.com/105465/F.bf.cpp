#include <bits/stdc++.h>
#define int long long

int arr[500010];
int num=0;
int c[500010];
void msort(std::vector<int> &a,int left,int right)
{
    if(left==right)return;
    int mid=left+(right-left)/2,goal=left;
    int begin1=left,begin2=mid+1,end1=mid,end2=right;
    msort(a,begin1,end1);
    msort(a,begin2,end2);
    while(begin1<=end1&&begin2<=end2)
    {
        if(arr[begin1]<=arr[begin2]){c[goal++]=arr[begin1++];}
        else
        {
            c[goal++]=arr[begin2++];
            num+=mid-begin1+1; //此时begin1右侧剩下的左序列的值都比 arr[begin2]大，都是逆序数
        }
    }
    while(begin1<=end1){c[goal++]=arr[begin1++];}
    while(begin2<=end2){c[goal++]=arr[begin2++];}
    for(int i=left;i<=right;i++){arr[i]=c[i];}
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int &i : a) std::cin >> i;
  std::vector<int> d(n + 1);
  auto add = [&](int x, int c) {
    x++;
    for (int i = x; i <= n; i += i & -i) d[i] += c;
  };
  auto query = [&](int x) {
    int ans = 0;
    x++;
    for (int i = x; i > 0; i -= i & -i) ans += d[i];
    return ans;
  };
  int ans = LLONG_MAX / 3;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[j] ^= i;
    }
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      cnt += query(n - 1) - query(a[j]);
      add(a[j], 1);
    }
    ans = std::min(ans, cnt + (i != 0));
    std::fill(d.begin(), d.end(), 0);
    std::cerr << ans << '\n';
    for (int j = 0; j < n; j++) {
      a[j] ^= i;
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}