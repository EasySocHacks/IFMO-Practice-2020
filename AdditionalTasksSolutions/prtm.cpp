#include <bits/stdc++.h>
using namespace std;

map <char, double> weight;
string str;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    weight['A'] = 71.03711;
    weight['C'] = 103.00919;
    weight['D'] = 115.02694;
    weight['E'] = 129.04259;
    weight['F'] = 147.06841;
    weight['G'] = 57.02146;
    weight['H'] = 137.05891;
    weight['I'] = 113.08406;
    weight['K'] = 128.09496;
    weight['L'] = 113.08406;
    weight['M'] = 131.04049;
    weight['N'] = 114.04293;
    weight['P'] = 97.05276;
    weight['Q'] = 128.05858;
    weight['R'] = 156.10111;
    weight['S'] = 87.03203;
    weight['T'] = 101.04768;
    weight['V'] = 99.06841;
    weight['W'] = 186.07931;
    weight['Y'] = 163.06333;



    cin >> str;
    double ans = 0.0;

    for (char c : str) {
        ans += weight[c];
    }

    cout.precision(20);
    cout << ans;

    return 0;
}
