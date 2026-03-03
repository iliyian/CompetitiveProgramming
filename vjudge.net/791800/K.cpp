/*

LLLLLLLLLLL             IIIIIIIIIIYYYYYYY       YYYYYYYIIIIIIIIII               AAA               NNNNNNNN        NNNNNNNN
L:::::::::L             I::::::::IY:::::Y       Y:::::YI::::::::I              A:::A              N:::::::N       N::::::N
L:::::::::L             I::::::::IY:::::Y       Y:::::YI::::::::I             A:::::A             N::::::::N      N::::::N
LL:::::::LL             II::::::IIY::::::Y     Y::::::YII::::::II            A:::::::A            N:::::::::N     N::::::N
  L:::::L                 I::::I  YYY:::::Y   Y:::::YYY  I::::I             A:::::::::A           N::::::::::N    N::::::N
  L:::::L                 I::::I     Y:::::Y Y:::::Y     I::::I            A:::::A:::::A          N:::::::::::N   N::::::N
  L:::::L                 I::::I      Y:::::Y:::::Y      I::::I           A:::::A A:::::A         N:::::::N::::N  N::::::N
  L:::::L                 I::::I       Y:::::::::Y       I::::I          A:::::A   A:::::A        N::::::N N::::N N::::::N
  L:::::L                 I::::I        Y:::::::Y        I::::I         A:::::A     A:::::A       N::::::N  N::::N:::::::N
  L:::::L                 I::::I         Y:::::Y         I::::I        A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N
  L:::::L                 I::::I         Y:::::Y         I::::I       A:::::::::::::::::::::A     N::::::N    N::::::::::N
  L:::::L         LLLLLL  I::::I         Y:::::Y         I::::I      A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N
LL:::::::LLLLLLLLL:::::LII::::::II       Y:::::Y       II::::::II   A:::::A             A:::::A   N::::::N      N::::::::N
L::::::::::::::::::::::LI::::::::I    YYYY:::::YYYY    I::::::::I  A:::::A               A:::::A  N::::::N       N:::::::N
L::::::::::::::::::::::LI::::::::I    Y:::::::::::Y    I::::::::I A:::::A                 A:::::A N::::::N        N::::::N
LLLLLLLLLLLLLLLLLLLLLLLLIIIIIIIIII    YYYYYYYYYYYYY    IIIIIIIIIIAAAAAAA                   AAAAAAANNNNNNNN         NNNNNNN

 * 
 * ==============================================================================
 * @Author  : iliyian
 * @File    : K.cpp
 * @Time    : 2026-02-25 15:41:31
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::string ans_str = "0accc";

int ask(int d, std::string s) {
  std::cout << "? " << d << ' ' << s << std::endl;
  int ans;
  // ans = (s[0] == ans_str[d]) + (s[1] == ans_str[d + 1]);
  std::cin >> ans;
  // std::cout << ans << std::endl;
  return ans;
}

std::map<std::string, std::string> mp;

int check(std::string s,int pos,std::string q){
	int tot=0;
	if(s[pos]==q[0])tot++;
	if(s[pos+1]==q[1])tot++;
	return tot;
}

void init(){
	for(int i=0;i<=2;++i){
		for(int j=0;j<=2;++j){
			for(int k=0;k<=2;++k){
				std::string s="";
				s.push_back('a'+i),s.push_back('a'+j),s.push_back('a'+k);
				std::string res="";
				res.push_back('0'+check(s,0,"aa"));
				res.push_back('0'+check(s,0,"ba"));
				res.push_back('0'+check(s,1,"ba"));
				res.push_back('0'+check(s,1,"bb"));
//				std::cerr<<s<<" "<<res<<"\n";
				mp[res]=s;
			}
		}
	}
} 

void solve(int n) {
  // int n;
  // n = ans_str.size() - 1;
  // std::cin >> n;
  init(); 
  std::string ans="";
  for (int l = 1; l + 2 <= n; l += 3) {
    int r = l + 2;
    std::string res="";
    res.push_back('0'+ask(l, "aa"));
    res.push_back('0'+ask(l, "ba"));
    res.push_back('0'+ask(l + 1, "ba"));
    res.push_back('0'+ask(l + 1, "bb"));
//    std::cerr<<mp[res]<<"\n";
    ans+=mp[res];
  }
  if (n % 3 == 1) {
  	bool fg = 0;
    std::string st="";
    st.push_back(ans[n-2]);
    for (char c = 'a'; c <= 'b'; c++) {
      st.push_back(c);
      if (ask(n - 1, st) == 2) {
        ans.push_back(c);
        fg = 1;
        break;
      }
      st.pop_back();
    }
    if(!fg){
    	ans.push_back('c');
	}
  }
  if (n % 3 == 2) {
    int l = n - 1;
    int x = ask(l, "aa");
    if (x == 0) {
      int y = ask(l, "bb");
      if (y == 0) {
        ans.push_back('c'), ans.push_back('c');
      } else if (y == 1) {
        int z = ask(l, "bc");
        if (z == 0) {
          ans.push_back('c'), ans.push_back('b');
        } else {
          ans.push_back('b'), ans.push_back('c');
        }
      } else {
        ans.push_back('b'), ans.push_back('b');
      }
    } else if (x == 1) {
      int y = ask(l, "ab");
      if (y == 0) {
        int z = ask(l, "ba");
        if (z == 1) {
          ans.push_back('c'), ans.push_back('a');
        } else {
          ans.push_back('b'), ans.push_back('a');
        }
      } else if (y == 1) {
        ans.push_back('a'), ans.push_back('c');
      } else {
        ans.push_back('a'), ans.push_back('b');
      }
    } else {
      ans.push_back('a'), ans.push_back('a');
    }
  }
  std::cout << "! " << ans << std::endl;
}

int32_t main() {
//  std::cin.tie(nullptr)->sync_with_stdio(false);

//  bool ok = false;
//  
//  std::vector<std::array<int, 3>> s(27);
//  for (int i = 0; i < 27; i++) {
//    s[i][0] = i % 3;
//    s[i][1] = i / 3 % 3;
//    s[i][2] = i / 9 % 3;
//  }
//
//  std::vector<std::array<int, 2>> v;
//  auto dfs = [&](auto self, int dep) -> void {
//    if (ok) return;
//    if (dep == 5) {
//      std::vector<int> ans(27);
//      for (int i = 0; i < 27; i++) {
//        int resp = 0, p = 1;
//        for (int j = 0; j < 4; j++) {
//          auto [d, str] = v[j];
//          int u1 = str / 3, u2 = str % 3;
//          int ans = (s[i][d] == u1) + (s[i][d + 1] == u2);
//          resp = resp + ans * p;
//          p = p * 3;
//        }
//        ans[i] = resp;
//      }
//      std::set<int> st;
//      for (auto i : ans) {
//        st.insert(i);
//      }
//      if (st.size() == 27) {
//        ok = true;
//        for (auto [d, str] : v) {
//          std::cout << d + 1 << ' ' << char(str / 3 + 'a') << char(str % 3 + 'a') << '\n';
//        }
//        for (int i = 0; i < 27; i++) {
//          int resp = ans[i];
//          int k = i;
//          std::string anss;
//          for (int j = 0; j < 3; j++) {
//            // std::cout << char(k % 3 + 'a');
//            anss.push_back(k % 3 + 'a');
//            k /= 3;
//          }
//          std::ranges::reverse(anss);
//          std::cout << anss;
//          mp[i] = anss;
//          std::cout << ' ';
//          // std::cout << resp << ' ';
//          for (int j = 0; j < 4; j++) {
//            std::cout << resp % 3 << ' ';
//            resp /= 3;
//          }
//          std::cout << '\n';
//        }
//        std::cout << '\n'; 
//      }
//      return;
//    }
//    for (int d = 0; d < 2; d++) {
//      for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//          v.push_back({d, i * 3 + j});
//          self(self, dep + 1);
//          if (ok) break;
//          v.pop_back();
//        }
//        if (ok) break;
//      }
//      if (ok) break;
//    }
//  };
//  dfs(dfs, 1);

  int t = 1;
  // std::cin >> t;

  int n;

  while (std::cin >> n) {
    if (n == 0) break;
    solve(n);
  }

  return 0;
}