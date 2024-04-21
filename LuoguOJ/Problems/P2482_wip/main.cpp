#include <bits/stdc++.h>
using namespace std;

struct Pig {
  string id;
  string card;
  int life = 4;
  bool weaponed = false;
  bitset<10> is_evil, is_kind;

  int find(char c) {
    for (int i = 0; i < card.size(); i++) {
      if (card[i] == c)
        return i;
    }
    return -1;
  }
} pigs[10];

queue<int> cards;

int n, m;

bool askfor(char c, int i, int j) {
  for (int k = i + 1; k != i; ++k %= n) {
    switch (c) {
      case 'E':
        if (pigs[k].is_evil[j]) {
          int pos = pigs[k].find('J');
          if (pos != -1) {
            pigs[k].card.erase(pos);
            askfor('')
            return true;
          }
        }
      break;
      case 'K':
        if (pigs[k].is_kind[j]) {
          int pos = pigs[k].find('J');
          if (pos != -1) {
            pigs[k].card.erase(pos);
            return true;
          }
        }
      break;
    }
  }
  return false;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> pigs[i].id;
    if (pigs[i].id == "FP") {
      pigs[i].is_evil[0] == true;
    } else if (pigs[i].id == "ZP") {
      pigs[i].is_kind[0] = true;
    }
    for (int i = 0; i < 4; i++) {
      char card;
      cin >> card;
      pigs[i].card.push_back(card);
    }
  }
  for (int i = 0; i < m; i++) {
    char card;
    cin >> card;
    cards.push(card);
  }

  int cur = 0;
  while (true) {
    Pig &p = pigs[cur];
    for (int i = 0; i < 2; i++)
      p.card.push_back(cards.front()), cards.pop();

    for (int i = 0; i < p.card.size(); i++) {
      char c = p.card[i];
      bool used_k = false;
      switch (c) {
        case 'P':
          if (p.life != 4) {
            p.card.erase(i, 1);
            p.life++;
            i--;
          }
        break;
        case 'K':
          for (int j = i - 1; j <= i + 1; j++) {
            if (j == i) continue;
            if ((!used_k || p.weaponed) && p.is_evil[j]) {
              used_k = true;
              p.card.erase(i, 1); i--;
              int pos = pigs[j].find('D');
              if (pos == -1) {
                pigs[j].life--;
              } else {
                pigs[j].card.erase(pos, 1);
              }
            }
          }
        case 'D':
          continue;
        break;
        case 'F':
          for (int j = i + 1; j != i; ++j %= n) {
            if (p.is_evil[j]) {
              p.card.erase(i, 1); i--;
              
              if (askfor('K'))

              int pos1, pos2;
              do {
                pos1 = pigs[j].find('K');
                pos2 = p.find('K');
                if (pos1 == -1) {
                  pigs[j].life--;
                } else if (pos2 == -1) {
                  p.life--;
                }
              } while (pos1 != -1 && pos2 != -1);
            }
          }
      }
    }
  }

}