#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;

struct par {
    int i, j, k;

    par() {}
    par(int i, int j, int k) : i(i), j(j), k(k) {}
};

string s1, s2, s3;

vector <vector <vector <int>>> dp;
vector <vector <vector <par>>> parent;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin >> s1 >> s2 >> s3;

    dp.resize(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, -INF)));
    parent.resize(s1.size() + 1, vector<vector<par>>(s2.size() + 1, vector<par>(s3.size() + 1, par(-1, -1, -1))));

    dp[0][0][0] = 0;

    for (int i = 0; i <= s1.size(); i++) {
        for (int j = 0; j <= s2.size(); j++) {
            for (int k = 0; k <= s3.size(); k++) {
                if (i == 0 && j == 0 && k == 0)
                    continue;

                if (i >= 1 && j >= 1 && k >= 1 && dp[i][j][k] < dp[i - 1][j - 1][k - 1] + (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1] ? 1 : 0)) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1] ? 1 : 0);
                    parent[i][j][k] = par(i -1, j - 1, k - 1);
                }

                for (int x = 0; x < 7; x++) {
                    if ((x & (1 << 0)) != 0 && i < 1)
                        continue;
                    if ((x & (1 << 1)) != 0 && j < 1)
                        continue;
                    if ((x & (1 << 2)) != 0 && k < 1)
                        continue;

                    if (dp[i][j][k] < dp[i - ((x & (1 << 0)) != 0 ? 1 : 0)][j - ((x & (1 << 1)) != 0 ? 1 : 0)][k - ((x & (1 << 2)) != 0 ? 1 : 0)]) {
                        dp[i][j][k] = dp[i - ((x & (1 << 0)) != 0 ? 1 : 0)][j - ((x & (1 << 1)) != 0 ? 1 : 0)][k - ((x & (1 << 2)) != 0 ? 1 : 0)];
                        parent[i][j][k] = par(i - ((x & (1 << 0)) != 0 ? 1 : 0), j - ((x & (1 << 1)) != 0 ? 1 : 0), k - ((x & (1 << 2)) != 0 ? 1 : 0));
                    }
                }
            }
        }
    }

    string ans1 = "", ans2 = "", ans3 = "";

    int i = s1.size();
    int j = s2.size();
    int k = s3.size();

    cout << dp[i][j][k] << "\n";

    while (!(i == 0 && j == 0 && k == 0)) {
        int newI = parent[i][j][k].i;
        int newJ = parent[i][j][k].j;
        int newK = parent[i][j][k].k;

        if (i != newI && j != newJ && k != newK) {
            ans1 = s1[i - 1] + ans1;
            ans2 = s2[j - 1] + ans2;
            ans3 = s3[k - 1] + ans3;
        } else {
            if (i == newI) {
                ans1 = "-" + ans1;
            } else {
                ans1 = s1[i - 1] + ans1;
            }

            if (j == newJ) {
                ans2 = "-" + ans2;
            } else {
                ans2 = s2[j - 1] + ans2;
            }

            if (k == newK) {
                ans3 = "-" + ans3;
            } else {
                ans3 = s3[k - 1] + ans3;
            }
        }

        i = newI;
        j = newJ;
        k = newK;
    }

    cout << ans1 << "\n" << ans2 << "\n" << ans3;

    return 0;
}
