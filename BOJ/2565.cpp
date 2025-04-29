#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dp[501] = {0};
    int edges[501] = {0};

    for (int i = 1; i < 501; i++) {
        edges[i] = -1;
    }

    int N, m, M = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        edges[a] = b;
        M = max(M, a);
    }

    for (int i = 1; i <= M; i++) {
        if (edges[i] == -1) continue;
        for (int j = 0; j < i; j++) {
            if (edges[i] > edges[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << N - *max_element(dp, dp + 501);

    return 0;
}