#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, leaf;
vector<vector<int>> matrix;

int main() {
    freopen("in.txt", "r", stdin);

    cin >> n >> leaf;

    matrix.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int ans = INF;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i == leaf || j == leaf) {
                continue;
            }

            ans = min(ans, (matrix[leaf][i] + matrix[leaf][j] - matrix[j][i]) / 2);
        }
    }

    cout << ans;

    return 0;
}
