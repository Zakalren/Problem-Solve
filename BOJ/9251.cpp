#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

string line, line2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> line >> line2;

    for (int i = 1; i <= line.size(); i++) {
        for (int j = 1; j <= line2.size(); j++) {
            if (line[i - 1] == line2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[line.size()][line2.size()];

    return 0;
}