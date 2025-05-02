#include <bits/stdc++.h>

using namespace std;

// 19:09

vector<vector<pair<int, int>>> edges;
vector<int> scores;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    edges.resize(V + 1);
    scores.resize(V + 1, INT_MAX);
    scores[K] = 0;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edges[a].push_back(make_pair(b, c));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push(make_pair(0, K));

    while (!pq.empty()) {
        int cost = pq.top().first;
        int dest = pq.top().second;
        pq.pop();

        // if (cost > scores[dest]) continue;

        for (auto edge : edges[dest]) {
            int next_dest = edge.first;
            int next_cost = cost + edge.second;

            if (scores[next_dest] > next_cost) {
                scores[next_dest] = next_cost;
                pq.push(make_pair(next_cost, next_dest));
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (scores[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << scores[i] << "\n";
    }

    return 0;
}