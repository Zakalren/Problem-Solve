#include <bits/stdc++.h>

using namespace std;

int parent[1001];
pair<int, pair<int, int>> pairs[100000];

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

    int N, M, ans = 0;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        cin >> pairs[i].second.first >> pairs[i].second.second >>
            pairs[i].first;
    }

    sort(pairs, pairs + M);

    int count = 0;
    for (int i = 0; i < M; i++) {
        if (count == N - 1) break;

        auto pair = pairs[i];

        if (find_parent(pair.second.first) == find_parent(pair.second.second))
            continue;

        union_parent(pair.second.first, pair.second.second);
        ans += pair.first;
        ++count;
    }

    cout << ans;

    return 0;
}