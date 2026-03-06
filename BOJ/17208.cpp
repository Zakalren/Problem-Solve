#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int dp[301][301];

vector<pair<int, int>> v;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for (const auto& p : v) {
        for (int i = M; i >= p.first; i--) {
            for (int j = K; j >= p.second; j--) {
                dp[i][j] = max(dp[i][j], dp[i - p.first][j - p.second] + 1);
            }
        }
    }

    cout << dp[M][K] << "\n";

    return 0;
}