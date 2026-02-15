#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> ingredients(101);

bool is_middle[101];
int indegrees[101];
int counts[101];

int N, M;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M;

    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        ingredients[a].push_back({b, c});
        is_middle[a] = true;
        indegrees[b]++;
    }

    queue<int> q;
    q.push(N);
    counts[N] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto pair : ingredients[cur]) {
            counts[pair.first] += counts[cur] * pair.second;

            if (--indegrees[pair.first] == 0) {
                q.push(pair.first);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (counts[i] == 0) continue;
        if (is_middle[i]) continue;

        cout << i << " " << counts[i] << "\n";
    }

    return 0;
}
