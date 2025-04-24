#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1);
    vector<int> parents(N + 1);
    parents[1] = 1;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (int node : graph[front]) {
            if (!parents[node]) {
                parents[node] = front;
                q.push(node);
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << parents[i] << '\n';
    }

    return 0;
}