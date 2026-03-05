#include <bits/stdc++.h>

using namespace std;

int N;
int score[1001];
int dp[1001];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> score[i];
    }

    for (int i = 1; i <= N; i++) {
        int min_score = 10001;
        int max_score = 0;

        for (int j = i; j >= 1; j--) {
            min_score = min(min_score, score[j]);
            max_score = max(max_score, score[j]);

            dp[i] = max(dp[i], (max_score - min_score) + dp[j - 1]);
        }
    }

    cout << dp[N] << "\n";

    return 0;
}