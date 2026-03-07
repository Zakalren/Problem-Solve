#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[1001][101];
int s[1001];
int h[1001];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }

    fill(&dp[0][0], &dp[0][0] + 1001 * 101, -1);
    dp[0][100] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 100; j++) {
            if (dp[i][j] == -1) continue;

            int next_health = 0;
            if (j >= h[i + 1]) {
                next_health = min(100, j - h[i + 1] + K);
                dp[i + 1][next_health] =
                    max(dp[i + 1][next_health], dp[i][j] + s[i + 1]);
            }

            next_health = min(100, j + K);
            dp[i + 1][next_health] = max(dp[i + 1][next_health], dp[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        ans = max(ans, dp[N][i]);
    }

    cout << ans << "\n";

    return 0;
}