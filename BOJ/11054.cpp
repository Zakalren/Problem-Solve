#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num[1000], dp[1000], dp2[1000];
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
        dp[i] = 1;
        dp2[i] = 1;
    }

    for (int i = N - 2; i >= 0; i--) {
        for (int j = i + 1; j < N; j++) {
            if (num[i] > num[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (num[i] > num[j]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        dp[i] += dp2[i];
        // cout << "num[" << i << ']' << ": " << num[i] << ", ";
        // cout << "dp[" << i << ']' << ": " << dp[i] << ", ";
        // cout << "dp2[" << i << ']' << ": " << dp2[i] << '\n';
    }

    /*for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (num[j] > num[i]) {
                dp2[i] =
            }
        }
    }*/

    cout << *max_element(dp, dp + N) - 1;
    return 0;
}