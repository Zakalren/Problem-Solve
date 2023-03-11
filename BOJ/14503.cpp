#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
int N, M, r, c, d, cnt, map[51][51];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void dfs() {
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (map[r][c] == 0) {
            map[r][c] = 2;
            cnt++;
        }

        bool flag = false;
        for (int i = 0; i < 4; i++) {
            d = (d + 3) % 4;
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (map[nr][nc] == 0) {
                q.push(make_pair(nr, nc));
                flag = true;
                break;
            }
        }

        if (!flag) {
            int nr = r - dr[d];
            int nc = c - dc[d];
            if (map[nr][nc] == 1) {
                cout << cnt;
                return;
            } else {
                q.push(make_pair(nr, nc));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> r >> c >> d;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    q.push(make_pair(r, c));
    dfs();

    return 0;
}