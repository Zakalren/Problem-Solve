#include <bits/stdc++.h>

using namespace std;

int N, ans = 0;
int nums[8], arr[8];
bool visited[8];

void dfs(int depth) {
    if (depth == N) {
        int total = 0;
        for (int i = 0; i < N - 1; i++) {
            total += abs(arr[i] - arr[i + 1]);
        }
        ans = max(ans, total);
    }

    else {
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                arr[depth] = nums[i];
                dfs(depth + 1);
                visited[i] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    dfs(0);
    cout << ans;

    return 0;
}