#include <iostream>
#include <queue>

using namespace std;

int N, M, count, max_size;
int board[500][500];

bool visit[500][500];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1 && !visit[i][j]) {
                int size = 1;
                q.push({i, j});
                visit[i][j] = true;
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if (board[nx][ny] == 1 && !visit[nx][ny]) {
                            q.push({nx, ny});
                            visit[nx][ny] = true;
                            size++;
                        }
                    }
                }
                count++;
                max_size = max(max_size, size);
            }
        }
    }

    cout << count << '\n' << max_size;
}