#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

const int MAX = 101;

queue<Point> q;
int N, maxDepth, cnt, map[MAX][MAX], visit[MAX][MAX];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void bfs(int depth) {
    while (!q.empty()) {
        Point v = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = v.x + dx[i];
            int ny = v.y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (map[nx][ny] > depth && !visit[nx][ny]) {
                    visit[nx][ny] = 1;
                    q.push({ nx, ny });
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            maxDepth = max(maxDepth, map[i][j]);
        }
    }

    for (int i = 0; i < maxDepth; i++) {
        int safe = 0;
        fill(visit[0], visit[0]+(MAX*MAX), 0);
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (map[j][k] > i && !visit[j][k]) {
                    visit[j][k] = 1;
                    q.push({ j, k });
                    bfs(i);
                    safe++;
                }
            }
        }

        cnt = max(cnt, safe);
    }

    cout << cnt;

    return 0;
}