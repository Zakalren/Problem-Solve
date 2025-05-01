#include <bits/stdc++.h>

using namespace std;

int dp[100001];
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    v.resize(N + 1);

    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = 0; i < N; i++) {
        int weight = v[i].first;
        int value = v[i].second;
        for (int j = K; j >= weight; j--) {
            dp[j] = max(dp[j], dp[j - weight] + v[i].second);
        }
    }

    cout << *max_element(dp, dp + K + 1);

    return 0;
}