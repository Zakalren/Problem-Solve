#include <bits/stdc++.h>

using namespace std;

int N, work[100001], dp[100001], ans = 0;
bool counting;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        for (int j = a; j <= b; j++) {
            if (!work[j])
                work[j] = 1;
        }
    }

    for (int i = 1; i < 100001; i++) {
        if (work[i]) {
            dp[i] = dp[i-1] + work[i];
        }
    }

    for (int i = 1; i < 100001; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}