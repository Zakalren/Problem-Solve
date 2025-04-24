#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<string> strset;

    string line;
    cin >> line;

    for (int i = 0; i < line.length(); i++) {
        string s = "";
        for (int j = i; j < line.length(); j++) {
            s += line[j];
            strset.insert(s);
        }
    }

    /*
    for (string s : strset) {
        cout << s << '\n';
    }

    cout << "res\n";*/

    cout << strset.size();

    return 0;
}