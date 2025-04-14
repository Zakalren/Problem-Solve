#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num[1000], dp[1000];
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
        dp[i] = 1;
    }

    int len = 1;

    for (int i = N - 2; i >= 0; i--) {
        for (int j = i + 1; j < N; j++) {
            if (num[j] > num[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp, dp + N);
    // cout << len;
    return 0;
}