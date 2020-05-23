#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int N;
vector<vector<int>> matrix;

int getLimb(int n) {
    int ans = INF;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i == n - 1 || j == n - 1) {
                continue;
            }

            ans = min(ans, (matrix[n - 1][i] + matrix[n - 1][j] - matrix[j][i]) / 2);
        }
    }

    return ans;
}

set <pair<int, int>> emptySet;

pair<bool, vector<set<pair<int, int>>>> addNode(vector<set<pair<int, int>>> g, int v, int J, int x, int w, int p, int d, int limb) {
    if (v == J) {
        if (d == x) {
            g[v].insert({w, limb});
            g[w].insert({v, limb});
        }

        return {true, g};
    }

    for (auto xu : g[v]) {
        int u = xu.first;
        int wu = xu.second;

        if (u == p)
            continue;

        auto ans = addNode(g, u, J, x, w, v, d + wu, limb);

        if (ans.first) {
            if (d == x) {
                g[v].insert({w, limb});
                g[w].insert({v, limb});
            } else if (x > d && x < d + wu) {
                    g.push_back(emptySet);

                    g[v].erase({u, wu});
                    g[u].erase({v, wu});

                    int newNode = g.size() - 1;

                    g[v].insert({newNode, x - d});
                    g[newNode].insert({v, x - d});

                    g[u].insert({newNode, d + wu - x});
                    g[newNode].insert({u, d + wu - x});

                    g[w].insert({newNode, limb});
                    g[newNode].insert({w, limb});
            } else {
                return ans;
            }

            return {true, g};
        }
    }

    return {false, g};
}

vector<set<pair<int, int>>> additivePhylogeny(int n) {
    if (n == 2) {
        vector<set<pair<int, int>>> ans(N, emptySet);

        ans[0].insert({1, matrix[0][1]});
        ans[1].insert({0, matrix[1][0]});

        return ans;
    }

    int limbLength = getLimb(n);

    int I = -1, J = -1;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (i == j)
                continue;

            if (matrix[i][j] == matrix[i][n - 1] + matrix[n - 1][j] - 2 * limbLength) {
                I = i;
                J = j;
                break;
            }
        }

        if (I != -1)
            break;
    }

    vector<set<pair<int, int>>> g = additivePhylogeny(n - 1);
    g = addNode(g, I, J, matrix[I][n - 1] - limbLength, n - 1, -1, 0, limbLength).second;

    return g;
}

int main () {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin >> N;

    matrix.resize(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<set<pair<int, int>>> g = additivePhylogeny(N);

    for (int v = 0; v < g.size(); v++) {
        for (auto x : g[v]) {
            int u = x.first;
            int w = x.second;

            cout << v << "->" << u << ":" << w << "\n";
        }
    }

    return 0;
}
