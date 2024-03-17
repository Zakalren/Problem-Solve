#include <bits/stdc++.h>

using namespace std;

int N;

bool found;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

char board[5][10];

queue<pair<int, int>> q;
queue<pair<int, int>> killq;

void fall() {
    for (int i = 0; i < N; i++) {
    for (int x = 0; x < 5; x++) {
        for (int y = 1; y < N; y++) {
            if (board[x][y] != '.' && board[x-1][y] == '.') {
                board[x-1][y] = board[x][y];
                board[x][y] = '.';
            }
        }
    }
    }
}

void solve(int x, int y) {
    bool pass = true;
    char value = board[x][y];

    for (int i = 0; i < 4; i++) {
        int mx = x + dx[i];
        int my = y + dy[i];

        if (mx >= 5 || my >= N || mx < 0 || my < 0) 
            continue;

        if (board[mx][my] != value) {
            pass = false;
            break;
        }
    }

    if (pass) {
        found = true;
        for (int i = 0; i < 4; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];

            if (mx >= 5 || my >= N || mx < 0 || my < 0) 
                continue;

            killq.push({ mx, my });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    string temp;
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < N; y++) {
            cin >> board[x][y];
        }
    }

    /*cout << "repeat\n";

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < N; y++) {
            cout << board[x][y];
        }
        cout << '\n';
    }

    cout << "start\n";*/

    do {
        found = false;
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < N; y++) {
                if (board[x][y] != '.') {
                    solve(x, y);
                }
            }
        }

        while (!killq.empty()) {
            int kx = killq.front().first;
            int ky = killq.front().second;
            killq.pop();

            board[kx][ky] = '.';
        }

        fall();
    }
    while (found);

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < N; y++) {
            cout << board[x][y];
        }
        cout << '\n';
    }

    return 0;
}