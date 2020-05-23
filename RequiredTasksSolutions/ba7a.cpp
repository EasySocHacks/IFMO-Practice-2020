#include <bits/stdc++.h>
using namespace std;

int n;
map <int, vector<pair<int, int>>> g;

pair<bool, int> dfs(int v, int destination, int weight, int parent) {
    if (v == destination) {
        return {true, weight};
    }

    for (auto x : g[v]) {
        int u = x.first;
        int w = x.second;

        if (u == parent) {
            continue;
        }

        auto ret = dfs(u, destination, weight + w, v);

        if (ret.first)
            return ret;
    }

    return {false, 0};
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin >> n;
    int v, u, w;

    while (cin >> v) {
        scanf("->%d:%d", &u, &w);

        g[v].push_back({u, w});
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << "0 ";
            } else {
                cout << dfs(i, j, 0, -1).second << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}
