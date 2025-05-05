#include <bits/stdc++.h>

using namespace std;

int parent[100001];
pair<int, pair<int, int>> pairs[1000000];

int find_parent(int node) {
    if (parent[node] == node) return node;

    return parent[node] = find_parent(parent[node]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    if (a != b) parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        cin >> pairs[i].second.first >> pairs[i].second.second >>
            pairs[i].first;
    }

    sort(pairs, pairs + M);

    int ans = 0, count = 0, largest = 0;
    for (int i = 0; i < M; i++) {
        if (count == N - 1) break;

        auto pair = pairs[i];
        int start = pair.second.first;
        int end = pair.second.second;
        int weight = pair.first;

        if (find_parent(start) == find_parent(end)) continue;

        union_parent(start, end);
        ans += weight;
        largest = max(largest, weight);
        ++count;
    }

    cout << ans - largest;

    return 0;
}