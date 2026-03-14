template<int ALPHA>
class DFA {
private:
    struct State {
        bool accept;
        int trans[ALPHA];
    };
    std::vector<State> states;
    int start;
public:
    DFA(int n = 2) : states(n), start(1) {}
     
    bool getAccept(int s) const {
        return states[s].accept;
    }
    void setAccept(int s, bool ac = true) {
        states[s].accept = ac;
    }
    int getTrans(int s, int c) const {
        return states[s].trans[c];
    }
    void setTrans(int s, int c, int t) {
        states[s].trans[c] = t;
    }
    int getStart() const {
        return start;
    }
    void setStart(int s) {
        start = s;
    }
    int addState() {
        states.push_back({});
        return states.size() - 1;
    }
    int size() const {
        return states.size();
    }
};

template<int ALPHA>
DFA<ALPHA> minimize(const DFA<ALPHA> &a) {
    const int n = a.size();
    std::vector<std::vector<int>> vec(2);
    std::vector<int> bel(n), siz(2);
    for (int i = 0; i < n; i++) {
        bel[i] = a.getAccept(i);
        vec[bel[i]].push_back(i);
        siz[bel[i]]++;
    }
     
    std::vector<std::array<std::vector<int>, ALPHA>> in(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ALPHA; j++) {
            in[a.getTrans(i, j)][j].push_back(i);
        }
    }
     
    auto rebuild = [&](int x) {
        if (siz[x] == vec[x].size()) {
            return;
        }
        vec[x].erase(std::remove_if(vec[x].begin(), vec[x].end(),
            [&](int s) {
                return bel[s] != x;
            }), vec[x].end());
    };
     
    std::queue<int> q;
    q.push(1);
     
    std::vector<int> tag(n), tags(2);
    std::vector<std::vector<int>> intersect(2);
    int tm = 0;
     
    for (int x = 1; x < vec.size(); x++) {
        rebuild(x);
         
        for (int c = 0; c < ALPHA; c++) {
            tm++;
             
            std::vector<int> v;
            for (auto i : vec[x]) {
                for (auto s : in[i][c]) {
                    if (tag[s] != tm) {
                        tag[s] = tm;
                        v.push_back(s);
                    }
                }
            }
             
            for (auto s : v) {
                intersect[bel[s]].clear();
            }
            for (auto s : v) {
                intersect[bel[s]].push_back(s);
            }
             
            for (auto s : v) {
                if (tags[bel[s]] == tm) {
                    continue;
                }
                if (siz[bel[s]] == intersect[bel[s]].size()) {
                    continue;
                }
                tags[bel[s]] = tm;
                int ns = vec.size();
                vec.push_back(intersect[bel[s]]);
                tags.push_back(tm);
                intersect.push_back({});
                siz.push_back(intersect[bel[s]].size());
                siz[bel[s]] -= siz[ns];
                for (auto x : intersect[bel[s]]) {
                    bel[x] = ns;
                }
            }
        }
    }
     
    DFA<ALPHA> b(vec.size());
    b.setStart(bel[a.getStart()]);
    for (int i = 0; i < n; i++) {
        b.setAccept(bel[i], a.getAccept(i));
        for (int j = 0; j < ALPHA; j++) {
            b.setTrans(bel[i], j, bel[a.getTrans(i, j)]);
        }
    }
    return b;
}