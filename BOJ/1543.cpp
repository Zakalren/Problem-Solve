#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    string line, line2;
    getline(cin, line);
    getline(cin, line2);

    for (int i = 0; i < line.size(); i++) {
        for (int j = 0; j < line2.size(); j++) {
            if (line[i + j] != line2[j]) {
                break;
            }

            if (j == line2.size() - 1) {
                ans++;
                i += j;
            }
        }
    }

    cout << ans;

    return 0;
}