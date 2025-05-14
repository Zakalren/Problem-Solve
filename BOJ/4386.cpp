#include <bits/stdc++.h>

using namespace std;

vector<pair<float, pair<int, int>>> edges;

pair<float, float> stars[100];
int parent[100];

int find_parent(int node) {
    if (parent[node] == node) return node;

    return parent[node] = find_parent(parent[node]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    parent[b] = parent[a];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> stars[i].first >> stars[i].second;
    }

    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            float dist = sqrt(pow(stars[i].first - stars[j].first, 2) +
                              pow(stars[i].second - stars[j].second, 2));

            edges.push_back({dist, {i, j}});
            // edges.push_back({dist, {j, i}});
        }
    }

    sort(edges.begin(), edges.end());

    float ans = 0;
    int count = 0;
    for (auto& edge : edges) {
        if (count == N - 1) break;

        auto star1 = edge.second.first;
        auto star2 = edge.second.second;
        float weight = edge.first;

        if (find_parent(star1) == find_parent(star2)) continue;

        union_parent(star1, star2);
        ans += weight;
        ++count;
    }

    cout << ans;

    return 0;
}