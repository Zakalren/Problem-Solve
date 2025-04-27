#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int graph[1025][1025] = {0};

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int n;
            cin >> n;

            graph[i][j] = graph[i][j - 1] + n;
        }
    }

    while (M--) {
        int ans = 0;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2) swap(x1, x2);

        if (y1 > y2) swap(y1, y2);

        for (int i = x1; i <= x2; i++) {
            ans += graph[i][y2] - graph[i][y1 - 1];
        }

        cout << ans << "\n";

        // 1 2
        // 3 4

        // 1 3
        // 3 7

        // 1,2 ~ 1,2
        // [1][2] - [1][1] => 3 - 1
    }

    return 0;
}