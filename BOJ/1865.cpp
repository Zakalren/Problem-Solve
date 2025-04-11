#include <bits/stdc++.h>

using namespace std;

typedef struct Edge {
    int s, e, t;
} Edge;

const int M_VALUE = 1000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        vector<Edge> edges;

        int times[501];
        int N, M, W;

        for (int i = 0; i <= N; i++) {
            times[i] = M_VALUE;
        }

        cin >> N >> M >> W;

        for (int i = 0; i < M; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }

        for (int i = 0; i < W; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }

        times[1] = 0;
        bool isNegative = false;

        for (int i = 0; i < N; i++) {
            for (Edge edge : edges) {
                if (times[edge.s] + edge.t < times[edge.e]) {
                    times[edge.e] = times[edge.s] + edge.t;

                    if (i == N - 1) {
                        isNegative = true;
                    }
                }
            }
        }

        if (isNegative) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}