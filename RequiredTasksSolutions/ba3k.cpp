#include <bits/stdc++.h>
using namespace std;

vector <string> vec;
vector <vector<int>> g;
map <string, int> dictionary;
map <int, string> rDictionary;
vector <int> parents;

vector <vector<int>> ans;

void dfs(int v, int id) {
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

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    string str;

    while (cin >> str) {
        vec.push_back(str);

        if (dictionary.count(str.substr(1)) == 0) {
            int sz = dictionary.size();
            rDictionary[sz] = str.substr(1);
            dictionary[str.substr(1)] = sz;
        }

        if (dictionary.count(str.substr(0, str.size() - 1)) == 0) {
            int sz = dictionary.size();
            rDictionary[sz] = str.substr(0, str.size() - 1);
            dictionary[str.substr(0, str.size() - 1)] = sz;
        }
    }

    g.resize(dictionary.size(), vector<int>(0));
    parents.resize(dictionary.size(), 0);

    for (int i = 0; i < vec.size(); i++) {
        g[dictionary[vec[i].substr(0, vec[i].size() - 1)]].push_back(dictionary[vec[i].substr(1)]);
        parents[dictionary[vec[i].substr(1)]]++;
    }

    for (int i = 0; i < dictionary.size(); i++) {
        if (parents[i] != 1 || g[i].size() > 1) {
            dfs(i, -1);
        }
    }

    for (auto element : ans) {
        string ansString = rDictionary[element[0]];
        for (int i = 1; i < element.size(); i++) {
            ansString += rDictionary[element[i]].back();
        }

        cout << ansString << "\n";
    }

    return 0;
}
