#include <bits/stdc++.h>

using namespace std;

int parent[200001];

int find_parent(int node) {
    if (parent[node] == node) return node;

    return parent[node] = find_parent(parent[node]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    if (a != b) parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> v(N);

    int max_deadline = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i].second >> v[i].first;
        max_deadline = max(max_deadline, v[i].second);
    }

    for (int i = 1; i <= max_deadline; i++) {
        parent[i] = i;
    }

    sort(v.begin(), v.end(), greater<pair<int, int>>());  // 내림차순 정렬

    int ans = 0;
    for (auto& pair : v) {
        int deadline = pair.second;
        int reward = pair.first;

        int available = find_parent(deadline);
        if (available) {
            union_parent(available, available - 1);
            ans += reward;
        }
    }

    cout << ans;

    return 0;
}