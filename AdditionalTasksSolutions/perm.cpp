#include <bits/stdc++.h>
using namespace std;

int n;
int fac = 1;

vector <int> perm(0);

void nextPermutation() {
    int i = n - 2;
    for (; i >= 0; i--) {
        if (perm[i] < perm[i + 1])
            break;
    }

    if (i == -1)  {
        return;
    }

    int j = n - 1;
    for (; j >= i; j--) {
        if (perm[j] > perm[i])
            break;
    }

    swap(perm[i], perm[j]);
    reverse(perm.begin() + i + 1, perm.end());
}

int main() {
    freopen("out.txt", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        fac *= i;
        perm.push_back(i);
    }

    cout << fac << "\n";

    for (int i = 0; i < fac; i++) {
        for (int j = 0; j < n; j++) {
            cout << perm[j] << " ";
        }

        cout << "\n";

        nextPermutation();
    }

    return 0;
}
