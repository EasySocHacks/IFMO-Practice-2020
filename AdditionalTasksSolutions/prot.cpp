#include <bits/stdc++.h>
using namespace std;

string str;
string ans = "";
map <string, string> change;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    //
    change["UUU"] = "F";
    change["CUU"] = "L";
    change["AUU"] = "I";
    change["GUU"] = "V";
    change["UUC"] = "F";
    change["CUC"] = "L";
    change["AUC"] = "I";
    change["GUC"] = "V";
    change["UUA"] = "L";
    change["CUA"] = "L";
    change["AUA"] = "I";
    change["GUA"] = "V";
    change["UUG"] = "L";
    change["CUG"] = "L";
    change["AUG"] = "M";
    change["GUG"] = "V";
    change["UCU"] = "S";
    change["CCU"] = "P";
    change["ACU"] = "T";
    change["GCU"] = "A";
    change["UCC"] = "S";
    change["CCC"] = "P";
    change["ACC"] = "T";
    change["GCC"] = "A";
    change["UCA"] = "S";
    change["CCA"] = "P";
    change["ACA"] = "T";
    change["GCA"] = "A";
    change["UCG"] = "S";
    change["CCG"] = "P";
    change["ACG"] = "T";
    change["GCG"] = "A";
    change["UAU"] = "Y";
    change["CAU"] = "H";
    change["AAU"] = "N";
    change["GAU"] = "D";
    change["UAC"] = "Y";
    change["CAC"] = "H";
    change["AAC"] = "N";
    change["GAC"] = "D";
    change["CAA"] = "Q";
    change["AAA"] = "K";
    change["GAA"] = "E";
    change["CAG"] = "Q";
    change["AAG"] = "K";
    change["GAG"] = "E";
    change["UGU"] = "C";
    change["CGU"] = "R";
    change["AGU"] = "S";
    change["GGU"] = "G";
    change["UGC"] = "C";
    change["CGC"] = "R";
    change["AGC"] = "S";
    change["GGC"] = "G";
    change["CGA"] = "R";
    change["AGA"] = "R";
    change["GGA"] = "G";
    change["UGG"] = "W";
    change["CGG"] = "R";
    change["AGG"] = "R";
    change["GGG"] = "G";

    change["UAA"] = "";
    change["UAG"] = "";
    change["UGA"] = "";
    //

    cin >> str;

    for (int i = 0; i < str.size(); i += 3) {
        string codon = "";
        codon += str[i];
        codon += str[i + 1];
        codon += str[i + 2];

        ans += change[codon];
    }

    cout << ans;

    return 0;
}
