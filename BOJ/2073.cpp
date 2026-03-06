#include <bits/stdc++.h>

using namespace std;

int D, P;
int dp[100001];

vector<pair<int, int>> v;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> D >> P;
    for (int i = 0; i < P; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    fill(dp, dp + D + 1, -1e9);
    dp[0] = 1e9;

    for (const auto& p : v) {
        for (int i = D; i >= p.first; i--) {
            if (dp[i - p.first] != -1e9) {
                dp[i] = max(dp[i], min(dp[i - p.first], p.second));
            }
        }
    }

    cout << dp[D] << "\n";

    return 0;
}