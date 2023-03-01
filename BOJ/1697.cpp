#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int a, b, depth[100001];
bool check[100001];

void bfs() {
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v*2 >= 0 && v*2 <= 100000 && !check[v*2]) {
            depth[v * 2] = depth[v] + 1;
            check[v * 2] = true;
            q.push(v * 2);
        }

        if (v+1 >= 0 && v+1 <= 100000 && !check[v+1]) {
            depth[v + 1] = depth[v] + 1;
            check[v + 1] = true;
            q.push(v + 1);
        }

        if (v-1 >= 0 && v-1 <= 100000 && !check[v-1]) {
            depth[v - 1] = depth[v] + 1;
            check[v - 1] = true;
            q.push(v - 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;

    q.push(a);
    check[a] = true;
    bfs();

    cout << depth[b];

    return 0;
}