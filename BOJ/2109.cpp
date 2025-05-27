#include <bits/stdc++.h>

using namespace std;

int parent[10001];

int find_parent(int node) {
    if (parent[node] == node) return node;

    return parent[node] = find_parent(parent[node]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    if (a == b) return;

    parent[a] = b;
}

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }

    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> v(N);

    int max_d = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
        max_d = max(max_d, v[i].second);
    }

    for (int i = 1; i <= max_d; i++) {
        parent[i] = i;
    }

    sort(v.begin(), v.end(), compare);  // 내림차순 정렬

    // 20 1
    // 2 1
    // 10 3
    // 100 2
    // 8 2
    // 5 20
    // 50 10

    // 100 2
    // 50 10
    // 20 1
    // 10 3
    // 8 2
    // 5 20
    // 2 1

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int p = v[i].first;
        int d = v[i].second;

        int available = find_parent(d);
        if (available) {
            union_parent(available, available - 1);
            ans += p;
        }
    }

    cout << ans;

    return 0;
}