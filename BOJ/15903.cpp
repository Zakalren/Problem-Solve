#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll cards[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    ll res = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    for (int j = 0; j < m; j++) {
        int min_idx = 0, min2_idx = -1;

        for (int i = 0; i < n; i++) {
            if (cards[min_idx] > cards[i]) {
                min_idx = i;
                // cout << "min_idx: " << i << '\n';
            }
        }
        for (int i = 0; i < n; i++) {
            if (i == min_idx) continue;

            if ((cards[min2_idx] > cards[i] || min2_idx == -1) &&
                i != min_idx) {
                min2_idx = i;
                // cout << "min2_idx: " << i << '\n';
            }
        }

        ll sum = cards[min_idx] + cards[min2_idx];
        cards[min_idx] = sum;
        cards[min2_idx] = sum;
    }

    for (int i = 0; i < n; i++) {
        res += cards[i];
    }
    cout << res;

    return 0;
}