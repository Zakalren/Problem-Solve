#include <bits/stdc++.h>

using namespace std;

bool vip[41];

int dp[41];
int ans = 1;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    int tmp;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        vip[tmp] = true;
    }

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= 40; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int streak = 0;
    for (int i = 1; i <= N; i++) {
        if (vip[i]) {
            ans *= dp[streak];
            streak = 0;
        } else {
            streak++;
        }
    }
    ans *= dp[streak];

    cout << ans << "\n";

    return 0;
}