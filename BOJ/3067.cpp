#include <bits/stdc++.h>

using namespace std;

int T, N, M;
int dp[10001];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> T;
    while (T--) {
        vector<int> v;

        cin >> N;
        int tmp;
        for (int i = 0; i < N; i++) {
            cin >> tmp;
            v.push_back(tmp);
        }
        cin >> M;

        fill(dp, dp + M + 1, 0);
        dp[0] = 1;

        for (int num : v) {
            for (int i = num; i <= M; i++) {
                dp[i] = dp[i] + dp[i - num];
            }
        }

        cout << dp[M] << "\n";
    }

    return 0;
}