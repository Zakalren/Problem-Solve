#include <bits/stdc++.h>

using namespace std;

int parent[1000];
//set< pair<int, pair<int, int>> > s;
vector<pair<int, pair<int, int>>> v;

int find_parent(int node) {
    if (parent[node] == node) {
        return node;
    }

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

    int N;
    cin >> N;

    //v.resize(N * N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int weight;
            cin >> weight;

            if (j > i) {
                v.push_back({ weight, {i, j }});
            }
        }
    }

    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    /*
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int weight = matrix[i][j];
            v.push_back({ weight, { i, j } });
        }
    }

    for (int i = 0; i < v.size(); i++) {
        parent[i] = i;
    }
    */

    sort(v.begin(), v.end());

    long long ans = 0;
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (count == N - 1) break;

        auto pair = v[i];

        int start = pair.second.first;
        int end = pair.second.second;
        int weight = pair.first;

        if (find_parent(start) == find_parent(end)) continue;

        union_parent(start, end);
        ++count;
        ans += weight;
    }

    cout << ans;

    return 0;
}