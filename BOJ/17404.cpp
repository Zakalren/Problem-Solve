#include <bits/stdc++.h>

using namespace std;

int N;
int nums[1000][3];
int dp[1001][3][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> nums[i][j];
        }
    }

    // dp[인덱스][첫 선택][현재선택] 해서 첫번째에 선택한 색깔에 따라 그 다음
    // 색깔이랑(필수는 아닐듯) 그전색깔(마지막인덱스) 색깔 최소값으로 맞추고 dp
    // 돌리면 될듯?
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = INT_MAX / 2;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        dp[0][i][i] = nums[0][i];

        for (int j = 0; j < 3; j++) {
            if (i == j) continue;

            dp[1][i][j] = min(dp[1][i][j], dp[0][i][i] + nums[1][j]);
        }
        // dp[N][i] = nums[0][i];
    }

    for (int j = 0; j < 3; j++) {
        for (int i = 2; i < N; i++) {
            dp[i][j][0] = min(dp[i - 1][j][1], dp[i - 1][j][2]) + nums[i][0];
            dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + nums[i][1];
            dp[i][j][2] = min(dp[i - 1][j][0], dp[i - 1][j][1]) + nums[i][2];
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;

            ans = min(ans, dp[N - 1][i][j]);
        }
    }

    cout << ans;

    return 0;
}