#include <bits/stdc++.h>
#define N 15
#define M 2005
using namespace std;

vector<Pig> pigs(N + 1);
vector<char> deck(M + 1);
vector<bool> isZhong(N + 1), isFan(N + 1), isLeiFan(N + 1), weaponed(N + 1);

int n, m, deckid = 1;

struct Pig {
  char id;
  int life = 0, idx;
  vector<char> cards;
};

void rmcard(int pigid, int cardid) {
  pigs[pigid].cards.erase(pigs[pigid].cards.begin() + cardid);
}

void addcard(int cnt, int pig) {
  for (int i = 0; i < cnt; i++) {
    pigs[pig].cards.push_back(deck[deckid++]);
  }
};

int findcard(int pig, char card) {
  auto &cards = pigs[pig].cards;
  for (int i = 0; i < cards.size(); i++) {
    if (cards[i] == card) {
      return i;
    }
  }
  return -1ll;
};

bool canDo(int object, int subject, bool isGood) {    
  switch (pigs[subject].id) {
    case 'M': {
      if (isGood) {
        if (isZhong[object] || object == subject) {
          return true;
        }
      } else {
        if (isFan[object] || isLeiFan[object]) {
          return true;
        }
      }
    }
    break;
    case 'Z': {
      if (isGood) {
        if (isZhong[object] || pigs[object].id == 'M') {
          return true;
        }
      } else {
        if (isFan[object]) {
          return true;
        }
      }
    }
    break;
    case 'F': {
      if (isGood) {
        if (isFan[object]) {
          return true;
        }
      } else {
        if (isZhong[object] || pigs[object].id == 'M') {
          return true;
        }
      }
    }
    break;
  }
  return false;  
}

bool xianYinQin(int object, int subject) {
  if (isFan[object]) isFan[subject] = true;
  else isZhong[subject] = true;
};

bool biaoDiYi(int object, int subject) {
  if (isFan[object]) isZhong[subject] = true;
  else isFan[object] = true;
};

bool askWuXieKeJi(int object, int subject, bool isGood) {
  int cur = subject;
  do {
    int c = findcard(cur, 'J');
    if (c != -1 && canDo(object, cur, !isGood)) {
      if (!isGood) { // i对o献殷勤
        xianYinQin(object, cur);
      } else {
        biaoDiYi(object, cur);
      }
      rmcard(cur, c);
      return !askWuXieKeJi(subject, cur, !isGood);
    }
    cur = cur % pigs.size() + 1;
  } while (cur != subject);

  return false;
};

void checkend() {
  int fcnt = 0, mcnt = 0;
  for (auto &p : pigs) {
    fcnt += p.id == 'F';
    mcnt += p.id != 'F';
  }
  if (fcnt && mcnt) return;
  if (!fcnt) {
    cout << "FP\n";
  } else {
    cout << "MP\n";
  }
  vector<vector<char>> end(n + 1);
  for (auto &p : pigs) {
    for (auto card : p.cards) {
      end[p.idx].push_back(card);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (end[i].empty()) {
      cout << "DEAD\n";
    } else {
      for (auto card : end[i]) {
        cout << card << ' ';
      }
      cout << '\n';
    }
  }
  exit(0);
}

void kill(int object, int subject) {
  if (pigs[object].id == 'F') {
    addcard(3, subject);
  } else if (pigs[object].id == 'Z' && pigs[subject].id == 'M') {
    pigs[subject].cards.clear();
  }
  pigs.erase(pigs.begin() + object);
  checkend();
}

void hurt(int object, int subject) {
  biaoDiYi(object, subject);
  pigs[object].life--;
  if (!pigs[object].life) {
    int id = findcard(object, 'P');
    if (id == -1) {
      kill(object, subject);
    } else {
      rmcard(object, id);
    }
  }
}

void aoe(int from, char req) {
  for (int i = from % pigs.size() + 1; i != from; i = i % pigs.size() + 1) {
    if (askWuXieKeJi(i, from, false)) return;
    int id = findcard(i, req);
    if (id == -1) {
      hurt(i, from);
    } else {
      rmcard(i, id);
    }
  }
};

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string id;
    cin >> id;
    pigs[i].id = id.front();
    for (int j = 0; j < 4; j++) {
      char c;
      cin >> c;
      pigs[i].cards.push_back(c);
    }
    pigs[i].idx = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> deck[i];
  }

  for (int pigidx = 1;; pigidx = pigidx % pigs.size() + 1) {
    auto &[id, life, cards] = pigs[pigidx];
    addcard(2, pigidx);
    for (int cardid = 0; cardid < cards.size(); cardid++) {
      int card = cards[cardid];
      switch (card) {
        case 'P': {
          if (life != 4) {
            life++;
            rmcard(pigidx, cardid);
          }
          break;
        }
        case 'K': {
          if (weaponed[pigidx]) {
            rmcard
          }
          break;
        }
        case 'F': {
          
        }
        case 'W': {
          rmcard(pigidx, cardid);
          aoe(pigidx, 'D');
        }
        case 'N': {
          rmcard(pigidx, cardid);
          aoe(pigidx, 'K');
        }
        case 'Z': {
          rmcard(pigidx, cardid);
          weaponed[pigidx] = true;
        }
        default: break;
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  solve();

  return 0;
}