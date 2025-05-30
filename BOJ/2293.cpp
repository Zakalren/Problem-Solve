#include <bits/stdc++.h>

using namespace std;

int dp[10001];
int nums[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    // N: 3, K: 10
    // nums 0 : 1
    // nums 1 : 2
    // nums 2 : 5

    // dp[1] += (dp[1 - 1] = dp[0])
    // dp[2] += (dp[2 - 1] = dp[1])

    dp[0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = nums[i]; j <= K; j++) {
            dp[j] += dp[j - nums[i]];
        }
    }

    cout << dp[K];

    return 0;
}