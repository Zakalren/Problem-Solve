#include <iostream>
#include <queue>

using namespace std;

int N, A, B, M, R[101][101], visit[101], depth[101];
queue<int> q;

void bfs(int v) {
    q.push(v);
    visit[v] = 1;

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if (R[v][i] == 1 && visit[i] != 1) {
                q.push(i);
                visit[i] = 1;
                depth[i] = depth[v] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> A >> B;
    cin >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        R[a][b] = 1;
        R[b][a] = 1;
    }
    
    bfs(A);

    if (depth[B] == 0) {
        cout << -1;
    }
    else {
        cout << depth[B];
    }

    return 0;
}