#include <bits/stdc++.h>

using namespace std;

int N, M, K, ans = INT_MAX;

int prefix_sum[2001][2001];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char ch;
            cin >> ch;

            int num = 0;
            if ((i + j) % 2 == 0) {
                if (ch != 'B') num = 1;
            }
            else {
                if (ch != 'W') num = 1;
            }

            prefix_sum[i][j] = num + prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
        }
    }

    for (int i = K; i <= N; i++) {
        for (int j = K; j<= M; j++) {
            int cnt = prefix_sum[i][j] - prefix_sum[i-K][j] - prefix_sum[i][j-K] + prefix_sum[i-K][j-K];
            int min_cnt = min(cnt, K * K - cnt);

            ans = min(ans, min_cnt);
        }
    }

    cout << ans << "\n";

    return 0;
}
