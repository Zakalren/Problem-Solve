#include <algorithm>
#include <iostream>

using namespace std;

int N, T[16], P[16], dp[16];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = 0; i < N; i++) {
        dp[i + 1] = max(dp[i + 1], dp[i]);
        dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
    }

    cout << dp[N];

    return 0;
}