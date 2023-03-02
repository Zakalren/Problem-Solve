#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> vec(1001);
queue<int> q;
int N, M, visit[1001], count;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (visit[i])
            continue;

        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int j = 0; j < vec[v].size(); j++) {
                if (!visit[vec[v][j]]) {
                    visit[vec[v][j]] = 1;
                    q.push(vec[v][j]);
                }
            }
        }

        count++;
    }

    cout << count;

    return 0;
}