#include <bits/stdc++.h>
using namespace std;

string str;
map <char, char> change;

int main() {
    freopen("out.txt", "w", stdout);

    change['A'] = 'T';
    change['T'] = 'A';
    change['C'] = 'G';
    change['G'] = 'C';

    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        for (int len = 4; len <= 12; len++) {
            if (i + len - 1 >= str.size()) {
                break;
            }

            bool ok = true;

            for (int j = 0; j < len; j++) {
                if (str[i + j] != change[str[i + len - 1 - j]]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                cout << (i + 1) << " " << len << "\n";
            }
        }
    }

    return 0;
}
