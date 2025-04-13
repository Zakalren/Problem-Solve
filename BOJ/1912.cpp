#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dp[100000];
    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> dp[i];
    }

    for (int i = N - 2; i >= 0; i--) {
        if (dp[i] + dp[i + 1] > dp[i]) {
            dp[i] = dp[i] + dp[i + 1];
        }
    }

    int ans = *max_element(dp, dp + N);
    cout << ans;

    return 0;
}