#include <bits/stdc++.h>

using namespace std;

int parent[100001];

int find_parent(int node) {
    if (parent[node] == node) return node;

    return parent[node] = find_parent(parent[node]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    int G, P;
    cin >> G >> P;

    for (int i = 1; i <= G; i++) {
        parent[i] = i;
    }

    bool end = false;
    int num;
    for (int i = 0; i < P; i++) {
        cin >> num;

        num = find_parent(num);

        if (num == 0 || end) {
            end = true;
            continue;
        }

        ans++;
        union_parent(num, num - 1);
    }

    cout << ans;

    return 0;
}