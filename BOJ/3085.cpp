#include <bits/stdc++.h>

using namespace std;

int N, ans = 0;
char board[50][50];

void solve() {
    for (int i = 0; i < N; i++) {
        int row_count = 1;
        int col_count = 1;

        for (int j = 1; j < N; j++) {
            if (board[i][j] == board[i][j - 1])
                row_count++;
            else
                row_count = 1;

            ans = max(ans, row_count);

            if (board[j][i] == board[j - 1][i])
                col_count++;
            else
                col_count = 1;

            ans = max(ans, col_count);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + 1 < N) {
                swap(board[i][j], board[i + 1][j]);
                solve();
                swap(board[i][j], board[i + 1][j]);
            }

            if (j + 1 < N) {
                swap(board[i][j], board[i][j + 1]);
                solve();
                swap(board[i][j], board[i][j + 1]);
            }
        }
    }

    cout << ans;

    return 0;
}