#include <bits/stdc++.h>
using namespace std;

map <int, vector<int>> g;
int maxNumber = 0;

map <int, bool> used;

void dfs(int v) {
    used[v] = true;

    for (int u : g[v]) {
        if (used[u])
            continue;

        dfs(u);
    }
}

void buidGraph(string str) {
    string cur = "";
    int first = 0;
    int last = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(')
                continue;

        if (str[i] == ' ' || str[i] == ')') {
            int number = atoi(cur.c_str());

            maxNumber = max(maxNumber, abs(number));

            if (last == 0) {
                last = number;
                first = number;
            } else {
                g[last].push_back(-number);
                g[-number].push_back(last);
                last = number;

                if (str[i] == ')') {
                    g[number].push_back(-first);
                    g[-first].push_back(number);
                    last = 0;
                    first = 0;
                }
            }

            cur = "";
        } else {
            cur += str[i];
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);

    string str;

    getline(cin, str);
    buidGraph(str);

    getline(cin, str);
    buidGraph(str);

    int cycles = 0;

    for (auto x : g) {
        if (used[x.first])
            continue;

        cycles++;
        dfs(x.first);
    }

    cout << maxNumber - cycles;

    return 0;
}
