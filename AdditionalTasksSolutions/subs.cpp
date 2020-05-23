#include <bits/stdc++.h>
using namespace std;

string s, t;

int main() {
    freopen("out.txt", "w", stdout);

    cin >> s >> t;

    for (int i = 0; i < s.size(); i++) {
        if (i + t.size() - 1 >= s.size())
            break;

        bool ok = true;

        for (int j = 0; j < t.size(); j++) {
            if (t[j] != s[i + j]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            cout << (i + 1) << " ";
        }
    }

    return 0;
}
