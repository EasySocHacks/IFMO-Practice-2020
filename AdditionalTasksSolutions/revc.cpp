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
        str[i] = change[str[i]];
    }

    reverse(str.begin(), str.end());

    cout << str;

    return 0;
}
