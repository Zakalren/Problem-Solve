#include <bits/stdc++.h>

using namespace std;

int dp[11];

// 1 = 1 => 1
// 2 = 1+1, 2 => 2
// 3 = 1+1+1, 2+1, 1+2, 3 => 4
// 4 = 1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2, 1+3, 3+1 => 7

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        cout << dp[n] << "\n";
    }

    return 0;
}