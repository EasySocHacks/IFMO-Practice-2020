#include <bits/stdc++.h>
using namespace std;

vector <int> vec;

void parseString(string str) {
    string cur;
    str += " ";

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            vec.push_back(atoi(cur.c_str()));
            cur = "";
        } else {
            cur += str[i];
        }
    }
}

void printArray() {
    cout << "(";

    for (int i = 0; i < vec.size(); i++) {

        if (vec[i] > 0)
            cout << "+" << vec[i];
        else
            cout << vec[i];

        if (i != vec.size() - 1)
            cout << " ";
    }

    cout << ")\n";
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    string str;
    getline(cin, str);

    parseString(str.substr(1, str.size() - 2));

    for (int k = 1; k <= vec.size(); k++) {
        for (int i = k - 1; i < vec.size(); i++) {
            if (abs(vec[i]) == k) {
                if (i != k - 1) {
                    for (int j = k - 1; j <= i; j++) {
                        if (i - (j - k + 1) < j)
                            break;

                        vec[j] *= -1;

                        if (j != i - (j - k + 1))
                            vec[i - (j - k + 1)] *= -1;

                        swap(vec[j], vec[i - (j - k + 1)]);
                    }

                    printArray();
                }

                if (vec[k - 1] < 0) {
                    vec[k - 1] = abs(vec[k - 1]);

                    printArray();
                }
            }
        }
    }

    return 0;
}
