#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, res = -2100000000;
    cin >> N >> K;

    int nums[100001] = {0};

    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
        nums[i] += nums[i - 1];
    }

    for (int i = 1; i <= N - K + 1; i++) {
        res = max(res, nums[i + K - 1] - nums[i - 1]);
    }

    // 2 2
    // [0], 1 4

    cout << res;

    return 0;
}