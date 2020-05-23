#include <bits/stdc++.h>
using namespace std;

int k;
string str;
map <string, vector<string>> graph;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin >> k >> str;

    for (int i = 0; i < str.size(); i++) {
        if (i + k - 1 >= str.size()) {
            break;
        }

        graph[str.substr(i, k - 1)].push_back(str.substr(i + 1, k - 1));
    }

    for (auto edges : graph) {
        cout << edges.first << " -> ";

        for (int i = 0; i < edges.second.size(); i++) {
            if (i > 0) {
                cout << ",";
            }

            cout << edges.second[i];
        }

        cout << "\n";
    }

    return 0;
}
