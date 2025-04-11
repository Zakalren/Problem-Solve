#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M,
        balls[101] = {
            0,
        };
    cin >> N >> M;

    for (int n = 0; n < M; n++) {
        int i, j, k;
        cin >> i >> j >> k;

        for (int a = i; a <= j; a++) {
            balls[a] = k;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << balls[i];
        if (i != N) {
            cout << ' ';
        }
    }

    return 0;
}