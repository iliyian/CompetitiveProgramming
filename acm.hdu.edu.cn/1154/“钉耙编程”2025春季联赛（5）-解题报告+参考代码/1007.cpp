#include <bits/stdc++.h>
const int BUF_SIZE = 1 << 10;
const int N = 1e5 + 7;
int C = 1;

struct qxx
{
    int to, nxt;
};
char buf[BUF_SIZE];
int head[N], edge_cnt = 1;
qxx edge[N * 4];
void add_edge(int u, int v)
{
    edge[edge_cnt] = {v, head[u]};
    head[u] = edge_cnt++;
}

void clear(int n)
{
    std::fill(head, head + n + 1, 0);
    edge_cnt = 1;
}

// COMMIT,
// BRANCH,
// MERGE,
// CHECKOUT,
// RESET
void solve()
{
    int T;
    std::cin >> T;

    C++;
    clear(T + 1);
    using BRANCH = std::pair<std::string, int>;
    int node = 1;
    std::list<BRANCH> branches;
    // std::vector<BRANCH> branches;
    std::map<std::string, std::list<BRANCH>::iterator> mp;
    branches.emplace_front("main", 1);
    auto HEAD = branches.begin();
    mp["main"] = HEAD;
    using B = std::bitset<5056>;
    std::vector<B> PARS(T + 1);
    PARS[1][1] = 1;
    while (T--)
    {
        C++;
        std::string str;
        while (str.empty())
            std::getline(std::cin, str);
        std::istringstream ss(str);
        std::vector<std::string> tokens;
        for (; ss.getline(buf, BUF_SIZE, ' ');)
            tokens.push_back(buf);
        if (tokens[0] == "commit")
        {
            node++;
            PARS[node][node] = 1;
            auto &[_, p] = *HEAD;
            add_edge(node, p);
            PARS[node] |= PARS[p];
            p = node;
        }
        if (tokens[0] == "branch")
        {
            int u = HEAD->second;
            bool d = false;
            std::string name;
            for (auto s : tokens)
            {
                if (s == "branch")
                    continue;
                if (s == "-d")
                    d = true;
                else if (name.empty())
                    name = s;
                else
                    u = std::stoi(s);
            }
            if (d)
            {
                if (mp.count(name))
                {
                    assert(name != HEAD->first);
                    branches.erase(mp[name]);
                    mp.erase(name);
                }
            }
            else
            {
                if (!mp.count(name))
                {
                    branches.emplace_front(name, u);
                    mp[name] = branches.begin();
                }
            }
        }
        if (tokens[0] == "merge")
        {
            auto &[_, u] = *HEAD;
            std::string name;
            for (auto s : tokens)
            {
                if (s == "merge")
                    continue;
                name = s;
            }
            auto v = mp[name]->second;
            if ((((PARS[u] ^ PARS[v]) & PARS[u]).count() == 0)) // subtree
                u = v;
            else if (!(((PARS[u] ^ PARS[v]) & PARS[v]).count() == 0))
            {
                node++;
                add_edge(node,u);
                add_edge(node,v);
                PARS[node] = PARS[u] | PARS[v];
                PARS[node][node] = 1;
                u = node;
            }
            // node++;
            // add_edge(node, p);
            // add_edge(node, mp[name]->second);
            // p = node;
        }
        if (tokens[0] == "checkout")
        {
            std::string name;
            for (auto s : tokens)
            {
                if (s == "checkout")
                    continue;
                name = s;
            }
            HEAD = mp[name];
        }
        if (tokens[0] == "reset")
        {
            int u = HEAD->second;
            for (auto s : tokens)
            {
                if (s == "reset")
                    continue;
                u = std::stoi(s);
            }
            HEAD->second = u;
        }
    }
    std::cout << branches.size() << '\n';
    branches.sort([&](const BRANCH&a,const BRANCH&b)
     { return a.first < b.first; });
    for (auto [s,p] : branches)
        std::cout << s << ' ' << p << '\n';
    std::cout << node << '\n';
    for (int i = 1; i <= node; i++)
    {
        std::vector<int> ans;
        for (int j = head[i]; j; j = edge[j].nxt)
            ans.push_back(edge[j].to);
        std::sort(ans.begin(),ans.end());
        std::cout << ans.size() << ' ';
        for(auto it : ans)
            std::cout << it << ' ';
        std::cout << '\n';
    }
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data1.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--)
        solve();
    return 0;
}