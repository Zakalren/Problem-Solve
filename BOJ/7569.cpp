#include <iostream>
#include <queue>

using namespace std;

struct Tomato {
    int x, y, h;
};

int N, M, H, map[101][101][101], ripen, count;
queue<Tomato> q;

int dx[] = { -1,0,1,0,0,0 };
int dy[] = { 0,1,0,-1,0,0 };
int dh[] = { 0,0,0,0,1,-1 };

bool complete() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (map[i][j][k] == 0)
                    return false;
            }
        }
    }

    return true;
}

void bfs() {
    if (complete()) {
        cout << count;
        return;
    }
    count++;

    int before = ripen;
    int size = q.size();
    for (int i = 0; i < size; i++) {
        Tomato t = q.front();
        q.pop();

        for (int j = 0; j < 6; j++) {
            int nx = t.x + dx[j];
            int ny = t.y + dy[j];
            int nh = t.h + dh[j];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && nh >= 0 && nh < H) {
                if (map[nh][nx][ny] == 0) {
                    map[nh][nx][ny] = 1;
                    q.push({ nx, ny, nh });
                    ripen++;
                }
            }
        }
    }

    if (before == ripen) {
        cout << -1;
        return;
    }

    bfs();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> map[i][j][k];

                if (map[i][j][k] == 1) {
                    q.push({ j, k, i });
                    ripen++;
                }
            }
        }
    }

    bfs();

    return 0;
}