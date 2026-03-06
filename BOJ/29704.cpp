#include <bits/stdc++.h>

using namespace std;

int N, T;
int dp[1001];

vector<pair<int, int>> v;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int S = 0;

    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        S += b;
    }

    for (auto p : v) {
        for (int i = T; i >= p.first; i--) {
            dp[i] = max(dp[i], dp[i - p.first] + p.second);
        }
    }

    cout << S - dp[T] << "\n";

    return 0;
}