#pragma once
#include <bits/stdc++.h>

using namespace std;

vector <pair<string, string>> readFASTA() {
    string str;

    vector <pair<string, string>> ans;

    while (cin >> str) {
        if (str[0] == '>') {
            ans.push_back({str.substr(1), ""});
        } else {
            ans.back().second += str;
        }
    }

    return ans;
}
