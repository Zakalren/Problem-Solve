#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int x, y;
};

int N, B[3][3], visit[3][3];
queue<Point> q;

void bfs() {
    while (!q.empty()) {
        Point v = q.front();
        int dist = B[v.x][v.y];
        q.pop();

        if (dist == -1)
            break;

        if (v.x + dist < N) {
            if (!visit[v.x + dist][v.y]) {
                q.push({ v.x + dist, v.y });
                visit[v.x + dist][v.y] = 1;
            }
        }

        if (v.y + dist < N) {
            if (!visit[v.x][v.y + dist]) {
                q.push({ v.x, v.y + dist });
                visit[v.x][v.y + dist] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> B[i][j];
        }
    }

    q.push({ 0, 0 });
    bfs();

    if (visit[N-1][N-1]) {
        cout << "HaruHaru";
    }
    else {
        cout << "Hing";
    }

    return 0;
}