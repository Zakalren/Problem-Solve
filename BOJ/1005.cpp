#include <bits/stdc++.h>

using namespace std;

int times[1001];
int costs[1001];

bool visited[1001];

vector<vector<int>> v;

void dfs(int cur) {
    if (visited[cur]) return;
    visited[cur] = true;

    for (int ing : v[cur]) {
        if (visited[ing]) continue;

        dfs(ing);
    }

    int M_ing = 0;
    for (int ing : v[cur]) {
        M_ing = max(M_ing, costs[ing]);
    }
    costs[cur] = M_ing + times[cur];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        v.clear();

        int N, K;
        cin >> N >> K;

        v.resize(N + 1);

        for (int i = 1; i <= N; i++) {
            visited[i] = false;
            costs[i] = 0;
        }

        for (int i = 1; i <= N; i++) {
            cin >> times[i];
        }

        int a, b;
        for (int i = 0; i < K; i++) {
            cin >> a >> b;
            v[b].push_back(a);
        }

        int target;
        cin >> target;

        // 말단 노드들부터 쭉 올라가야할것 같은데 depth 파악을 어떻게 하지 ?
        // 후위 순회로 해야하나?

        dfs(target);
        cout << costs[target] << "\n";

        /*
        queue<pair<int, int>> q;
        q.push({target, times[target]});

        while (!q.empty()) {
            int dest = q.front().first;
            int cost = q.front().second;
            q.pop();

            if (visited[dest]) continue;
            visited[dest] = true;

            // 재료들 중 시간 젤 큰거 + 얘 건축시간
            int M_ing = *max_element(v[dest].begin(), v[dest].end());
            costs[dest] = cost + M_ing;
        }
        */
    }

    return 0;
}