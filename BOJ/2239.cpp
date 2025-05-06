#include <bits/stdc++.h>

using namespace std;

int board[9][9];
vector<pair<int, int>> blanks;
bool answered = false;

bool isvalid(int r, int c, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[r][i] == num) return false;
        if (board[i][c] == num) return false;
    }

    int sr = (r / 3) * 3;
    int sc = (c / 3) * 3;
    for (int i = sr; i < sr + 3; i++) {
        for (int j = sc; j < sc + 3; j++) {
            if (board[i][j] == num) return false;
        }
    }

    return true;
}

void visit(int index) {
    if (index == blanks.size() && !answered) {
        answered = true;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j];
            }
            cout << "\n";
        }
        return;
    }

    if (answered) return;

    auto [r, c] = blanks[index];

    for (int i = 1; i <= 9; i++) {
        if (!isvalid(r, c, i)) continue;

        board[r][c] = i;
        visit(index + 1);
        board[r][c] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char ch;
            cin >> ch;
            board[i][j] = ch - '0';

            if (!board[i][j]) blanks.push_back({i, j});
        }
    }

    visit(0);

    return 0;
}