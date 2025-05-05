#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> v;
int visited[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, ans = 0;
    cin >> V >> E;

    v.resize(V + 1);

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    for (int i = 0; i < v[1].size(); i++) {
        pq.push(v[1][i]);
    }
    visited[1] = 1;

    int count = 0;
    while (count < V - 1) {
        auto p = pq.top();
        pq.pop();

        if (visited[p.second]) continue;

        visited[p.second] = 1;
        ++count;
        ans += p.first;

        for (int i = 0; i < v[p.second].size(); i++) {
            if (visited[v[p.second][i].second]) continue;

            pq.push(v[p.second][i]);
        }
    }

    cout << ans;

    return 0;
}