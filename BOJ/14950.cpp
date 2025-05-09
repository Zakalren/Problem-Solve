#include <bits/stdc++.h>

using namespace std;

int parent[10001];
pair<int, pair<int, int>> pairs[30000];

int find_parent(int node) {
    if (parent[node] == node) return node;
    return parent[node] = find_parent(parent[node]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    if (a != b) {
        parent[b] = a;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, T;
    cin >> N >> M >> T;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        cin >> pairs[i].second.first >> pairs[i].second.second >> pairs[i].first;
    }

    sort(pairs, pairs+M);

    int ans = 0;
    int count = 0;
    for (int i = 0; i < M; i++) {
        if (count == N - 1) break;

        int start = pairs[i].second.first;
        int end = pairs[i].second.second;
        int weight = pairs[i].first;

        if (find_parent(start) == find_parent(end)) continue;

        union_parent(start, end);

        int cost = weight + (count * T);
        ans += cost;
        ++count;
    }

    cout << ans;

    return 0;
}