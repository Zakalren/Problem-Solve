#include <bits/stdc++.h>

using namespace std;

int dist[1000][1000];
int graph[1000][1000];
int N, M;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main() {
    queue<pair<int, int>> q;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dist[i][j] = INT_MAX;

            cin >> graph[i][j];

            if (graph[i][j] == 2) {
                dist[i][j] = 0;
                q.push({i, j});
            }

            if (graph[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= N) continue;
            if (nc < 0 || nc >= M) continue;

            if (dist[nr][nc] != INT_MAX) continue;

            q.push({nr, nc});
            dist[nr][nc] = dist[r][c] + 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dist[i][j] == INT_MAX)
                cout << -1;
            else
                cout << dist[i][j];

            cout << " ";
        }
        cout << "\n";
    }

    return 0;
}