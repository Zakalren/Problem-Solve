#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

queue<Point> q;
vector<Point> icePoints;

int N, M, island, result, map[301][301], minusMap[301][301], visit[301][301];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void bfs() {
    while (!q.empty()) {
        Point v = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = v.x + dx[k];
            int ny = v.y + dy[k];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (map[nx][ny] > 0 && !visit[nx][ny]) {
                    visit[nx][ny] = 1;
                    q.push({ nx, ny });
                }
                else if (map[nx][ny] == 0) {
                    minusMap[v.x][v.y]++;
                }
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
            if (map[i][j] > 0) {
                icePoints.push_back({ i, j });
            }
        }
    }

    while (!icePoints.empty()) {
        island = 0;
        fill(visit[0], visit[0]+(301*301), 0);
        fill(minusMap[0], minusMap[0]+(301*301), 0);

        for (const auto & p : icePoints) {
            if (!visit[p.x][p.y]) {
                visit[p.x][p.y] = 1;
                q.push({ p.x, p.y });
                bfs();
                island++;
            }
        }

        if (island >= 2) {
            cout << result;
            break;
        }

        result++;
        vector<Point> temp;
        for (const auto p : icePoints) {
            map[p.x][p.y] = max(0, map[p.x][p.y] - minusMap[p.x][p.y]);

            if (map[p.x][p.y] > 0) {
                temp.push_back(p);
            }
        }
        icePoints = temp;

        if (icePoints.size() == 0) {
            cout << 0;
            break;
        }
    }
    
    return 0;
}