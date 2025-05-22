#include <bits/stdc++.h>

using namespace std;

int N, M;
int prices[1000];

int get_count(int price) {
    return min((long)N, M - (lower_bound(prices, prices + M, price) - prices));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> prices[i];
    }

    sort(prices, prices + M);

    for (int i = 0; i < M; i++) {
        int price = prices[i];
        int count = get_count(price);

        if (price * count > ans * get_count(ans)) {
            ans = price;
        }
    }

    cout << ans << " " << ans * get_count(ans);

    return 0;
}