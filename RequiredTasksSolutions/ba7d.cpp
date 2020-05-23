#include <bits/stdc++.h>
using namespace std;

const double INF = 1e9;

int n;
vector<vector<double>> matrix;

vector<vector<pair<int, double>>> g;
vector<double> height;
vector<bool> used;
vector<int> sz;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin >> n;

    matrix.resize(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    g.resize(n, vector<pair<int, double>>(0));
    height.resize(n, 0);
    used.resize(n, false);
    sz.resize(n, 1);

    for (int q = 0; q < n - 1; q++) {
        double minLength = INF;
        int a, b;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                if (i == j)
                    continue;

                if (used[i] || used[j])
                    continue;

                if (minLength > matrix[i][j]) {
                    minLength = matrix[i][j];

                    a = i;
                    b = j;
                }
            }
        }

        used[a] = true;
        used[b] = true;

        g.push_back(vector<pair<int, double>>(0));
        int v = g.size() - 1;

        height.push_back(matrix[a][b] / 2.0);

        used.push_back(false);

        sz.push_back(sz[a] + sz[b]);

        g[v].push_back({a, height[v] - height[a]});
        g[v].push_back({b, height[v] - height[b]});

        g[a].push_back({v, height[v] - height[a]});
        g[b].push_back({v, height[v] - height[b]});

        for (int i = 0; i < matrix.size(); i++) {
            if (used[i]) {
                matrix[i].push_back(-1);
            } else {
                matrix[i].push_back((sz[a] * matrix[a][i] + sz[b] * matrix[b][i]) / (double) (sz[a] + sz[b]));
            }
        }

        matrix.push_back(vector<double>(0));

        for (int i = 0; i < matrix.size() - 1; i++) {
            matrix[matrix.size() - 1].push_back(matrix[i][matrix.size() - 1]);
        }

        matrix[matrix.size() - 1].push_back(0);
    }

    cout.precision(10);
    for (int v = 0; v < g.size(); v++) {
        for (auto node : g[v]) {
            int u = node.first;
            double len = node.second;

            cout << v << "->" << u << ":" << len << "\n";
        }
    }

    return 0;
}
