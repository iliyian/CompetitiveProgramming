  #include<bits/stdc++.h>
  #define int long long
  #define umap unordered_map
  const int MAXN = 5e6 + 7;
  using namespace std;
  void solve() {
    umap<int,int> mp;
    int n,w0;
    cin >> n >> w0;
    vector<int> sum(n+5,0),s(n+5,0),fa(n+5,0),is(n + 1, 0);
    int cnt = 2,zhu = 2;
    sum[2] = w0; fa[1] = 1; fa[2] = 2;
    is[2] = is[1] = 1;
    int sum_a = 0, sum_b = 0;
    int ans = w0;
    while(n--)
    {
      int op;
      cin >> op;
      if(op == 1) 
      {
        int w; cin >> w;
        sum[++cnt] = sum[zhu] + w;
        zhu = cnt;
        is[cnt] = 1;
        fa[zhu] = zhu; ans += w;
        sum_b = 0;
      }
      else if(op == 2){
        int x,w;
        cin >> x >> w;
        fa[++cnt] = fa[x];
        s[cnt] = (is[x] ? 0 : s[x]) + w;
        s[fa[cnt]] = std::max(s[fa[cnt]], s[cnt]);
        if(s[fa[cnt]] == sum[fa[cnt]]) sum_a = max(s[fa[cnt]],sum_a);
        if(s[fa[cnt]] == ans-sum[fa[cnt]]) sum_b = max(s[fa[cnt]],sum_b);
      }
      else {
        cout << max(0LL,ans - sum_a - sum_b) << '\n';
      }
    }
  }
  signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    std::cin >> t;

    while (t--) {
      solve();
    }
    return 0;
  }
  