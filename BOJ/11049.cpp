#include <bits/stdc++.h>

using namespace std;

int N;
int dp[501][501];  // i부터 j까지 곱했을때의 곱셈 횟수
pair<int, int> pairs[501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < N; i++) {
        dp[i][i] = 0;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j + i - 1 < N; j++) {
            int k = j + i - 1;

            for (int l = j; l < k; l++) {
                int count =
                    dp[j][l] + dp[l + 1][k] +
                    (pairs[j].first * pairs[l].second * pairs[k].second);

                dp[j][k] = min(dp[j][k], count);
            }
        }
    }

    cout << dp[0][N - 1];

    return 0;
}