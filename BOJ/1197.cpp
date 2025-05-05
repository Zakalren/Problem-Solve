#include <bits/stdc++.h>

using namespace std;

int parent[10001];
pair<int, pair<int, int>> pairs[100001];  // 가중치, start, dest

int find_parent(int num) {
    if (parent[num] == num) return num;
    return parent[num] = find_parent(parent[num]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    if (a != b) parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, ans = 0;
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        // cin >> a >> b >> c;
        cin >> pairs[i].second.first >> pairs[i].second.second >>
            pairs[i].first;
    }

    sort(pairs, pairs + E);

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < E; i++) {
        if (v.size() == V - 1) break;

        auto pair = pairs[i];

        int start = pair.second.first;
        int dest = pair.second.second;

        if (find_parent(start) == find_parent(dest)) continue;

        ans += pair.first;
        v.push_back(pair);
        union_parent(start, dest);
    }

    cout << ans;

    return 0;
}