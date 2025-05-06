#include <bits/stdc++.h>

using namespace std;

int parent[200001];
pair<int, pair<int, int>> pairs[200000];

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

    while (1) {
        int m, n, sum = 0;
        cin >> m >> n;

        if (m == 0 && n == 0) break;

        for (int i = 0; i < m; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            cin >> pairs[i].second.first >> pairs[i].second.second >>
                pairs[i].first;
            sum += pairs[i].first;
        }

        sort(pairs, pairs + n);

        int ans = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (count == m - 1) break;

            int start = pairs[i].second.first;
            int end = pairs[i].second.second;
            int weight = pairs[i].first;

            if (find_parent(start) == find_parent(end)) continue;

            union_parent(start, end);
            ++count;
            ans += weight;
        }

        cout << (sum - ans) << "\n";
    }

    return 0;
}