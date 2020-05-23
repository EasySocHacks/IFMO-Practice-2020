#include <bits/stdc++.h>
using namespace std;

string s1, s2;
vector <vector<int>> dp;
vector <vector<pair<int, int>>> par;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin >> s1 >> s2;

    dp.resize(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    par.resize(s1.size() + 1, vector<pair<int, int>>(s2.size() + 1, {-1, -1}));

    for (int i = 0; i <= s1.size(); i++) {
        for (int j = 0; j <= s2.size(); j++) {
            if (i == 0 && j == 0)
                continue;

            if (i >= 1 && j >= 1 && s1[i - 1] == s2[j - 1]) {
                if (dp[i][j] <= dp[i - 1][j - 1] + 1) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    par[i][j] = {i - 1, j - 1};
                }
            } else {
                if (i >= 1 && dp[i][j] <= dp[i - 1][j]) {
                    dp[i][j] = dp[i - 1][j];
                    par[i][j] = {i - 1, j};
                }

                if (j >= 1 && dp[i][j] <= dp[i][j - 1]) {
                    dp[i][j] = dp[i][j - 1];
                    par[i][j] = {i, j - 1};
                }
            }
        }
    }

    int i = s1.size(), j = s2.size();
    string ans = "";

    while (!(i == 0 && j == 0)) {
        int newI = par[i][j].first;
        int newJ = par[i][j].second;

        if (dp[i][j] != dp[newI][newJ]) {
            ans = s1[i - 1] + ans;
        }

        i = newI;
        j = newJ;
    }

    cout << ans;

    return 0;
}
