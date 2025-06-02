#include <bits/stdc++.h>

using namespace std;

int dist[50001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        dist[i] = INT_MAX;
    }

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    priority_queue<pair<int, int>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        if (cur_dist > dist[cur]) continue;

        if (cur_dist == dist[cur] == INT_MAX) continue;

        for (auto& pair : graph[cur]) {
            int next = pair.first;
            int next_dist = cur_dist + pair.second;

            if (next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.push({-next_dist, next});
            }
        }
    }

    cout << dist[N];

    return 0;
}