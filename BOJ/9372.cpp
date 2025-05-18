#include <bits/stdc++.h>

using namespace std;

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

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        for (int i = 0; i <= N; i++) {
            parent[i] = i;
        }

        int a, b, ans = 0;
        for (int i = 0; i < M; i++) {
            cin >> a >> b;

            if (find_parent(a) == find_parent(b)) continue;

            union_parent(a, b);
            ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}