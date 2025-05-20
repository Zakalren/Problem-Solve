#include <bits/stdc++.h>

using namespace std;

int parent[1001];
bool is_powered[1001];

pair<int, pair<int, int>> edges[100000];

int find_parent(int node) {
    if (parent[node] == node) return node;

    return parent[node] = find_parent(parent[node]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int power_station;
    for (int i = 0; i < K; i++) {
        cin >> power_station;
        is_powered[power_station] = true;
    }

    for (int i = 0; i < M; i++) {
        cin >> edges[i].second.first >> edges[i].second.second >>
            edges[i].first;
    }

    sort(edges, edges + M);

    int ans = 0;
    for (int i = 0; i < M; i++) {
        auto edge = edges[i];
        int u = edge.second.first;
        int v = edge.second.second;
        int w = edge.first;

        int u_parent = find_parent(u);
        int v_parent = find_parent(v);

        if (u_parent == v_parent) continue;

        if (is_powered[u_parent] && is_powered[v_parent]) continue;

        union_parent(u, v);
        is_powered[find_parent(v)] =
            is_powered[u_parent] || is_powered[v_parent];
        ans += w;
    }

    cout << ans;

    return 0;
}