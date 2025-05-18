#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int R, C;

char graph[10000][500];
bool visited[10000][500];

int dr[3] = {-1, 0, 1};

bool dfs(int r, int c) {
    visited[r][c] = true;

    if (c == C - 1) {
        ans++;
        return true;
    }

    for (int i = 0; i < 3; i++) {
        int nr = r + dr[i];
        int nc = c + 1;

        if (nr < 0 || nr >= R) continue;

        if (visited[nr][nc]) continue;

        if (graph[nr][nc] == 'x') continue;

        if (dfs(nr, nc)) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        dfs(i, 0);
    }

    cout << ans;

    return 0;
}