#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

int T, N;
queue<int> q;
vector<bool> visit;
vector<Point> depth;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        visit = vector<bool>(N + 2, false);
        depth = vector<Point>(N + 2, {0, 0});
        q = queue<int>();

        for (int j = 0; j < N + 2; j++) {
            cin >> depth[j].x >> depth[j].y;
        }

        q.push(0);
        visit[0] = true;

        bool find = false;
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            if (depth[v].x == depth[N + 1].x && depth[v].y == depth[N + 1].y) {
                find = true;
                break;
            }

            for (int j = 1; j < N + 2; j++) {
                if (!visit[j] && abs(depth[v].x - depth[j].x) +
                                         abs(depth[v].y - depth[j].y) <=
                                     1000) {
                    visit[j] = true;
                    q.push(j);
                }
            }
        }

        if (find) {
            cout << "happy\n";
        } else {
            cout << "sad\n";
        }
    }

    return 0;
}