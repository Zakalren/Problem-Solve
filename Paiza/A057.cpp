#include <bits/stdc++.h>

using namespace std;

int N, ans;
char MAP[10][10];

int dx[8] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int findLine(int x, int y, int direction, int length) {
    int mx = x + dx[direction];
    int my = y + dy[direction];

    if (mx < 0 || my < 0 || mx >= N || my >= N)
        return length;

    if (MAP[x][y]-'0'+1 != MAP[mx][my]-'0')
        return length;

    return findLine(mx, my, direction, length+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 8; k++) {
                ans = max(ans, findLine(i, j, k, 1));
            }
        }
    }

    cout << ans;

    return 0;
}