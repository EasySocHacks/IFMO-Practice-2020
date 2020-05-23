#include <bits/stdc++.h>
using namespace std;

const int LEN = 109;
const int INF = 1e8;
const int OPEN_PENALTY = 11;
const int CONTINUE_PENALTY = 1;

int matrix[26][26];
string s1, s2;

/*
0 - BOTH REDUCE
1 - J REDUCE
2 - I REDUCE
*/
int dp[LEN][LEN][3];
pair<pair<int, int>, int> parent[LEN][LEN][3];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    matrix[0][0] = 4;
    matrix[0][2] = 0;
    matrix[0][3] = -2;
    matrix[0][4] = -1;
    matrix[0][5] = -2;
    matrix[0][6] = 0;
    matrix[0][7] = -2;
    matrix[0][8] = -1;
    matrix[0][10] = -1;
    matrix[0][11] = -1;
    matrix[0][12] = -1;
    matrix[0][13] = -2;
    matrix[0][15] = -1;
    matrix[0][16] = -1;
    matrix[0][17] = -1;
    matrix[0][18] = 1;
    matrix[0][19] = 0;
    matrix[0][21] = 0;
    matrix[0][22] = -3;
    matrix[0][24] = -2;
    matrix[2][0] = 0;
    matrix[2][2] = 9;
    matrix[2][3] = -3;
    matrix[2][4] = -4;
    matrix[2][5] = -2;
    matrix[2][6] = -3;
    matrix[2][7] = -3;
    matrix[2][8] = -1;
    matrix[2][10] = -3;
    matrix[2][11] = -1;
    matrix[2][12] = -1;
    matrix[2][13] = -3;
    matrix[2][15] = -3;
    matrix[2][16] = -3;
    matrix[2][17] = -3;
    matrix[2][18] = -1;
    matrix[2][19] = -1;
    matrix[2][21] = -1;
    matrix[2][22] = -2;
    matrix[2][24] = -2;
    matrix[3][0] = -2;
    matrix[3][2] = -3;
    matrix[3][3] = 6;
    matrix[3][4] = 2;
    matrix[3][5] = -3;
    matrix[3][6] = -1;
    matrix[3][7] = -1;
    matrix[3][8] = -3;
    matrix[3][10] = -1;
    matrix[3][11] = -4;
    matrix[3][12] = -3;
    matrix[3][13] = 1;
    matrix[3][15] = -1;
    matrix[3][16] = 0;
    matrix[3][17] = -2;
    matrix[3][18] = 0;
    matrix[3][19] = -1;
    matrix[3][21] = -3;
    matrix[3][22] = -4;
    matrix[3][24] = -3;
    matrix[4][0] = -1;
    matrix[4][2] = -4;
    matrix[4][3] = 2;
    matrix[4][4] = 5;
    matrix[4][5] = -3;
    matrix[4][6] = -2;
    matrix[4][7] = 0;
    matrix[4][8] = -3;
    matrix[4][10] = 1;
    matrix[4][11] = -3;
    matrix[4][12] = -2;
    matrix[4][13] = 0;
    matrix[4][15] = -1;
    matrix[4][16] = 2;
    matrix[4][17] = 0;
    matrix[4][18] = 0;
    matrix[4][19] = -1;
    matrix[4][21] = -2;
    matrix[4][22] = -3;
    matrix[4][24] = -2;
    matrix[5][0] = -2;
    matrix[5][2] = -2;
    matrix[5][3] = -3;
    matrix[5][4] = -3;
    matrix[5][5] = 6;
    matrix[5][6] = -3;
    matrix[5][7] = -1;
    matrix[5][8] = 0;
    matrix[5][10] = -3;
    matrix[5][11] = 0;
    matrix[5][12] = 0;
    matrix[5][13] = -3;
    matrix[5][15] = -4;
    matrix[5][16] = -3;
    matrix[5][17] = -3;
    matrix[5][18] = -2;
    matrix[5][19] = -2;
    matrix[5][21] = -1;
    matrix[5][22] = 1;
    matrix[5][24] = 3;
    matrix[6][0] = 0;
    matrix[6][2] = -3;
    matrix[6][3] = -1;
    matrix[6][4] = -2;
    matrix[6][5] = -3;
    matrix[6][6] = 6;
    matrix[6][7] = -2;
    matrix[6][8] = -4;
    matrix[6][10] = -2;
    matrix[6][11] = -4;
    matrix[6][12] = -3;
    matrix[6][13] = 0;
    matrix[6][15] = -2;
    matrix[6][16] = -2;
    matrix[6][17] = -2;
    matrix[6][18] = 0;
    matrix[6][19] = -2;
    matrix[6][21] = -3;
    matrix[6][22] = -2;
    matrix[6][24] = -3;
    matrix[7][0] = -2;
    matrix[7][2] = -3;
    matrix[7][3] = -1;
    matrix[7][4] = 0;
    matrix[7][5] = -1;
    matrix[7][6] = -2;
    matrix[7][7] = 8;
    matrix[7][8] = -3;
    matrix[7][10] = -1;
    matrix[7][11] = -3;
    matrix[7][12] = -2;
    matrix[7][13] = 1;
    matrix[7][15] = -2;
    matrix[7][16] = 0;
    matrix[7][17] = 0;
    matrix[7][18] = -1;
    matrix[7][19] = -2;
    matrix[7][21] = -3;
    matrix[7][22] = -2;
    matrix[7][24] = 2;
    matrix[8][0] = -1;
    matrix[8][2] = -1;
    matrix[8][3] = -3;
    matrix[8][4] = -3;
    matrix[8][5] = 0;
    matrix[8][6] = -4;
    matrix[8][7] = -3;
    matrix[8][8] = 4;
    matrix[8][10] = -3;
    matrix[8][11] = 2;
    matrix[8][12] = 1;
    matrix[8][13] = -3;
    matrix[8][15] = -3;
    matrix[8][16] = -3;
    matrix[8][17] = -3;
    matrix[8][18] = -2;
    matrix[8][19] = -1;
    matrix[8][21] = 3;
    matrix[8][22] = -3;
    matrix[8][24] = -1;
    matrix[10][0] = -1;
    matrix[10][2] = -3;
    matrix[10][3] = -1;
    matrix[10][4] = 1;
    matrix[10][5] = -3;
    matrix[10][6] = -2;
    matrix[10][7] = -1;
    matrix[10][8] = -3;
    matrix[10][10] = 5;
    matrix[10][11] = -2;
    matrix[10][12] = -1;
    matrix[10][13] = 0;
    matrix[10][15] = -1;
    matrix[10][16] = 1;
    matrix[10][17] = 2;
    matrix[10][18] = 0;
    matrix[10][19] = -1;
    matrix[10][21] = -2;
    matrix[10][22] = -3;
    matrix[10][24] = -2;
    matrix[11][0] = -1;
    matrix[11][2] = -1;
    matrix[11][3] = -4;
    matrix[11][4] = -3;
    matrix[11][5] = 0;
    matrix[11][6] = -4;
    matrix[11][7] = -3;
    matrix[11][8] = 2;
    matrix[11][10] = -2;
    matrix[11][11] = 4;
    matrix[11][12] = 2;
    matrix[11][13] = -3;
    matrix[11][15] = -3;
    matrix[11][16] = -2;
    matrix[11][17] = -2;
    matrix[11][18] = -2;
    matrix[11][19] = -1;
    matrix[11][21] = 1;
    matrix[11][22] = -2;
    matrix[11][24] = -1;
    matrix[12][0] = -1;
    matrix[12][2] = -1;
    matrix[12][3] = -3;
    matrix[12][4] = -2;
    matrix[12][5] = 0;
    matrix[12][6] = -3;
    matrix[12][7] = -2;
    matrix[12][8] = 1;
    matrix[12][10] = -1;
    matrix[12][11] = 2;
    matrix[12][12] = 5;
    matrix[12][13] = -2;
    matrix[12][15] = -2;
    matrix[12][16] = 0;
    matrix[12][17] = -1;
    matrix[12][18] = -1;
    matrix[12][19] = -1;
    matrix[12][21] = 1;
    matrix[12][22] = -1;
    matrix[12][24] = -1;
    matrix[13][0] = -2;
    matrix[13][2] = -3;
    matrix[13][3] = 1;
    matrix[13][4] = 0;
    matrix[13][5] = -3;
    matrix[13][6] = 0;
    matrix[13][7] = 1;
    matrix[13][8] = -3;
    matrix[13][10] = 0;
    matrix[13][11] = -3;
    matrix[13][12] = -2;
    matrix[13][13] = 6;
    matrix[13][15] = -2;
    matrix[13][16] = 0;
    matrix[13][17] = 0;
    matrix[13][18] = 1;
    matrix[13][19] = 0;
    matrix[13][21] = -3;
    matrix[13][22] = -4;
    matrix[13][24] = -2;
    matrix[15][0] = -1;
    matrix[15][2] = -3;
    matrix[15][3] = -1;
    matrix[15][4] = -1;
    matrix[15][5] = -4;
    matrix[15][6] = -2;
    matrix[15][7] = -2;
    matrix[15][8] = -3;
    matrix[15][10] = -1;
    matrix[15][11] = -3;
    matrix[15][12] = -2;
    matrix[15][13] = -2;
    matrix[15][15] = 7;
    matrix[15][16] = -1;
    matrix[15][17] = -2;
    matrix[15][18] = -1;
    matrix[15][19] = -1;
    matrix[15][21] = -2;
    matrix[15][22] = -4;
    matrix[15][24] = -3;
    matrix[16][0] = -1;
    matrix[16][2] = -3;
    matrix[16][3] = 0;
    matrix[16][4] = 2;
    matrix[16][5] = -3;
    matrix[16][6] = -2;
    matrix[16][7] = 0;
    matrix[16][8] = -3;
    matrix[16][10] = 1;
    matrix[16][11] = -2;
    matrix[16][12] = 0;
    matrix[16][13] = 0;
    matrix[16][15] = -1;
    matrix[16][16] = 5;
    matrix[16][17] = 1;
    matrix[16][18] = 0;
    matrix[16][19] = -1;
    matrix[16][21] = -2;
    matrix[16][22] = -2;
    matrix[16][24] = -1;
    matrix[17][0] = -1;
    matrix[17][2] = -3;
    matrix[17][3] = -2;
    matrix[17][4] = 0;
    matrix[17][5] = -3;
    matrix[17][6] = -2;
    matrix[17][7] = 0;
    matrix[17][8] = -3;
    matrix[17][10] = 2;
    matrix[17][11] = -2;
    matrix[17][12] = -1;
    matrix[17][13] = 0;
    matrix[17][15] = -2;
    matrix[17][16] = 1;
    matrix[17][17] = 5;
    matrix[17][18] = -1;
    matrix[17][19] = -1;
    matrix[17][21] = -3;
    matrix[17][22] = -3;
    matrix[17][24] = -2;
    matrix[18][0] = 1;
    matrix[18][2] = -1;
    matrix[18][3] = 0;
    matrix[18][4] = 0;
    matrix[18][5] = -2;
    matrix[18][6] = 0;
    matrix[18][7] = -1;
    matrix[18][8] = -2;
    matrix[18][10] = 0;
    matrix[18][11] = -2;
    matrix[18][12] = -1;
    matrix[18][13] = 1;
    matrix[18][15] = -1;
    matrix[18][16] = 0;
    matrix[18][17] = -1;
    matrix[18][18] = 4;
    matrix[18][19] = 1;
    matrix[18][21] = -2;
    matrix[18][22] = -3;
    matrix[18][24] = -2;
    matrix[19][0] = 0;
    matrix[19][2] = -1;
    matrix[19][3] = -1;
    matrix[19][4] = -1;
    matrix[19][5] = -2;
    matrix[19][6] = -2;
    matrix[19][7] = -2;
    matrix[19][8] = -1;
    matrix[19][10] = -1;
    matrix[19][11] = -1;
    matrix[19][12] = -1;
    matrix[19][13] = 0;
    matrix[19][15] = -1;
    matrix[19][16] = -1;
    matrix[19][17] = -1;
    matrix[19][18] = 1;
    matrix[19][19] = 5;
    matrix[19][21] = 0;
    matrix[19][22] = -2;
    matrix[19][24] = -2;
    matrix[21][0] = 0;
    matrix[21][2] = -1;
    matrix[21][3] = -3;
    matrix[21][4] = -2;
    matrix[21][5] = -1;
    matrix[21][6] = -3;
    matrix[21][7] = -3;
    matrix[21][8] = 3;
    matrix[21][10] = -2;
    matrix[21][11] = 1;
    matrix[21][12] = 1;
    matrix[21][13] = -3;
    matrix[21][15] = -2;
    matrix[21][16] = -2;
    matrix[21][17] = -3;
    matrix[21][18] = -2;
    matrix[21][19] = 0;
    matrix[21][21] = 4;
    matrix[21][22] = -3;
    matrix[21][24] = -1;
    matrix[22][0] = -3;
    matrix[22][2] = -2;
    matrix[22][3] = -4;
    matrix[22][4] = -3;
    matrix[22][5] = 1;
    matrix[22][6] = -2;
    matrix[22][7] = -2;
    matrix[22][8] = -3;
    matrix[22][10] = -3;
    matrix[22][11] = -2;
    matrix[22][12] = -1;
    matrix[22][13] = -4;
    matrix[22][15] = -4;
    matrix[22][16] = -2;
    matrix[22][17] = -3;
    matrix[22][18] = -3;
    matrix[22][19] = -2;
    matrix[22][21] = -3;
    matrix[22][22] = 11;
    matrix[22][24] = 2;
    matrix[24][0] = -2;
    matrix[24][2] = -2;
    matrix[24][3] = -3;
    matrix[24][4] = -2;
    matrix[24][5] = 3;
    matrix[24][6] = -3;
    matrix[24][7] = 2;
    matrix[24][8] = -1;
    matrix[24][10] = -2;
    matrix[24][11] = -1;
    matrix[24][12] = -1;
    matrix[24][13] = -2;
    matrix[24][15] = -3;
    matrix[24][16] = -1;
    matrix[24][17] = -2;
    matrix[24][18] = -2;
    matrix[24][19] = -2;
    matrix[24][21] = -1;
    matrix[24][22] = 2;
    matrix[24][24] = 7;


    cin >> s1 >> s2;

    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = -INF;
                parent[i][j][k] = {{-1, -1}, -1};
            }
        }
    }

    dp[0][0][0] = 0;

    for (int i = 0; i <= s1.size(); i++) {
        for (int j = 0; j <= s2.size(); j++) {
            if (i == 0 && j == 0)
                continue;

            for (int k = 0; k < 3; k++) {
                if (i >= 1 && j >= 1 && dp[i][j][0] < dp[i - 1][j - 1][k] + matrix[s1[i - 1] - 'A'][s2[j - 1] - 'A']) {
                    dp[i][j][0] = dp[i - 1][j - 1][k] + matrix[s1[i - 1] - 'A'][s2[j - 1] - 'A'];
                    parent[i][j][0] = {{i - 1, j - 1}, k};
                }
            }

            if (i >= 1 && dp[i][j][1] < dp[i - 1][j][1] - CONTINUE_PENALTY) {
                dp[i][j][1] = dp[i - 1][j][1] - CONTINUE_PENALTY;
                parent[i][j][1] = {{i - 1, j}, 1};
            }

            for (int k = 0; k < 3; k++) {
                if (k == 1)
                    continue;

                if (i >= 1 && dp[i][j][1] < dp[i - 1][j][k] - OPEN_PENALTY) {
                    dp[i][j][1] = dp[i - 1][j][k] - OPEN_PENALTY;
                    parent[i][j][1] = {{i - 1, j}, k};
                }
            }

            if (j >= 1 && dp[i][j][2] < dp[i][j - 1][2] - CONTINUE_PENALTY) {
                dp[i][j][2] = dp[i][j - 1][2] - CONTINUE_PENALTY;
                parent[i][j][2] = {{i, j - 1}, 2};
            }

            for (int k = 0; k < 3; k++) {
                if (k == 2)
                    continue;

                if (j >= 1 && dp[i][j][2] < dp[i][j - 1][k] - OPEN_PENALTY) {
                    dp[i][j][2] = dp[i][j - 1][k] - OPEN_PENALTY;
                    parent[i][j][2] = {{i, j - 1}, k};
                }
            }
        }
    }

    string ans1 = "", ans2 = "";

    int i = s1.size();
    int j = s2.size();
    int k = 0;

    int maximumValue = -INF;
    for (int x = 0; x < 3; x++) {
        if (maximumValue < dp[i][j][x]) {
            maximumValue = dp[i][j][x];
            k = x;
        }
    }

    cout << dp[i][j][k] << "\n";

    while (!(i == 0 && j == 0)) {
        int newI = parent[i][j][k].first.first;
        int newJ = parent[i][j][k].first.second;
        int newK = parent[i][j][k].second;

        if (i != newI && j != newJ) {
            ans1 = s1[i - 1] + ans1;
            ans2 = s2[j - 1] + ans2;
        } else {
            if (i == newI) {
                ans1 = "-" + ans1;
                ans2 = s2[j - 1] + ans2;
            }

            if (j == newJ) {
                ans1 = s1[i - 1] + ans1;
                ans2 = "-" + ans2;
            }
        }

        i = newI;
        j = newJ;
        k = newK;
    }

    cout << ans1 << "\n" << ans2;

    return 0;
}
