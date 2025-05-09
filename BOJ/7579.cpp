#include <bits/stdc++.h>

using namespace std;

int N, M;

int dp[10001];

int mems[100];
int costs[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> mems[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> costs[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 10000; j >= costs[i]; j--) {
            dp[j] = max(dp[j], dp[j - costs[i]] + mems[i]);
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i <= 10000; i++) {
        if (dp[i] >= M) {
            ans = min(ans, i);
        }
    }

    cout << ans;

    // dp[0] = 0;

    // 4 50
    // 5 15 20 30 50
    // 0 1  1  2  3
    //

    return 0;
}