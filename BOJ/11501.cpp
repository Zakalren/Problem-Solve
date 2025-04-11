#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        long long answer = 0;
        int N, prices[1000000];
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> prices[i];
        }

        int M_price = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (prices[i] > M_price) {
                M_price = prices[i];
                continue;
            }

            if (M_price - prices[i] > 0) {
                answer += M_price - prices[i];
            }
        }

        cout << answer << '\n';
    }

    return 0;
}