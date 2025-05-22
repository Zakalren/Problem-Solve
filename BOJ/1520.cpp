#include <bits/stdc++.h>

using namespace std;

int M, N;
int graph[500][500];

int dp[500][500];

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

int dfs(int r, int c) {
    if (r == M - 1 && c == N - 1) {
        return 1;
    }

    if (dp[r][c] != -1) {
        return dp[r][c];
    }

    dp[r][c] = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= M) continue;
        if (nc < 0 || nc >= N) continue;

        if (graph[r][c] <= graph[nr][nc]) continue;

        dp[r][c] += dfs(nr, nc);
    }

    return dp[r][c];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    dfs(0, 0);
    cout << dp[0][0];

    return 0;
}