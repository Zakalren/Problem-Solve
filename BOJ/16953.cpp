#include <bits/stdc++.h>

using namespace std;

int A, B, res = INT32_MAX;

void dfs(int depth, int num) {
    if (num < A) return;

    if (num == A) {
        res = min(depth, res);
        return;
    }

    if (num % 2 == 0) {
        dfs(depth + 1, num / 2);
    }

    if (num % 10 == 1) {
        dfs(depth + 1, (num - 1) / 10);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B;

    dfs(1, B);

    if (res == INT32_MAX) res = -1;
    cout << res;

    return 0;
}