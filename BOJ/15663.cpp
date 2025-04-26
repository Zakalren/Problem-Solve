#include <bits/stdc++.h>

using namespace std;

set<vector<int>> s;
int N, M, nums[8], visited[8];

void dfs(int index, vector<int> list) {
    list.push_back(nums[index]);

    if (list.size() == M) {
        s.insert(list);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;

        visited[i] = 1;
        dfs(i, list);
        visited[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    // sort(nums, nums + N);

    for (int i = 0; i < N; i++) {
        visited[i] = 1;
        dfs(i, vector<int>());
        visited[i] = 0;
    }

    for (auto list : s) {
        for (int i : list) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}