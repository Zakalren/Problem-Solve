#include <bits/stdc++.h>

using namespace std;

int N, M;
int visited[10001] = {0};

vector<int> nums;
vector<int> sequence;

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << sequence[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            sequence[depth] = nums[i];
            dfs(depth + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;

    nums.resize(N);
    sequence.resize(M);

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    dfs(0);

    return 0;
}
