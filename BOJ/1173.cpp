#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, m, M, T, R;
    cin >> N >> m >> M >> T >> R;

    if (M - m < T) {
        cout << -1;
        return 0;
    }

    int beat = m;
    int ans = 0;

    while (N) {
        if (beat + T <= M) {
            beat += T;
            --N;
        }

        else {
            beat = max(m, beat - R);
        }

        ++ans;
    }

    cout << ans;

    return 0;
}