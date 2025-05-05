#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
int sizes[100001];

void traverse(int node, int parent) {
    sizes[node] = 1;
    for (int n : v[node]) {
        if (n == parent) continue;

        traverse(n, node);
        sizes[node] += sizes[n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, R, Q;
    cin >> N >> R >> Q;

    v.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    traverse(R, 0);

    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        cout << sizes[q] << "\n";
    }

    return 0;
}