#include <iostream>

using namespace std;

int parent[100000];
int N, K, Q;

int getParent(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K >> Q;
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
    int a, b;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        a = getParent(a);
        b = getParent(b);
        parent[b] = a;
    }
    for (int i = 0; i < Q; i++) {
        cin >> a;
        cout << getParent(a) << '\n';
    }
}