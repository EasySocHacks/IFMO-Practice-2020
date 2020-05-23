#include <bits/stdc++.h>
using namespace std;

vector <int> vec;

void parseString(string str) {
    string cur;
    str += " ";

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            vec.push_back(atoi(cur.c_str()));
            cur = "";
        } else {
            cur += str[i];
        }
    }
}

int ans = 0;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    vec.push_back(0);

    string str;
    getline(cin, str);

    parseString(str.substr(1, str.size() - 2));

    vec.push_back(vec.size());

    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] - vec[i - 1] != 1)
            ans++;
    }

    cout << ans;

    return 0;
}
