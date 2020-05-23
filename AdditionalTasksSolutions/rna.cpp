#include <bits/stdc++.h>
using namespace std;

string dna;

int main() {
    freopen("out.txt", "w", stdout);

    cin >> dna;

    for (int i = 0; i < dna.size(); i++) {
        if (dna[i] == 'T')
            dna[i] = 'U';
    }

    cout << dna;

    return 0;
}
