#include <bits/stdc++.h>

#define MOD 10007

using namespace std;

int dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 1 => 1
    // 2 => 1 + 2 = 3
    // 3 => 3 + 2 = 5
    // 4 => 5 + 3 + 3
    //

    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 2]) % MOD;
    }

    cout << dp[N];

    return 0;
}