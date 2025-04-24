#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int nums[100000] = {0};
    for (int i = 1; i <= N; i++) {
        cin >> nums[i];

        if (i > 0) nums[i] += nums[i - 1];
    }

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;

        // 5 9 12 14 15

        int res = nums[b] - nums[a - 1];
        cout << res << '\n';
    }

    return 0;
}