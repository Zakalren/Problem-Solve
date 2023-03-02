#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000001;

int A, K, depth[MAX], visit[MAX];
queue<int> q;

void bfs() {
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v + 1 < MAX && !visit[v + 1]) {
            visit[v + 1] = 1;
            depth[v + 1] = depth[v] + 1;
            q.push(v + 1);
        }

        if (v * 2 < MAX && !visit[v * 2]) {
            visit[v * 2] = 1;
            depth[v * 2] = depth[v] + 1;
            q.push(v * 2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> K;

    q.push(A);
    bfs();

    cout << depth[K];

    return 0;
}