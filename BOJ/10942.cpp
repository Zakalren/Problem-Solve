#include <bits/stdc++.h>

using namespace std;

int nums[2001];
int dp[2001][2001];
pair<int, int> questions[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> questions[i].first >> questions[i].second;
    }

    for (int i = 1; i <= N; i++) {
        dp[i][i] = 1;
    }

    for (int i = 1; i < N; i++) {
        if (nums[i] == nums[i + 1]) dp[i][i + 1] = 1;
    }

    for (int len = 3; len <= N; len++) {
        for (int i = 1; i <= N - len + 1; i++) {
            int j = i + len - 1;

            if (nums[i] == nums[j] && dp[i + 1][j - 1]) dp[i][j] = 1;
        }
    }

    for (int i = 0; i < M; i++) {
        int start = questions[i].first;
        int end = questions[i].second;

        if (dp[start][end])
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}