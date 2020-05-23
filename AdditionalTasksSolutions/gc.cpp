#include <bits/stdc++.h>
#include "FASTA.h"
using namespace std;

int CGCount(string str) {
    int ans = 0;

    for (char c : str) {
        if (c == 'C' || c == 'G') {
            ans++;
        }
    }

    return ans;
}

bool cmp(pair<string, double> firstPair, pair<string, double> secondPair) {
    return firstPair.second >= secondPair.second;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    vector <pair<string, string>> input = readFASTA();

    vector <pair<string, double>> percentage;

    for (auto namedString : input) {
        percentage.push_back({namedString.first, (double)CGCount(namedString.second) / (double)namedString.second.size()});
    }

    sort(percentage.begin(), percentage.end(), cmp);

    cout.precision(20);
    cout << percentage.front().first << "\n" << (double)100.0 * percentage.front().second;

    return 0;
}
