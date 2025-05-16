#include <bits/stdc++.h>

using namespace std;

vector<pair<double, pair<int, int>>> v;

pair<int, int> pairs[1001];
int parent[1001];

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

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> pairs[i].first >> pairs[i].second;
        parent[i] = i;
    }

    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            double dist = sqrt(pow(pairs[i].first - pairs[j].first, 2) +
                               pow(pairs[i].second - pairs[j].second, 2));

            v.push_back({dist, {i, j}});
        }
    }

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;

        v.push_back({0.0, {a, b}});
    }

    sort(v.begin(), v.end());

    int count = 0;
    double ans = 0.0;
    for (int i = 0; i < v.size(); i++) {
        if (count == N - 1) break;

        double dist = v[i].first;
        int a = v[i].second.first;
        int b = v[i].second.second;

        if (find_parent(a) == find_parent(b)) continue;
        union_parent(a, b);
        count++;

        ans += dist;
    }

    cout << setprecision(2) << fixed << ans;

    return 0;
}