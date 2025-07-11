#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int start_node, const vector<vector<pair<int, int>>>& graph,
                  int num_nodes) {
    vector<int> dist(num_nodes + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    dist[start_node] = 0;
    pq.push({0, start_node});

    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int dest = pq.top().second;
        pq.pop();

        if (cur_cost > dist[dest]) continue;

        for (const auto& edge : graph[dest]) {
            if (dist[edge.first] > cur_cost + edge.second) {
                dist[edge.first] = cur_cost + edge.second;
                pq.push({dist[edge.first], edge.first});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> adj(N + 1);
    vector<vector<pair<int, int>>> rev_adj(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        rev_adj[v].push_back({u, t});
    }

    vector<int> dist_from_X = solve(X, adj, N);
    vector<int> dist_to_X = solve(X, rev_adj, N);

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (dist_to_X[i] != INT_MAX && dist_from_X[i] != INT_MAX) {
            ans = max(ans, dist_to_X[i] + dist_from_X[i]);
        }
    }

    cout << ans << "\n";

    return 0;
}