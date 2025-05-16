#include <bits/stdc++.h>

using namespace std;

map<string, int> m;

int parent[200002];
int counts[200002];

int find_parent(int node) {
    if (parent[node] == node) return node;

    return parent[node] = find_parent(parent[node]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    if (a == b) return;

    parent[b] = a;
    counts[a] = counts[a] + counts[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        m.clear();

        int F;
        cin >> F;

        for (int i = 0; i < F * 2; i++) {
            parent[i] = i;
            counts[i] = 1;
        }

        int counter = 0;
        string f1, f2;
        for (int i = 0; i < F; i++) {
            cin >> f1 >> f2;

            if (m.find(f1) == m.end()) {
                m[f1] = counter++;
            }

            if (m.find(f2) == m.end()) {
                m[f2] = counter++;
            }

            int a = m[f1];
            int b = m[f2];

            union_parent(a, b);
            cout << counts[find_parent(a)] << "\n";
        }
    }

    return 0;
}