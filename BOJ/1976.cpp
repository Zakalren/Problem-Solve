#include <bits/stdc++.h>

using namespace std;

int matrix[201][201];

int parent[201];

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
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (matrix[i][j]) union_parent(i, j);
        }
    }

    int input[1000];
    for (int i = 0; i < M; i++) {
        cin >> input[i];
    }

    bool passed = true;
    for (int i = 0; i < M - 1; i++) {
        if (find_parent(input[i]) != find_parent(input[i + 1])) {
            passed = false;
            break;
        }
    }

    if (passed)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}