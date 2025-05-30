#include <bits/stdc++.h>

using namespace std;

int dp[31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    dp[0] = 1;
    dp[2] = 3;

    if (N % 2 == 1) {
        cout << 0;
        return 0;
    }

    for (int i = 4; i <= N; i += 2) {
        dp[i] = dp[i-2] * 3;

        for (int j = 4; j <= i; j += 2) {
            dp[i] += 2 * dp[i - j];
        }
    }

    cout << dp[N];

    return 0;
}