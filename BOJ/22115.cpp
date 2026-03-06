#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[100001];

vector<int> v;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> K;
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    fill(dp, dp + K + 1, INT_MAX);
    dp[0] = 0;

    for (int num : v) {
        for (int i = K; i >= num; i--) {
            if (dp[i - num] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - num] + 1);
            }
        }
    }

    if (dp[K] == INT_MAX)
        cout << "-1\n";
    else
        cout << dp[K] << "\n";

    return 0;
}