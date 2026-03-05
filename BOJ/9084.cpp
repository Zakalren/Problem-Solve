#include <bits/stdc++.h>

using namespace std;

int T;
int dp[10001], coins[20];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> T;
    while (T--) {
        int N, M;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> coins[i];
        }
        cin >> M;

        fill(dp, dp + M + 1, 0);

        dp[0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = coins[i]; j <= M; j++) {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }

        cout << dp[M] << "\n";
    }

    return 0;
}