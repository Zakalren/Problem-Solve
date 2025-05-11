#include <bits/stdc++.h>

using namespace std;

int N, M, ans = 0;
int board[500][500];

bool visited[500][500];

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

pair<int, int> shapes[4][4] = {
    {{0, 0}, {0, 1}, {0, 2}, {-1, 1}},  // ㅗ
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},   // ㅜ
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},   // ㅏ
    {{0, 0}, {1, 0}, {2, 0}, {1, -1}}   // ㅓ
};

void check_shapes(int r, int c) {
    for (auto shape : shapes) {
        int total = 0;
        bool valid = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + shape[i].first;
            int nc = c + shape[i].second;

            if (nr < 0 || nr >= N) {
                valid = false;
                break;
            }

            if (nc < 0 || nc >= M) {
                valid = false;
                break;
            }

            total += board[nr][nc];
        }

        if (valid) ans = max(ans, total);
    }
}

void dfs(int r, int c, int depth, int total) {
    if (depth == 4) {
        ans = max(ans, total);
        return;
    }

    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= N) continue;
        if (nc < 0 || nc >= M) continue;

        if (visited[nr][nc]) continue;

        visited[nr][nc] = true;
        dfs(nr, nc, depth + 1, total + board[nr][nc]);
        visited[nr][nc] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            visited[i][j] = false;

            check_shapes(i, j);
        }
    }

    cout << ans;

    return 0;
}