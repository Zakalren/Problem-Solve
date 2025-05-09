#include <bits/stdc++.h>

#define offset 100001

using namespace std;

vector<int> v[200002];

int dist[200002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, M;
    cin >> N >> K >> M;

    int temp;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> temp;
            v[temp].push_back(i + offset);
            v[i + offset].push_back(temp);
        }
    }

    for (int i = 0; i < 200002; i++) {
        dist[i] = INT_MAX;
    }

    queue<int> q;
    q.push(1);
    dist[1] = 1;

    while (!q.empty()) {
        int pos = q.front();
        q.pop();

        for (int num : v[pos]) {
            int next_dist = dist[pos];
            if (num <= 100000) ++next_dist;

            if (dist[num] > next_dist) {
                dist[num] = next_dist;
                q.push(num);
            }
        }
    }

    if (dist[N] == INT_MAX)
        cout << -1;
    else
        cout << dist[N];

    return 0;
}