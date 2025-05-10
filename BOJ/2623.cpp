#include <bits/stdc++.h>

using namespace std;

int N, M;
int indegree[1001];

vector<vector<int>> v;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    v.resize(N + 1);

    // 1 4 3
    // 6 2 5 4
    // 2 3

    // 1 4 3 -> 1 4 3 6 2 5 4

    int len, nums[1001];
    for (int i = 0; i < M; i++) {
        cin >> len;

        for (int j = 0; j < len; j++) {
            cin >> nums[j];
        }

        for (int j = 0; j < len - 1; j++) {
            ++indegree[nums[j + 1]];
            v[nums[j]].push_back(nums[j + 1]);
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        ans.push_back(num);
        for (int next : v[num]) {
            if (--indegree[next] == 0) q.push(next);
        }
    }

    if (ans.size() != N) {
        cout << 0;
        return 0;
    }

    for (int n : ans) {
        cout << n << "\n";
    }

    return 0;
}