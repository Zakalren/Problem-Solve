#include <bits/stdc++.h>

using namespace std;

int N;

int grid[100][100];
int visited[100][100];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void count_by_normal(int x, int y) {
    if (visited[x][y]) return;

    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

        if (visited[nx][ny]) continue;

        if (grid[nx][ny] != grid[x][y]) continue;

        count_by_normal(nx, ny);
    }
}

void count_by_colorblind(int x, int y) {
    if (visited[x][y]) return;

    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

        if (visited[nx][ny]) continue;

        if (grid[nx][ny] != grid[x][y] && (grid[x][y] + grid[nx][ny]) > 3)
            continue;

        count_by_colorblind(nx, ny);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;

    char ch;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ch;
            if (ch == 'R')
                grid[i][j] = 1;
            else if (ch == 'G')
                grid[i][j] = 2;
            else if (ch == 'B')
                grid[i][j] = 3;
        }
    }

    int normal_score = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                normal_score++;
                count_by_normal(i, j);
            }
        }
    }

    fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);

    int colorblind_score = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                colorblind_score++;
                count_by_colorblind(i, j);
            }
        }
    }

    cout << normal_score << " " << colorblind_score << "\n";

    return 0;
}