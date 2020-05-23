#include <bits/stdc++.h>
using namespace std;

const int LEN = 1e5;

int n;
vector <vector<int>> g(LEN);
vector <int> parents(LEN);
vector <bool> used;

vector <vector<int>> ans;

void dfs(int v, int id) {
    used[v] = true;

    if (id == -1) {
        if (g[v].size() == 0)
            return;

        for (int u : g[v]) {
            int id = ans.size();
            ans.push_back(vector<int>(1, v));

            dfs(u, id);
        }
    } else {
        ans[id].push_back(v);

        if (parents[v] == 1 && g[v].size() == 1) {
            dfs(g[v][0], id);
        }
    }
}

void cycleDfs(int v, int start, int id) {
    used[v] = true;

    if (id == -1) {
        id = ans.size();
        ans.push_back(vector<int>(1, v));

        cycleDfs(g[v][0], start, id);
    } else {
        ans[id].push_back(v);

        if (v != start) {
            cycleDfs(g[v][0], start, id);
        }
    }
}

vector <int> getNodes(string str) {
    vector <int> ans(0);

    str += ",";
    string cur = "";

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ',') {
            ans.push_back(atoi(cur.c_str()));
            cur = "";
        } else {
            cur += str[i];
        }
    }

    return ans;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int v;
    string str;

    while (cin >> v) {
        n = max(n, v);

        cin >> str;
        cin >> str;

        vector <int> us = getNodes(str);

        for (int u : us) {
            n = max(n, u);

            g[v].push_back(u);
            parents[u]++;
        }
    }

    used.resize(n, false);

    for (int i = 0; i < n; i++) {
        if (parents[i] != 1 || g[i].size() != 1) {
            dfs(i, -1);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            cycleDfs(i, i, -1);
        }
    }

    for (auto element : ans) {
        stringstream sstream;
        sstream << element[0];

        string tmp;
        sstream >> tmp;

        string ansString = "" + tmp;
        for (int i = 1; i < element.size(); i++) {
            sstream.clear();
            sstream << element[i];

            sstream >> tmp;

            ansString += " -> " + tmp;
        }

        cout << ansString << "\n";
    }

    return 0;
}
