#include <bits/stdc++.h>
using namespace std;

int n;
vector <string> vec;
vector <vector<int>> g;

string ans = "";
vector <bool> hasParent;
vector <bool> used;

void dfs(int v) {
    used[v] = true;
    ans += vec[v].back();

    for (int u : g[v]) {
        if (used[u])
            continue;

        dfs(u);
        break;
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin >> n;

    string str;
    while (cin >> str) {
        vec.push_back(str);
    }

    g.resize(vec.size());
    hasParent.resize(vec.size(), false);
    used.resize(vec.size(), false);

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            if (i == j)
                continue;

            if (vec[i].substr(1) == vec[j].substr(0, n - 1)) {
                g[i].push_back(j);
            }
        }
    }

    int root = -1;

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < g[i].size(); j++) {
            hasParent[g[i][j]] = true;
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        if (!hasParent[i])
            root = i;
    }

    ans = vec[root].substr(0, n - 1);

    dfs(root);

    cout << ans;

    return 0;
}
