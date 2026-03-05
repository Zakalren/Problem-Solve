#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000;

int dp[5001];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string S;
    cin >> S;

    if (S[0] == '0') {
        cout << "0\n";
        return 0;
    }

    int N = S.length();

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (S[i - 1] >= '1' && S[i - 1] <= '9') {
            dp[i] = dp[i - 1] % MOD;
        }

        int num = (S[i - 2] - '0') * 10 + (S[i - 1] - '0');
        if (num >= 10 && num <= 26) {
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
    }

    cout << dp[N] << "\n";

    return 0;
}