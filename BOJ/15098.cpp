#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_set<string> split;

    string line;
    getline(cin, line);

    istringstream iss(line);

    string buffer;
    while (iss >> buffer) {
        if (split.count(buffer)) {
            cout << "no";
            return 0;
        }

        split.insert(buffer);
    }

    cout << "yes";

    return 0;
}