#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1000001;

int F, S, G, U, D, visit[MAX], depth[MAX];
queue<int> q;

void bfs() {
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v+U >= 1 && v+U <= F && !visit[v+U]) {
            visit[v+U] = 1;
            depth[v+U] = depth[v] + 1;
            q.push(v+U);
        }

        if (v-D >= 1 && v-D <= F && !visit[v-D]) {
            visit[v-D] = 1;
            depth[v-D] = depth[v] + 1;
            q.push(v-D);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(depth, depth+MAX, -1);

    cin >> F >> S >> G >> U >> D;

    q.push(S);
    visit[S] = 1;
    depth[S] = 0;
    bfs();

    if (depth[G] == -1) {
        cout << "use the stairs";
    }
    else {
        cout << depth[G];
    } 

    return 0;
}