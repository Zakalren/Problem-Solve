#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int N;
ll dp[1276];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;

    int S = N * (N + 1) / 2;
    if (S % 2 != 0) {
        cout << "0\n";
        return 0;
    }

    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = S / 2; j >= i; j--) {
            dp[j] = dp[j] + dp[j - i];
        }
    }

    cout << dp[S / 2] / 2 << "\n";

    return 0;
}