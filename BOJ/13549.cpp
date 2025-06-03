#include <bits/stdc++.h>

using namespace std;

int N, K;

int dist[100001];

void solve() {
    queue<pair<int, int>> q;
    q.push({0, N});

    while (!q.empty()) {
        int depth = q.front().first;
        int num = q.front().second;
        q.pop();

        if (num < 0 || num > 100000) continue;

        if (depth > dist[num]) continue;

        if (num * 2 <= 100000 && depth < dist[num * 2]) {
            dist[num * 2] = depth;
            q.push({depth, num * 2});
        }

        if (num + 1 <= 100000 && depth + 1 < dist[num + 1]) {
            dist[num + 1] = depth + 1;
            q.push({depth + 1, num + 1});
        }

        if (num - 1 >= 0 && depth + 1 < dist[num - 1]) {
            dist[num - 1] = depth + 1;
            q.push({depth + 1, num - 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    fill(dist, dist + 100001, INT_MAX / 2);

    dist[N] = 0;
    solve();

    cout << dist[K];

    return 0;
}