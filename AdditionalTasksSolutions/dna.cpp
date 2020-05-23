#include <bits/stdc++.h>
using namespace std;

string dna;

int cnt[26];

int main() {
    cin >> dna;
    for (int i = 0; i < dna.size(); i++) {
        cnt[dna[i] - 'A']++;
    }

    cout << cnt['A' - 'A'] << " " << cnt['C' - 'A'] << " " <<  cnt['G' - 'A'] << " " << cnt['T' - 'A'];

    return 0;
}
