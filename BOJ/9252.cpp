#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line, line2;
    cin >> line >> line2;

    for (int i = 1; i <= line.size(); i++) {
        for (int j = 1; j <= line2.size(); j++) {
            if (line[i - 1] == line2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int length = dp[line.size()][line2.size()];
    cout << length << "\n";

    if (length != 0) {
        string str = "";
        int i = line.size();
        int j = line2.size();

        while (i && j) {
            if (line[i - 1] == line2[j - 1]) {
                str += line[i - 1];
                --i;
                --j;
            }

            else if (dp[i - 1][j] > dp[i][j - 1]) {
                --i;
            }

            else {
                --j;
            }
        }

        reverse(str.begin(), str.end());
        cout << str;
    }

    return 0;
}