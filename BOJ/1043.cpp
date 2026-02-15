#include <bits/stdc++.h>

using namespace std;

int N, M, T, ans;
int parent[51];
vector<int> party[50];

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
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M >> T;

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < T; i++) {
        int num;
        cin >> num;
        union_parent(0, num);
    }

    for (int i = 0; i < M; i++) {
        int size;
        cin >> size;

        for (int j = 0; j < size; j++) {
            int num;
            cin >> num;
            party[i].push_back(num);
            union_parent(party[i][0], num);
        }
    }

    for (int i = 0; i < M; i++) {
        if (find_parent(party[i][0]) != find_parent(0)) ans++;
    }

    cout << ans << "\n";

    return 0;
}
