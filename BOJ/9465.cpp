#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int nums[100000][2];
        int dp[100000][2] = {0};
        int N;
        cin >> N;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                cin >> nums[j][i];
            }
        }

        dp[0][0] = nums[0][0];
        dp[0][1] = nums[0][1];

        if (N == 1) {
            cout << max(dp[0][0], dp[0][1]) << "\n";
            continue;
        }

        if (N >= 2) {
            dp[1][0] = dp[0][1] + nums[1][0];
            dp[1][1] = dp[0][0] + nums[1][1];
        }

        for (int i = 2; i < N; i++) {
            dp[i][0] =
                max(dp[i - 1][1], max(dp[i - 2][0], dp[i - 2][1])) + nums[i][0];
            dp[i][1] =
                max(dp[i - 1][0], max(dp[i - 2][0], dp[i - 2][1])) + nums[i][1];
        }

        cout << max(dp[N - 1][0], dp[N - 1][1]) << "\n";
    }

    return 0;
}