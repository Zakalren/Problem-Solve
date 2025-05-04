#include <bits/stdc++.h>

using namespace std;

char graph[1000][1000];
int fire_times[1000][1000];
int visited[1000][1000];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C, ans = INT_MAX;
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            fire_times[i][j] = INT_MAX;
        }
    }

    pair<int, int> J;

    queue<pair<int, pair<int, int>>> fire_q;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == 'J')
                J = make_pair(i, j);

            else if (graph[i][j] == 'F')
                fire_q.push({0, {i, j}});
        }
    }

    while (!fire_q.empty()) {
        int depth = fire_q.front().first;
        int r = fire_q.front().second.first;
        int c = fire_q.front().second.second;
        fire_q.pop();

        if (fire_times[r][c] > depth) {
            fire_times[r][c] = depth;

            for (int i = 0; i < 4; i++) {
                int next_r = r + dx[i];
                int next_c = c + dy[i];

                if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C)
                    continue;

                if (graph[next_r][next_c] == '#') continue;

                fire_q.push({depth + 1, {next_r, next_c}});
            }
        }
    }

    queue<pair<int, pair<int, int>>> q;
    visited[J.first][J.second] = 1;
    q.push({0, J});

    while (!q.empty()) {
        int depth = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        if (depth >= fire_times[r][c]) continue;

        if (r == 0 || r == R - 1 || c == 0 || c == C - 1) {
            ans = min(ans, depth);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int next_r = r + dx[i];
            int next_c = c + dy[i];

            if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C)
                continue;

            if (graph[next_r][next_c] == '#') continue;

            if (depth + 1 >= fire_times[next_r][next_c]) continue;

            if (visited[next_r][next_c]) continue;

            visited[next_r][next_c] = 1;
            q.push({depth + 1, {next_r, next_c}});
        }
    }

    if (ans == INT_MAX)
        cout << "IMPOSSIBLE";
    else
        cout << ans + 1;

    return 0;
}