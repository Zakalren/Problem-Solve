#include <bits/stdc++.h>

using namespace std;

int parent[500000];

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

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int printed = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (find_parent(a) != find_parent(b)) {
            union_parent(a, b);
        }

        else if (!printed) {
            cout << i + 1;
            printed = 1;
        }
    }

    if (!printed) cout << 0;

    return 0;
}