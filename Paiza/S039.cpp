#include <bits/stdc++.h>

using namespace std;

int H, W, ans;
char MAP[500][500];

int maxHeight(int x, int y, int limit) {
    for (int i = y; i < H; i++) {
        if (i >= limit)
            return limit;
        
        if (MAP[x][i] == '#')
            return i;
    }

    return 0;
}

int findMaxHeight(int x, int y, int length, int height, int limit) {
    if (x < 0 || y < 0 || x >= W || y >= H)
        return 0;

    maxHeight(x, y, limit);

    for (int i = y; i < H; i++) {
        if (i >= limit)
            continue;

        if (MAP[x][i] == '#') {
            cout << "blocked " << x << "," << i << ". length: " << length << ", height: " << height << '\n'; 
            return length * height;
        }
        else {
            height++;
            limit = min(limit, i+1);
        }
    }

    return findMaxHeight(x+1, y, length+1, 1, limit);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> H >> W;

    for (int i = H -1; i >= 0; i--) {
        for (int j = 0; j < W; j++) {
            cin >> MAP[j][i];
        }
    }

    cout << "0, 0: " << MAP[0][0] << '\n';
    cout << "1, 0: " << MAP[1][0] << '\n';
    cout << "2, 0: " << MAP[2][0] << '\n';
    cout << "3, 0: " << MAP[3][0] << '\n';
    cout << "4, 0: " << MAP[4][0] << '\n';
    cout << "5, 0: " << MAP[5][0] << '\n';

    cout << "0, 1: " << MAP[0][1] << '\n';
    cout << "1, 1: " << MAP[1][1] << '\n';
    cout << "2, 1: " << MAP[2][1] << '\n';
    cout << "3, 1: " << MAP[3][1] << '\n';
    cout << "4, 1: " << MAP[4][1] << '\n';
    cout << "5, 1: " << MAP[5][1] << '\n';

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (MAP[i][j] == '.') {
                for (int k = i; k < W; k++) {
                    findMaxHeight(i, j, k-1, 1,)
                }
            }
        }
    }

    cout << ans;

    return 0;
}