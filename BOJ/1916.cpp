#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> v(N + 1);
    vector<int> costs(N + 1);

    for (int i = 1; i < costs.size(); i++) {
        costs[i] = INT_MAX;
    }

    for (int i = 1; i <= M; i++) {
        int dep, dest, cost;
        cin >> dep >> dest >> cost;
        v[dep].push_back(make_pair(cost, dest));
    }

    int dep, dest;
    cin >> dep >> dest;

    costs[dep] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, dep));

    while (!pq.empty()) {
        auto pair = pq.top();
        int cost = -pair.first;
        int pos = pair.second;
        pq.pop();

        if (cost > costs[pos]) continue;

        for (auto v1 : v[pos]) {
            int next_cost = cost + v1.first;
            int next_pos = v1.second;

            if (next_cost < costs[next_pos]) {
                costs[next_pos] = next_cost;
                pq.push(make_pair(-next_cost, next_pos));
            }
        }
    }

    cout << costs[dest];

    return 0;
}