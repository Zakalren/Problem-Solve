#include <bits/stdc++.h>

using namespace std;

int dp[11][11];

int combination(int n, int k) {
    if (dp[n][k] > 0) return dp[n][k];
    if (k == 0 || n == k) return dp[n][k] = 1;
    return dp[n][k] = combination(n - 1, k - 1) + combination(n - 1, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dp[11][11];

    int N, K;
    cin >> N >> K;

    cout << combination(N, K);

    return 0;
}