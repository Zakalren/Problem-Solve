#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
int N, M, map[8][8], map_copy[8][8], ans;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int safe_area() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map_copy[i][j] == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}

void bfs() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map_copy[i][j] = map[i][j];
            if (map_copy[i][j] == 2) {
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (map_copy[nx][ny] == 0) {
                map_copy[nx][ny] = 2;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for (int x1 = 0; x1 < N; x1++) {
        for (int y1 = 0; y1 < M; y1++) {
            if (map[x1][y1] != 0) continue;

            for (int x2 = 0; x2 < N; x2++) {
                for (int y2 = 0; y2 < M; y2++) {
                    if (map[x2][y2] != 0) continue;

                    for (int x3 = 0; x3 < N; x3++) {
                        for (int y3 = 0; y3 < M; y3++) {
                            if (map[x3][y3] != 0) continue;

                            if (x1 == x2 && y1 == y2) continue;
                            if (x2 == x3 && y2 == y3) continue;
                            if (x1 == x3 && y1 == y3) continue;

                            map[x1][y1] = 1;
                            map[x2][y2] = 1;
                            map[x3][y3] = 1;
                            bfs();
                            ans = max(ans, safe_area());
                            map[x1][y1] = 0;
                            map[x2][y2] = 0;
                            map[x3][y3] = 0;
                        }
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}