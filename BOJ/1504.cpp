#include <bits/stdc++.h>

using namespace std;

int graph[801][801];
int dist[801];

int N, E;

void solve(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    fill(dist + 1, dist + N + 1, INT_MAX);
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cur_dist) continue;

        for (int i = 1; i <= N; i++) {
            if (graph[cur][i] == INT_MAX) continue;

            int next_dist = cur_dist + graph[cur][i];
            if (dist[i] > next_dist) {
                dist[i] = next_dist;
                pq.push({next_dist, i});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> E;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == j) continue;

            graph[i][j] = INT_MAX;
        }
    }

    int u, v, c;
    for (int i = 1; i <= E; i++) {
        cin >> u >> v >> c;
        graph[u][v] = c;
        graph[v][u] = c;
    }

    int v1, v2;
    cin >> v1 >> v2;

    solve(1);
    long long int from_1_to_v1 = dist[v1];
    long long int from_1_to_v2 = dist[v2];

    solve(v1);
    int from_v1_to_v2 = dist[v2];
    int from_v1_to_n = dist[N];

    solve(v2);
    int from_v2_to_v1 = dist[v1];
    int from_v2_to_n = dist[N];

    long long ans = min(from_1_to_v1 + from_v1_to_v2 + from_v2_to_n,
                        from_1_to_v2 + from_v2_to_v1 + from_v1_to_n);

    if (ans >= INT_MAX)
        cout << "-1\n";
    else
        cout << ans << "\n";

    return 0;
}