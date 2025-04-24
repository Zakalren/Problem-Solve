#include <bits/stdc++.h>

using namespace std;

int board[128][128];
int white = 0, blue = 0;

void searchBoard(int x_start, int x_end, int y_start, int y_end) {
    for (int i = x_start; i < x_end; i++) {
        for (int j = y_start; j < y_end; j++) {
            if (board[i][j] != board[x_start][y_start]) {
                int x_mid = (x_start + x_end) / 2;
                int y_mid = (y_start + y_end) / 2;

                //if (x_start == 4 && x_mid == 4 && x_end == 8)
                 //   continue;

                //cout << "i: " << i << ", j: " << j << '\n';
                //cout << "x_start: " << x_start << ", x_mid: " << x_mid << ", x_end: " << x_end << '\n';
                //cout << "y_start: " << y_start << ", y_mid: " << y_mid << ", y_end: " << y_end << '\n';

                searchBoard(x_start, x_mid, y_start, y_mid);
                searchBoard(x_mid, x_end, y_start, y_mid);
                searchBoard(x_start, x_mid, y_mid, y_end);
                searchBoard(x_mid, x_end, y_mid, y_end);

                return;
            }
        }
    }

    if (board[x_start][y_start] == 0)
        white++;
    else
        blue++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = -1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[j][i];
        }
    }

    int x_start = 0, x_end = N;
    int y_start = 0, y_end = N;

    searchBoard(x_start, x_end, y_start, y_end);

    cout << white << '\n' << blue;

    return 0;
}