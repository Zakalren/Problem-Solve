#include <bits/stdc++.h>

using namespace std;

int C, N;
int dp[1101];

vector<pair<int, int>> v;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> C >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }

    fill(dp, dp + C + 101, 1e9);
    dp[0] = 0;

    for (const auto& p : v) {
        for (int i = p.first; i <= C + 100; i++) {
            dp[i] = min(dp[i], dp[i - p.first] + p.second);
        }
    }

    int ans = 1e9;
    for (int i = C; i <= C + 100; i++) {
        ans = min(ans, dp[i]);
    }

    cout << ans << "\n";

    return 0;
}