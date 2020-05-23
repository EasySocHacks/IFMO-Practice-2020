#include <bits/stdc++.h>
using namespace std;

string s, t;
int ans = 0;

int main() {
    cin >> s >> t;

    for (int i = 0; i < s.size(); i++) {
        ans += (s[i] != t[i]);
    }

    cout << ans;

    return 0;
}
