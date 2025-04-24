#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> coins;
    int N, K, ans = 0;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        coins.push_back(n);
        // cin >> coins[i];
    }

    // int ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (K == 0) break;

        if (coins[i] <= K) {
            // cout << "coins[" << i << "]: " << coins[i] << '\n';
            ans += K / coins[i];
            K %= coins[i];
        }
    }

    cout << ans;

    return 0;
}