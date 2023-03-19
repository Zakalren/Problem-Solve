#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Move {
    int rx, ry, bx, by, cnt;
};

int N, M, ans = -1;
char map[10][10];
queue<Move> q;
pair<int, int> red, blue;

bool visit[10][10][10][10];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void bfs() {
    while (!q.empty()) {
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int cnt = q.front().cnt;
        q.pop();

        if (cnt > 10) {
            // cout << -1;
            break;
        }

        if (map[rx][ry] == 'O') {
            // cout << cnt;
            ans = cnt;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int crx = rx, cry = ry, cbx = bx, cby = by;

            while (1) {
                crx += dx[i];
                cry += dy[i];

                if (map[crx][cry] == '#') {
                    crx -= dx[i];
                    cry -= dy[i];
                    break;
                }

                if (map[crx][cry] == 'O') {
                    break;
                }
            }

            while (1) {
                cbx += dx[i];
                cby += dy[i];

                if (map[cbx][cby] == '#') {
                    cbx -= dx[i];
                    cby -= dy[i];
                    break;
                }

                if (map[cbx][cby] == 'O') {
                    break;
                }
            }

            if (map[cbx][cby] == 'O') {
                continue;
            }

            if (crx == cbx && cry == cby) {
                int rdist = abs(crx - rx) + abs(cry - ry);
                int bdist = abs(cbx - bx) + abs(cby - by);

                if (rdist > bdist) {
                    crx -= dx[i];
                    cry -= dy[i];
                } else {
                    cbx -= dx[i];
                    cby -= dy[i];
                }
            }

            if (!visit[crx][cry][cbx][cby]) {
                q.push({crx, cry, cbx, cby, cnt + 1});
                visit[crx][cry][cbx][cby] = true;
            }
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'R') {
                red = {i, j};
            } else if (map[i][j] == 'B') {
                blue = {i, j};
            }
        }
    }

    q.push({red.first, red.second, blue.first, blue.second, 0});
    visit[red.first][red.second][blue.first][blue.second] = true;
    bfs();

    return 0;
}