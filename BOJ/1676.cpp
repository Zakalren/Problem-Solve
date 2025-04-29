#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, ans = 0;
    cin >> N;

    // 2 * 5 = 10, 10 * ???
    while (N >= 5) {
        N /= 5;
        ans += N;
    }

    cout << ans;

    return 0;
}