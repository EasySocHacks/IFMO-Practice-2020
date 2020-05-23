#include <bits/stdc++.h>
using namespace std;

vector <string> vec, pref, suff;
int n;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    string str;

    while (cin >> str) {
        vec.push_back(str);
        pref.push_back(str.substr(0, str.size() - 1));
        suff.push_back(str.substr(1));
    }

    n = vec.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (suff[i] == pref[j]) {
                cout << vec[i] << " -> " << vec[j] << "\n";
            }
        }
    }

    return 0;
}
