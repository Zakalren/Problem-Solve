#include <bits/stdc++.h>

using namespace std;

int parent[1000001];

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

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;

        if (a) {
            if (find_parent(b) == find_parent(c)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            union_parent(b, c);
        }
    }

    return 0;
}